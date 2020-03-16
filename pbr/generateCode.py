#!/usr/bin/env python

"""
Code generation for C++ classes.
"""

import os
import functools
import subprocess
import shlex
import collections

from jinja2 import Template


# Name of the project directory.
PROJECT_DIR = "pbr"

# Name of the codeGenTemplates directory.
TEMPLATE_DIR = "template"

# Name of the subdirectory where all types reside.
TYPE_DIR = "type"

# Name of the subdirectory where all function reside.
FUNCTION_DIR = "function"

# Prefix for the class names of types.
TYPES_CLASS_PREFIX = ""

# Kinds of arithmetic operators.
ARITHMETIC_OPERATORS = ['+', '-', '*', '/']

# POD types we are interested in generating code for.  Double is omitted for the time being.
FLOAT = "float"
INT = "int"

# COMPOSITE_TYPES is a dict of key (composite type name) -> value (composite type object)
# It is populated in GenCompositeTypes.
COMPOSITE_TYPES = {}

#
# Utilities
#

def RunCommand(command):
    """
    Run a command in the shell by forking a subprocess.
    """
    print("Running command {}".format(command))
    process = subprocess.Popen(shlex.split(command))
    process.wait()


def WriteFile(filePath, content):
    """
    Write a file to disk.

    Args:
        filePath (str): path to write to.
        content (str): content to write.
    """
    print("Generated {!r}".format(filePath))
    with open(filePath, 'w') as f:
        f.write(content)


def FormatCode(fileNames):
    """
    Run clang-format over input files, formatting in-place.

    Args:
        fileNames (list): input files to automatically format.
    """
    command = "clang-format -i " + " ".join(fileNames)
    RunCommand(command)


def GetCodeGenTemplate(templateName):
    """
    Args:
        templateName (str): name of the template file.

    Returns:
        str: full path to the codegen template.
    """
    return os.path.abspath(os.path.join(TEMPLATE_DIR, templateName))


def GenerateCode(context, templatePath):
    """
    Generate a single source file with a template and code-gen context.

    Args:
        context (obj): context object with attributes which are consumed in the template rendering.
        templatePath (str): path to the template file to perform substitution.

    Returns:
        str: file name of generated source file.
    """
    with open(templatePath, 'r') as f:
        templateStr = f.read()
        template = Template(templateStr)
        code = template.render(context=context)
        return code


class AggregateIncludesCpp:
    """
    Code generation for aggregating includes in a single CPP.
    """

    def __init__(self, includePaths):
        self.includePaths = includePaths


#
# Types
#

class DataType:
    """
    Abstract base class for all data types.
    """

    @property
    def className(self):
        raise NotImplementedError()

    @property
    def headerFileName(self):
        raise NotImplementedError()

    @property
    def isScalar(self):
        return False

    @property
    def isVector(self):
        return False

    @property
    def isArray(self):
        return False

    @property
    def isComposite(self):
        return False


class PODType(DataType):
    """
    POD (Plain old data) type, used in code-gen contexts.
    """

    def __init__(self, typeName):
        assert(isinstance(typeName, str))
        self._typeName = typeName

    @property
    def className(self):
        """
        Returns:
            str: the ctype of this type.
        """
        return self._typeName

    @property
    def isScalar(self):
        return True


POD_TYPES = [
    PODType(FLOAT),
    PODType(INT)
]



class VectorType(DataType):
    """
    Code generation for an C++ vector type.
    """

    def __init__(self, dims, elementType):
        assert(isinstance(dims, tuple))
        assert(isinstance(elementType, PODType))
        self.dims = dims
        self.elementType = elementType

    @property
    def elementSize(self):
        return functools.reduce(lambda x, y: x * y, self.dims)

    @property
    def className(self):
        if len(self.dims) == 2:
            prefix = TYPES_CLASS_PREFIX + "Mat"
        else:
            prefix = TYPES_CLASS_PREFIX + "Vec"

        return "{prefix}{dims}{elementType}".format(
            prefix=prefix,
            dims=str(self.dims[0]),
            elementType=self.elementType.className[0]
        )

    @property
    def headerFileName(self):
        if len(self.dims) == 2:
            prefix = "mat"
        else:
            prefix = "vec"

        return "{prefix}{dims}{elementType}.h".format(
            prefix=prefix,
            dims=str(self.dims[0]),
            elementType=self.elementType.className[0]
        )

    @property
    def isVector(self):
        return True


