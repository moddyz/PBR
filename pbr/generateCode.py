#!/usr/bin/env python

"""
Code generation for C++ classes.
"""

import os
import functools
import subprocess
import shlex

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

# Scalar types we are interested in generating code for.  Double is omitted for the time being.
FLOAT = "float"
INT = "int"

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
    Generate a single vector type as a header source.

    Args:
        context (obj): context object with attributes which are consumed in the template rendering.
        templatePath (str): path to the template file to perform substitution.

    Returns:
        str: file name of generated vector class.
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
    Abstract base class.
    """

    @property
    def className(self):
        raise NotImplementedError()

    @property
    def isScalar(self):
        raise NotImplementedError()

    @property
    def isVector(self):
        raise NotImplementedError()


class ScalarType(DataType):

    def __init__(self, typeName):
        self._typeName = typeName

    @property
    def className(self):
        """
        Returns:
            str: the c name of this type.
        """
        return self._typeName

    @property
    def isScalar(self):
        return True

    @property
    def isVector(self):
        return False


class VectorType(DataType):
    """
    Code generation for an C++ vector type.
    """

    def __init__(self, dims, elementType):
        assert(isinstance(dims, tuple))
        assert(isinstance(elementType, str))
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
            elementType=self.elementType[0]
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
            elementType=self.elementType[0]
        )

    @property
    def isScalar(self):
        return False

    @property
    def isVector(self):
        return True


class ArrayType:
    """
    Code generation for an C++ array type.
    """

    def __init__(self, elementType):
        self.elementType = elementType

        # Class name.
        if self.elementType.className.startswith(TYPES_CLASS_PREFIX):
            prefix = ""
        else:
            prefix = TYPES_CLASS_PREFIX

        self.className = "{prefix}{elementTypeName}Array".format(
            prefix=prefix,
            elementTypeName=(self.elementType.className[0].upper() + self.elementType.className[1:])
        )

        # header file name.
        if self.elementType.isVector:
            self.headerFileName = "{elementHeaderFileName}Array.h".format(
                elementHeaderFileName=os.path.splitext(self.elementType.headerFileName)[0]
            )
        else:
            self.headerFileName = "{elementTypeName}Array.h".format(
                elementTypeName=self.elementType.className[0].lower() + self.elementType.className[1:]
            )


SCALAR_TYPES = [
    ScalarType(FLOAT),
    ScalarType(INT)
]


def GenArrayTypes():
    """
    Generate all array type source files.

    Returns:
        list: paths to generated source files.
    """
    # Build ArrayType(s)
    arrayTypes = []
    for scalarType in SCALAR_TYPES:
        arrayType = ArrayType(scalarType)
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
    VectorType((2,), INT),
    VectorType((3,), INT),
    VectorType((4,), INT),
    VectorType((2,), FLOAT),
    VectorType((3,), FLOAT),
    VectorType((4,), FLOAT),

    # Matrix types.
    VectorType((3,3), FLOAT),
    VectorType((4,4), FLOAT),
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
        code = GenerateCode(vectorType, GetCodeGenTemplate(os.path.join(TYPE_DIR, 'vectorType.h')))
        filePath = os.path.join(os.path.abspath(TYPE_DIR), vectorType.headerFileName)
        WriteFile(filePath, code)
        filePaths.append(filePath)
        headerFileNames.append(vectorType.headerFileName)

    # Generate aggregation cpp source.
    includePaths = [os.path.join(PROJECT_DIR, TYPE_DIR, fileName) for fileName in headerFileNames]
    aggregateCode = GenerateCode(
        AggregateIncludesCpp(includePaths),
        GetCodeGenTemplate('aggregateIncludes.cpp')
    )
    aggregateCppPath = os.path.join(os.path.abspath(TYPE_DIR), "vectorTypes.cpp")
    WriteFile(aggregateCppPath, aggregateCode)
    filePaths.append(aggregateCppPath)

    return filePaths


def GenTypes():
    """
    Top-level entry point for generating all data type source files.
    Vectors and matrices types will be generated.
    Array types of scalar, vectors, and matrices will also be generated.

    Returns:
        list: paths to of generated source files.
    """
    filePaths = GenVectorTypes()
    filePaths += GenArrayTypes()
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


FUNCTION_GROUPS = [
    FunctionGroup([
        "crossProduct.h",
        "coordinateSystem.h",
        "rayPosition.h",
    ],
    vectorTypes=[
        VectorType((3,), FLOAT),
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
        VectorType((2,), FLOAT),
        VectorType((3,), FLOAT),
        VectorType((4,), FLOAT),
    ]),
    FunctionGroup([
        "lerp.h",
    ],
    types=[
        ScalarType(FLOAT),
        VectorType((2,), FLOAT),
        VectorType((3,), FLOAT),
        VectorType((4,), FLOAT),
    ]),
    FunctionGroup([
        "min.h",
        "max.h",
        "floor.h",
        "ceil.h",
        "abs.h",
    ],
    types=[
        ScalarType(INT),
        ScalarType(FLOAT),
        VectorType((2,), FLOAT),
        VectorType((3,), FLOAT),
        VectorType((4,), FLOAT),
        VectorType((2,), INT),
        VectorType((3,), INT),
        VectorType((4,), INT),
    ]),
]


def GenFunctions():
    """
    Generate code for templatized function.

    Returns:
        list: file paths to the generated files.
    """
    filePaths = []

    for functionGroup in FUNCTION_GROUPS:
        for f in functionGroup.files:
            filePath = GenFunction(f, **functionGroup.kwargs)
            filePaths.append(filePath)

    return filePaths


if __name__ == "__main__":
    filePaths = GenTypes()
    filePaths += GenFunctions()
    FormatCode(filePaths)


