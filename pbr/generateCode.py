#!/usr/bin/env python

"""
Code generation for C++ classes.
"""

import os
import functools
import subprocess
import shlex

from jinja2 import Template


# Namespace of all the symbols.
PROJECT = "pbr"

# Name of the subdirectory that all data types should reside.
CODEGENTEMPLATES_DIR = "codeGenTemplates"

# Name of the subdirectory that all data types should reside.
TYPES_DIR = "types"

# Prefix for type class names.
TYPES_CLASS_PREFIX = ""

# Available arithmetic operators.
ARITHMETIC_OPERATORS = ['+', '-', '*', '/']

# Scalar types we are interested in generating code for.
SCALAR_TYPES = ['float', 'int']


class CodeGenerator(object):
    """
    Code generator base class.  Basically wraps jinja2.Template.render.
    """

    def GenerateCode(self, templatePath):
        """
        Generate a single vector type as a header source.

        Args:
            templatePath (str): path to the template file to perform substitution.

        Returns:
            str: file name of generated vector class.
        """
        with open(templatePath, 'r') as f:
            templateStr = f.read()
            template = Template(templateStr)
            code = template.render(obj=self)
            return code


class AggregateIncludesCpp(CodeGenerator):
    """
    Code generation for aggregating includes in a single CPP.
    """

    def __init__(self, includePaths):
        self.includePaths = includePaths


class VectorType(CodeGenerator):
    """
    Code generation for an C++ vector type.
    """

    def __init__(self, dims, scalarType):
        assert(isinstance(dims, tuple))
        assert(isinstance(scalarType, str))
        self.dims = dims
        self.scalarType = scalarType
        self.elementSize = self.GetElementSize()
        self.className = self.GetClassName()

    def GetElementSize(self):
        """
        Returns:
            int: the number of elements in a vector.
        """
        return functools.reduce(lambda x, y: x * y, self.dims)

    def GetHeaderFileName(self):
        """
        Get the name of the header file to author the code into.

        Returns:
            str: header file name.
        """
        if len(self.dims) == 2:
            prefix = "mat"
        else:
            prefix = "vec"

        return "{prefix}{dims}{scalarType}.h".format(
            prefix=prefix,
            dims=str(self.dims[0]),
            scalarType=self.scalarType[0]
        )

    def GetClassName(self):
        """
        Get the name of the vector class.

        Returns:
            str: class name.
        """
        if len(self.dims) == 2:
            prefix = TYPES_CLASS_PREFIX + "Mat"
        else:
            prefix = TYPES_CLASS_PREFIX + "Vec"

        return "{prefix}{dims}{scalarType}".format(
            prefix=prefix,
            dims=str(self.dims[0]),
            scalarType=self.scalarType[0]
        )


class ArrayType(CodeGenerator):
    """
    Code generation for an C++ array type.
    """

    def __init__(self, elementTypeName, elementHeaderFileName=None):
        self.elementTypeName = elementTypeName
        self.elementHeaderFileName = elementHeaderFileName
        self.className = self.GetClassName()

    def GetClassName(self):
        """
        Returns:
            str: class name of this array.
        """
        if self.elementTypeName.startswith(TYPES_CLASS_PREFIX):
            prefix = ""
        else:
            prefix = TYPES_CLASS_PREFIX

        return "{prefix}{elementTypeName}Array".format(
            prefix=prefix,
            elementTypeName=(self.elementTypeName[0].upper() + self.elementTypeName[1:])
        )

    def GetHeaderFileName(self):
        """
        Get the name of the header file to author the code into.

        Returns:
            str: header file name.
        """
        if self.elementHeaderFileName:
            return "{elementHeaderFileName}Array.h".format(
                elementHeaderFileName=os.path.splitext(self.elementHeaderFileName)[0]
            )
        else:
            return "{elementTypeName}Array.h".format(
                elementTypeName=self.elementTypeName[0].lower() + self.elementTypeName[1:]
            )


def RunCommand(command):
    print("Running command {}".format(command))
    process = subprocess.Popen(shlex.split(command))
    process.wait()


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
    return os.path.abspath(os.path.join(CODEGENTEMPLATES_DIR, templateName))


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
        arrayType = ArrayType(vectorType.GetClassName(), elementHeaderFileName=vectorType.GetHeaderFileName())
        arrayTypes.append(arrayType)

    # Generate code for ArrayType(s)
    filePaths = []
    for arrayType in arrayTypes:
        fileName = arrayType.GetHeaderFileName()
        filePath = os.path.join(os.path.abspath(TYPES_DIR), fileName)
        code = arrayType.GenerateCode(GetCodeGenTemplate('arrayType.h'))
        print("Generated {!r}".format(filePath))
        with open(filePath, 'w') as f:
            f.write(code)
        filePaths.append(filePath)

    filePaths = []

    return filePaths


VECTOR_TYPES = [
    # Single-index vector types.
    VectorType((2,), "int"),
    VectorType((3,), "int"),
    VectorType((4,), "int"),
    VectorType((2,), "float"),
    VectorType((3,), "float"),
    VectorType((4,), "float"),

    # Matrix ve
    VectorType((3,3), "float"),
    VectorType((4,4), "float"),
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
        fileName = vectorType.GetHeaderFileName()
        code = vectorType.GenerateCode(GetCodeGenTemplate('vectorType.h'))
        filePath = os.path.join(os.path.abspath(TYPES_DIR), fileName)
        print("Generated {!r}".format(filePath))
        with open(filePath, 'w') as f:
            f.write(code)

        filePaths.append(filePath)
        headerFileNames.append(fileName)

    # Generate aggregation cpp source.
    includePaths = [os.path.join(PROJECT, TYPES_DIR, fileName) for fileName in headerFileNames]
    aggregateIncludes = AggregateIncludesCpp(includePaths)
    aggregateCode = aggregateIncludes.GenerateCode(GetCodeGenTemplate('aggregateIncludes.cpp'))
    aggregateCppPath = os.path.join(os.path.abspath(TYPES_DIR), "vectorTypes.cpp")
    with open(aggregateCppPath, 'w') as f:
        f.write(aggregateCode)
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


def GenerateCode():
    """
    Generate all code!
    """
    filePaths = GenTypes()
    FormatCode(filePaths)


if __name__ == "__main__":
    GenerateCode()


