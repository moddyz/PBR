#!/usr/bin/env python

"""
Code generation for C++ vector, matrix, and array types (forget templates!)
"""

import subprocess
import shlex


NAMESPACE = "pbr"
VECTOR_DIMS = [2, 3, 4]
SCALAR_TYPES = ['float', 'int']
SCALAR_TYPE_DEFAULT_VALUE = {
    'float': '0.0f',
    'int': '0',
}
ARITHMETIC_OPERATORS = ['+', '-', '*', '/']


def PrintInfo(message):
    """
    Logging utility.
    """
    print "[INFO] %s" % (message)


def GetVectorClassHeaderFileName(vectorDim, scalarType):
    """
    Get the name of the source file to author the code into.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: source file name.
    """
    return "vec{vectorDim}{scalarType}.h".format(vectorDim=vectorDim, scalarType=scalarType.title())


def GenPragmaOnce():
    """
    Generate pragma once header guard directive.

    Returns:
        str: code.
    """
    return "#pragma once\n"


def GenNamespaceBegin(namespace):
    """
    Generate the beginning of a namespace.

    Args:
        namespace (str): namespace name.

    Returns:
        str: code.
    """
    return "namespace %s\n{\n" % (namespace)


def GenNamespaceEnd(namespace):
    """
    Generate the end of a namespace.

    Args:
        namespace (str): namespace name (encoded as a comment).

    Returns:
        str: code.
    """
    return "} // namespace %s\n" % (namespace)


def GenClassPublicQualifier():
    """
    Generate class public qualifier.

    Returns:
        str: code.
    """
    return "public:\n"


def GenClassPrivateQualifier():
    """
    Generate class private qualifier.

    Returns:
        str: code.
    """
    return "private:\n"


def GenScalarDefaultValue(scalarType):
    """
    Generate the default value for a scalar type.

    Args:
        scalarType (str): name of the scalar type.

    Returns:
        str: code.
    """
    return SCALAR_TYPE_DEFAULT_VALUE[scalarType]


def GenVectorClassName(vectorDim, scalarType):
    """
    Get the name of the vector class.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: class name.
    """
    return "Vec{vectorDim}{scalarType}".format(vectorDim=vectorDim, scalarType=scalarType.title())


def GenVectorClassElementMember():
    """
    Get the name of the vector class element member variable.

    Returns:
        str: argument name of a vector element argument.
    """
    return "m_elements"


def GenVectorClassElementArg(index):
    """
    Get the name of a vector element argument.

    Examples:
        i_element0
        i_element2

    Returns:
        str: argument name of a vector element argument.
    """
    return "i_element{index}".format(index=index)


def GetVectorArg():
    """
    Get the name of a vector value argument.

    Examples:
        i_vector

    Returns:
        str: argument name of a vector.
    """
    return "i_vector"


def GenScalarArg():
    """
    Get the name of a scalar value argument.

    Returns:
        str: argument name of a scalar.
    """
    return "i_scalar"


def GenVectorClassBegin(vectorDim, scalarType):
    """
    Generate the beginning of a class.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: argument name of a scalar.
    """
    code = "class {className}\n".format(className=GenVectorClassName(vectorDim, scalarType))
    code += "{\n"
    return code


def GenVectorClassEnd():
    """
    Generate the end of a class.

    Returns:
        str: argument name of a scalar.
    """
    return "};\n"


def GenVectorClassConstructor(vectorDim, scalarType):
    # Constructor arguments.
    code = "explicit {className}".format(className=GenVectorClassName(vectorDim, scalarType))
    code += "("
    for index in range(vectorDim):
        code += "const {scalarType}& {elementArg}".format(
            scalarType=scalarType,
            elementArg=GenVectorClassElementArg(index)
        )
        if index < vectorDim - 1:
            code += ","
    code += ")\n"

    # Initializer list.
    code += ": "
    code += "{elementMember}(".format(
        elementMember=GenVectorClassElementMember(),
    )
    code += "{"
    for index in range(vectorDim):
        code += GenVectorClassElementArg(index)
        if index < vectorDim - 1:
            code += ","
    code += "}"
    code += ")\n"

    code += "{\n"
    code += "}\n"
    return code


def GetVectorClassArithmeticOperatorArgTypeAndName(vectorDim, scalarType, operator):
    if operator in ['*', '/']:
        argType = scalarType
        argName = GenScalarArg()
    else:
        argType = GenVectorClassName(vectorDim, scalarType)
        argName = GetVectorArg()
    return argType, argName


def GenVectorClassArithmeticOperatorRHS(vectorDim, scalarType, operator, index):
    if operator in ['*', '/']:
        rhs = GenScalarArg()
    else:
        rhs = "{argName}.{elementMember}[{index}]".format(
            argName=GetVectorArg(),
            elementMember=GenVectorClassElementMember(),
            index=index,
        )
    return rhs