class ArrayType(DataType):
    """
    Code generation for an C++ array type.
    """

    def __init__(self, elementType):
        assert(isinstance(elementType, DataType))
        self.elementType = elementType

    @property
    def className(self):
        if self.elementType.className.startswith(TYPES_CLASS_PREFIX):
            prefix = ""
        else:
            prefix = TYPES_CLASS_PREFIX

        return "{prefix}{elementTypeName}Array".format(
            prefix=prefix,
            elementTypeName=(self.elementType.className[0].upper() + self.elementType.className[1:])
        )

    @property
    def headerFileName(self):
        if self.elementType.isVector:
            return "{elementHeaderFileName}Array.h".format(
                elementHeaderFileName=os.path.splitext(self.elementType.headerFileName)[0]
            )
        else:
            return "{elementTypeName}Array.h".format(
                elementTypeName=self.elementType.className[0].lower() + self.elementType.className[1:]
            )

    @property
    def isArray(self):
        return True


"""
CompositeElement is a single element of an CompositeType, described by a name, type, and default value.

Args:
    name (str): is used to uniquely address this element from the parent Composite type.
    type (object): the data type.
    defaultValue (str): string, encoding C++ code that will be assigned to element member variable.
"""
CompositeElement = collections.namedtuple("CompositeElement", ["name", "type", "defaultValue"])


class CompositeType(DataType):
    """
    Code generation for an C++ composite data type.
    A composite type is a structure composed of one or more elements.
    Each element can be of type pod, vector, array, or another composite.

    Args:
        name (str): name of the composite type.
        elements (list): list of CompositeElement(s).
        extraIncludes (list): list of extras includes to encode near the top of the source file.
    """

    def __init__(self, name, elements, extraIncludes=None):
        for element in elements:
            assert(isinstance(element.type, DataType))
        self._name = name
        self.elements = elements
        self.elementSize = len(self.elements)
        self.extraIncludes = extraIncludes or []

    @property
    def className(self):
        return self._name[:1].upper() + self._name[1:]

    @property
    def headerFileName(self):
        return "{name}.h".format(
            name=self._name[:1].lower() + self._name[1:]
        )

    @property
    def isComposite(self):
        return True


def GenCompositeType(compositeType):
    """
    Generate a single C++ composite type source file.

    Args:
        compositeType (CompositeType): composite data type to generate definition source code for.

    Returns:
        str: file path to the generated source file.
    """
    filePath = os.path.join(os.path.abspath(TYPE_DIR), compositeType.headerFileName)
    code = GenerateCode(
        compositeType,
        GetCodeGenTemplate(os.path.join(TYPE_DIR, "compositeType.h"))
    )
    WriteFile(filePath, code)
    return filePath


