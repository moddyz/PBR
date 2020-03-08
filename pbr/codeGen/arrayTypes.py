"""
Code generation for C++ array types.

Currently, we simply use typdefs of std::vector templated by the element types.
"""

import os

from utils import (
    PrintInfo,
)

from constants import(
    TYPES_SUBDIRECTORY,
    TYPES_CLASS_PREFIX,
)

from base import (
    GenPragmaOnce,
    GenInclude,
    GenUsing,
    GenNamespaceBegin,
    GenNamespaceEnd,
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

        # Includes.
        if self.elementHeaderFileName:
            includePath = "pbr/types/{elementHeaderFileName}".format(
                elementHeaderFileName=self.elementHeaderFileName
            )
            code += GenInclude(includePath)
            code += os.linesep

        # Body.
        code += GenNamespaceBegin()
        code += os.linesep

        stdVectorTemplate = "std::vector< {elementTypeName} >".format(
            elementTypeName=self.elementTypeName
        )
        code += GenUsing(self.GetClassName(), stdVectorTemplate)
        code += os.linesep

        code += GenNamespaceEnd()

        return code

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
        filePath = os.path.join(os.path.abspath(TYPES_SUBDIRECTORY), fileName)
        code = arrayType.GenCode()
        PrintInfo("Generated {!r}:\n{}".format(filePath, code))
        with open(filePath, 'w') as f:
            f.write(code)
        filePaths.append(filePath)

    filePaths = []

    return filePaths
