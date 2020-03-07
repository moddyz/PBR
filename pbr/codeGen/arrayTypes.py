"""
Code generation for C++ array types.

Currently, we simply use typdefs of std::vector templated by the element types.
"""

import os

from utils import (
    PrintInfo,
)

from base import (
    GenPragmaOnce,
    GenInclude,
    GenUsing,
)

from scalarTypes import (
    SCALAR_TYPES,
)

from vectorTypes import (
    VECTOR_TYPES,
)


class ArrayType:
    """
    Code generation for an C++ array type.
    """

    def __init__(self, elementTypeName, elementHeaderFileName=None):
        self.elementTypeName = elementTypeName
        self.elementHeaderFileName = elementHeaderFileName

    def GenCode(self):
        """
        Returns:
            code: generated code for a C++ array type.
        """
        code = GenPragmaOnce()
        code += os.linesep

        if self.elementHeaderFileName:
            includePath = "pbr/types/{elementHeaderFileName}".format(
                elementHeaderFileName=self.elementHeaderFileName
            )
            code += GenInclude(includePath)
            code += os.linesep

        stdVectorTemplate = "std::vector< {elementTypeName} >".format(
            elementTypeName=self.elementTypeName
        )
        code += GenUsing(self.GetClassName(), stdVectorTemplate)

        return code

    def GetClassName(self):
        """
        Returns:
            str: class name of this array.
        """
        return "{elementTypeName}Array".format(
            elementTypeName=(self.elementTypeName[0].upper() + self.elementTypeName[1:])
        )

    def GetHeaderFileName(self):
        """
        Get the name of the header file to author the code into.

        Returns:
            str: header file name.
        """
        return "{elementTypeName}Array.h".format(
            elementTypeName=self.elementTypeName.lower()
        )


def GenArrayTypes(directoryPrefix):
    """
    Generate all array type source files.

    Args:
        directoryPrefix (str): directory prefix of generated files.

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
        filePath = os.path.join(os.path.abspath(directoryPrefix), fileName)
        code = arrayType.GenCode()
        PrintInfo("Generated {!r}:\n{}".format(filePath, code))
        with open(filePath, 'w') as f:
            f.write(code)
        filePaths.append(filePath)

    filePaths = []

    return filePaths