def GenBoundsCompositeTypes():
    """
    Generate Bounds composite type source file.

    Returns:
        list: paths to generated source files.
    """
    filePaths = []

    for vectorType in [
        VectorType((2,), PODType(FLOAT)),
        VectorType((3,), PODType(FLOAT)),
        VectorType((2,), PODType(INT)),
        VectorType((3,), PODType(INT))
    ]:
        compositeTypeName = "bounds{dims}{elementType}".format(
            dims=str(vectorType.dims[0]),
            elementType=vectorType.elementType.className[0]
        )

        # Min default value.
        minDefaultValue = "{vectorClassName}(".format(
            vectorClassName=vectorType.className
        )
        for index in range(vectorType.dims[0]):
            minDefaultValue += "std::numeric_limits< {vectorElementType} >::max()".format(
                vectorElementType=vectorType.elementType.className
            )
            if index + 1 < vectorType.dims[0]:
                minDefaultValue += ","
        minDefaultValue += ")"

        # Max default value.
        maxDefaultValue = "{vectorClassName}(".format(
            vectorClassName=vectorType.className
        )
        for index in range(vectorType.dims[0]):
            maxDefaultValue += "std::numeric_limits< {vectorElementType} >::min()".format(
                vectorElementType=vectorType.elementType.className
            )
            if index + 1 < vectorType.dims[0]:
                maxDefaultValue += ","
        maxDefaultValue += ")"

        compositeType = CompositeType(
            compositeTypeName,
            [
                CompositeElement(name="min", type=vectorType, defaultValue=minDefaultValue),
                CompositeElement(name="max", type=vectorType, defaultValue=maxDefaultValue),
            ],
            extraIncludes=[
                "<limits>",
            ]
        )

        # Cache composite type into global COMPOSITE_TYPES, to be queried in function generation in a later stage.
        COMPOSITE_TYPES[compositeType.className] = compositeType

        filePaths.append(GenCompositeType(compositeType))

    return filePaths


def GenCompositeTypes():
    """
    Generate all composite type source files.

    Returns:
        list: paths to generated source files.
    """
    filePaths = []
    filePaths += GenBoundsCompositeTypes()
    return filePaths


def GenArrayTypes():
    """
    Generate all array type source files.

    Returns:
        list: paths to generated source files.
    """
    # Build ArrayType(s)
    arrayTypes = []
    for podType in POD_TYPES:
        arrayType = ArrayType(podType)
        arrayTypes.append(arrayType)

    for vectorType in VECTOR_TYPES:
        arrayType = ArrayType(vectorType)
        arrayTypes.append(arrayType)

    # Generate code for ArrayType(s)
    filePaths = []
    for arrayType in arrayTypes:
        filePath = os.path.join(os.path.abspath(TYPE_DIR), arrayType.headerFileName)
        code = GenerateCode(arrayType, GetCodeGenTemplate(os.path.join(TYPE_DIR, 'arrayType.h')))
        WriteFile(filePath, code)
        filePaths.append(filePath)

    return filePaths


VECTOR_TYPES = [
    # Single-index vector types.
    VectorType((2,), PODType(INT)),
    VectorType((3,), PODType(INT)),
    VectorType((4,), PODType(INT)),
    VectorType((2,), PODType(FLOAT)),
    VectorType((3,), PODType(FLOAT)),
    VectorType((4,), PODType(FLOAT)),

    # Matrix types.
    VectorType((3,3), PODType(FLOAT)),
    VectorType((4,4), PODType(FLOAT)),
]


def GenVectorTypes():
    """
    Generate all vector type source files.

    Returns:
        list: paths to generated source files.
    """
    # Generate vector class headers.
    filePaths = []
    headerFileNames = []
    for vectorType in VECTOR_TYPES:
        code = GenerateCode(vectorType, GetCodeGenTemplate(os.path.join(TYPE_DIR, "vectorType.h")))
        filePath = os.path.join(os.path.abspath(TYPE_DIR), vectorType.headerFileName)
        WriteFile(filePath, code)
        filePaths.append(filePath)
        headerFileNames.append(vectorType.headerFileName)

    return filePaths


def GenTypes():
    """
    Top-level entry point for generating all data type source files.
    Vectors and matrices types will be generated.
    Array types of pod, vectors, and matrices will also be generated.

    Returns:
        list: paths to of generated source files.
    """
    filePaths = GenVectorTypes()
    filePaths += GenArrayTypes()
    filePaths += GenCompositeTypes()

    # Generate aggregation cpp source.
    includePaths = [os.path.join(PROJECT_DIR, TYPE_DIR, os.path.split(filePath)[1]) for filePath in filePaths]
    aggregateCode = GenerateCode(
        AggregateIncludesCpp(includePaths),
        GetCodeGenTemplate('aggregateIncludes.cpp')
    )
    aggregateCppPath = os.path.join(os.path.abspath(TYPE_DIR), "allTypes.cpp")
    WriteFile(aggregateCppPath, aggregateCode)
    filePaths.append(aggregateCppPath)

    return filePaths