def GenVectorClassArithmeticOperator(vectorDim, scalarType, operator):
    """
    Generate arithmetic arithmetic operator overload.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.
        operator (str): type of arithmetic operator.

    Returns:
        str: code.
    """
    assert(operator in ARITHMETIC_OPERATORS)

    argType, argName = GetVectorClassArithmeticOperatorArgTypeAndName(vectorDim, scalarType, operator)
    code = "{className} operator{operator}( const {argType}& {argName} )\n".format(
        className=GenVectorClassName(vectorDim, scalarType),
        operator=operator,
        argType=argType,
        argName=argName,
    )
    code += "{\n"

    code += "return {className}(".format(
        className=GenVectorClassName(vectorDim, scalarType)
    )
    for index in range(vectorDim):
        rhs = GenVectorClassArithmeticOperatorRHS(vectorDim, scalarType, operator, index)
        code += "{elementMember}[{index}] {operator} {rhs}".format(
            elementMember=GenVectorClassElementMember(),
            index=index,
            operator=operator,
            rhs=rhs,
        )
        if index < vectorDim - 1:
            code += ",\n"

    code += ");\n"
    code += "}\n"
    return code


def GenVectorClassArithmeticAssignmentOperator(vectorDim, scalarType, operator):
    """
    Generate arithmetic arithmetic assignment operator overload.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.
        operator (str): type of arithmetic operator.

    Returns:
        str: code.
    """
    argType, argName = GetVectorClassArithmeticOperatorArgTypeAndName(vectorDim, scalarType, operator)
    code = "{className}& operator{operator}=( const {argType}& {argName} )\n".format(
        className=GenVectorClassName(vectorDim, scalarType),
        operator=operator,
        argType=argType,
        argName=argName,
    )
    code += "{\n"

    for index in range(vectorDim):
        rhs = GenVectorClassArithmeticOperatorRHS(vectorDim, scalarType, operator, index)
        code += "{elementMember}[{index}] {operator}= {rhs};".format(
            elementMember=GenVectorClassElementMember(),
            index=index,
            operator=operator,
            rhs=rhs
        )
    code += "return *this;\n"
    code += "}\n"
    return code


def GenVectorClassMembers(vectorDim, scalarType):
    """
    Generate members for a vector class.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: code.
    """
    code = "{scalarType} {elementMember}[{vectorDim}] =".format(
        scalarType=scalarType,
        elementMember=GenVectorClassElementMember(),
        vectorDim=vectorDim,
    )
    code += "{\n"
    for index in range(vectorDim):
        code += GenScalarDefaultValue(scalarType)
        if index < vectorDim - 1:
            code += ",\n"
    code += "};\n"
    return code


def GenVectorClass(vectorDim, scalarType):
    """
    Generate a single vector type class definition.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: code.
    """
    code = GenVectorClassBegin(vectorDim, scalarType)
    code += GenClassPublicQualifier()
    code += GenVectorClassConstructor(vectorDim, scalarType)
    code += "\n"

    for operator in ARITHMETIC_OPERATORS:
        code += GenVectorClassArithmeticOperator(vectorDim, scalarType, operator)
        code += "\n"
        code += GenVectorClassArithmeticAssignmentOperator(vectorDim, scalarType, operator)
        code += "\n"

    code += GenClassPrivateQualifier()
    code += GenVectorClassMembers(vectorDim, scalarType)
    code += GenVectorClassEnd()
    return code


def GenVectorType(vectorDim, scalarType):
    """
    Generate a single vector type as a header source.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: file name of generated vector class.
    """
    code = GenPragmaOnce()
    code += GenNamespaceBegin(NAMESPACE)
    code += GenVectorClass(vectorDim, scalarType)
    code += GenNamespaceEnd(NAMESPACE)
    fileName = GetVectorClassHeaderFileName(vectorDim, scalarType)

    PrintInfo("Generated {!r}:\n{}".format(fileName, code))

    with open(fileName, 'w') as f:
        f.write(code)
    return fileName


def GenVectorTypes():
    """
    Generate all vector type source files, across matrix VECTOR_DIM x SCALAR_TYPES.

    Returns:
        list: names of generated source files.
    """
    fileNames = []
    for vectorDim in VECTOR_DIMS:
        for scalarType in SCALAR_TYPES:
            fileNames.append(GenVectorType(vectorDim, scalarType))
    return fileNames


def GenTypes():
    """
    Top-level entry point for generating all data type source files.
    Vectors and matrices types will be generated.
    Array types of scalar, vectors, and matrices will also be generated.

    Returns:
        list: names of generated source files.
    """
    fileNames = GenVectorTypes()
    #fileNames += GenMatrixTypes()
    return fileNames


def FormatCode(fileNames):
    """
    Run clang-format over input files, formatting in-place.

    Args:
        fileNames (list): input files to automatically format.
    """
    command = "clang-format -i " + " ".join(fileNames)
    PrintInfo("Running command {}".format(command))
    process = subprocess.Popen(shlex.split(command))
    process.wait()


if __name__ == "__main__":
    fileNames = GenTypes()
    FormatCode(fileNames)


