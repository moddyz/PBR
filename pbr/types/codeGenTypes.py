#!/usr/bin/env python

"""
Code generation for C++ vector, matrix, and array types (forget templates!)
"""

import subprocess
import shlex


VECTOR_DIMS = [2, 3, 4]
SCALAR_TYPES = ['float', 'int', 'double']
SCALAR_TYPE_DEFAULT_VALUE = {
    'float': '0.0f',
    'double': '0.0',
    'int': '0',
}


def PrintInfo(message):
    print "[INFO] %s" % (message)


def GenPragmaOnce():
    return "#pragma once\n"


def GenNamespaceBegin():
    return "namespace pbr\n{\n"


def GenNamespaceEnd():
    return "} // namespace pbr\n"


def GenClassPublicQualifier():
    return "public:\n"


def GenClassPrivateQualifier():
    return "private:\n"


def GetDefaultValue(scalarType):
    return SCALAR_TYPE_DEFAULT_VALUE[scalarType]


def GetVectorFileName(vectorDim, scalarType):
    return "vec{vectorDim}{scalarType}.h".format(vectorDim=vectorDim, scalarType=scalarType[0])


def GetVectorClassName(vectorDim, scalarType):
    return "Vec{vectorDim}{scalarType}".format(vectorDim=vectorDim, scalarType=scalarType[0])


def GetVectorElementMember(index):
    return "m_elem{index}".format(index=index)


def GetVectorElementInput(index):
    return "i_elem{index}".format(index=index)


def GenVectorClassBegin(vectorDim, scalarType):
    code = "class {className}\n".format(className=GetVectorClassName(vectorDim, scalarType))
    code += "{\n"
    return code


def GenVectorClassEnd():
    return "};\n"


def GenVectorClassConstructor(vectorDim, scalarType):
    # Constructor arguments.
    code = "explicit {className}".format(className=GetVectorClassName(vectorDim, scalarType))
    code += "("
    for index in range(vectorDim):
        code += "const {scalarType}& {elementInput}".format(
            scalarType=scalarType,
            elementInput=GetVectorElementInput(index)
        )
        if index < vectorDim - 1:
            code += ","
    code += ")\n"

    # Initializer list.
    for index in range(vectorDim):
        if index == 0:
            code += ": "
        else:
            code += ", "
        code += "{elementMember}( {elementInput} )\n".format(
            elementMember=GetVectorElementMember(index),
            elementInput=GetVectorElementInput(index)
        )

    code += "{\n"
    code += "}\n"
    return code


def GenVectorClassMembers(vectorDim, scalarType):
    code = ""
    for index in range(vectorDim):
        code += "{scalarType} {elementMember} = {defaultValue};\n".format(
            scalarType=scalarType,
            elementMember=GetVectorElementMember(index),
            defaultValue=GetDefaultValue(scalarType)
        )
    return code


def GenVectorClass(vectorDim, scalarType):
    code = GenVectorClassBegin(vectorDim, scalarType)
    code += GenClassPublicQualifier()
    code += GenVectorClassConstructor(vectorDim, scalarType)
    code += GenClassPrivateQualifier()
    code += GenVectorClassMembers(vectorDim, scalarType)
    code += GenVectorClassEnd()
    return code


def GenVectorType(vectorDim, scalarType):
    code = GenPragmaOnce()
    code += GenNamespaceBegin()
    code += GenVectorClass(vectorDim, scalarType)
    code += GenNamespaceEnd()
    fileName = GetVectorFileName(vectorDim, scalarType)

    PrintInfo("Generated {!r}:\n{}".format(fileName, code))

    with open(fileName, 'w') as f:
        f.write(code)
    return fileName


def GenVectorTypes():
    fileNames = []
    for vectorDim in VECTOR_DIMS:
        for scalarType in SCALAR_TYPES:
            fileNames.append(GenVectorType(vectorDim, scalarType))
    return fileNames


def GenTypes():
    fileNames = GenVectorTypes()
    #fileNames += GenMatrixTypes()
    return fileNames


def FormatCode(fileNames):
    command = "clang-format -i " + " ".join(fileNames)
    PrintInfo("Running command {}".format(command))
    process = subprocess.Popen(shlex.split(command))
    process.wait()


if __name__ == "__main__":
    fileNames = GenTypes()
    FormatCode(fileNames)