#
# Functions
#

def GenFunction(functionFileName, **kwargs):
    """
    Generate code for a function.

    Args:
        functionFileName (str): name of the template file.  This name will also be used to write the generated code.

    Returns:
        str: file path to the generated code.
    """
    function = Function()
    for key, value in kwargs.items():
        setattr(function, key, value)

    filePath = os.path.join(os.path.abspath(FUNCTION_DIR), functionFileName)
    code = GenerateCode(
        function,
        GetCodeGenTemplate(os.path.join(FUNCTION_DIR, functionFileName))
    )
    WriteFile(filePath, code)

    return filePath


class Function:
    """
    A simple code-gen context object for a function.  Not much to see here.
    """

    def __init__(self):
        pass


class FunctionGroup:
    """
    Group of functions which share the same code-gen context.
    """

    def __init__(self, files, **kwargs):
        self.files = files
        self.kwargs = kwargs


def GenFunctions():
    """
    Generate code for templatized function.

    Returns:
        list: file paths to the generated files.
    """
    functionGroups = [
        FunctionGroup([
            "crossProduct.h",
            "coordinateSystem.h",
            "rayPosition.h",
        ],
        vectorTypes=[
            VectorType((3,), PODType(FLOAT)),
        ]),
        FunctionGroup([
            "dotProduct.h",
            "length.h",
            "lengthSquared.h",
            "distance.h",
            "distanceSquared.h",
            "normalise.h",
            "faceForward.h",
        ],
        vectorTypes=[
            VectorType((2,), PODType(FLOAT)),
            VectorType((3,), PODType(FLOAT)),
            VectorType((4,), PODType(FLOAT)),
        ]),
        FunctionGroup([
            "lerp.h",
        ],
        types=[
            PODType(FLOAT),
            VectorType((2,), PODType(FLOAT)),
            VectorType((3,), PODType(FLOAT)),
            VectorType((4,), PODType(FLOAT)),
        ]),
        FunctionGroup([
            "min.h",
            "max.h",
            "floor.h",
            "ceil.h",
            "abs.h",
        ],
        types=[
            PODType(INT),
            PODType(FLOAT),
            VectorType((2,), PODType(FLOAT)),
            VectorType((3,), PODType(FLOAT)),
            VectorType((4,), PODType(FLOAT)),
            VectorType((2,), PODType(INT)),
            VectorType((3,), PODType(INT)),
            VectorType((4,), PODType(INT)),
        ]),
        FunctionGroup([
            "boundsUnion.h",
            "boundsIntersection.h",
            "boundsOverlap.h",
        ],
        types=[
            COMPOSITE_TYPES["Bounds2i"],
            COMPOSITE_TYPES["Bounds2f"],
            COMPOSITE_TYPES["Bounds3i"],
            COMPOSITE_TYPES["Bounds3f"],
        ]),
    ]

    filePaths = []

    for functionGroup in functionGroups:
        for f in functionGroup.files:
            filePath = GenFunction(f, **functionGroup.kwargs)
            filePaths.append(filePath)

    # Generate aggregation cpp source.
    includePaths = [os.path.join(PROJECT_DIR, FUNCTION_DIR, os.path.split(filePath)[1]) for filePath in filePaths]
    aggregateCode = GenerateCode(
        AggregateIncludesCpp(includePaths),
        GetCodeGenTemplate('aggregateIncludes.cpp')
    )
    aggregateCppPath = os.path.join(os.path.abspath(FUNCTION_DIR), "allFunctions.cpp")
    WriteFile(aggregateCppPath, aggregateCode)
    filePaths.append(aggregateCppPath)

    return filePaths


if __name__ == "__main__":
    filePaths = GenTypes()
    filePaths += GenFunctions()
    FormatCode(filePaths)


