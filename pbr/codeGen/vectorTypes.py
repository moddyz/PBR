"""
Code generation for C++ vector, matrix, and array types (forget templates!)
"""

import os

from constants import (
    NAMESPACE,
    SCALAR_TYPES,
    SCALAR_TYPE_DEFAULT_VALUE,
    ARITHMETIC_OPERATORS
)

from utils import (
    PrintInfo
)

from base import (
    GenPragmaOnce,
    GenNamespaceBegin,
    GenNamespaceEnd,
    GenClassPublicAccessSpecifier,
    GenClassPrivateAccessSpecifier,
    GenIndexArg,
    GenRowIndexArg,
    GenColumnIndexArg,
    GenConstQualifier,
    GenInclude,
    GenIncludes,
    GenAssert,
    GenAggregateCpp,
)

VECTOR_DIMS = [
    # Single-index vector types.
    (2,),
    (3,),
    (4,),

    # Matrix vector types.
    (3, 3),
    (4, 4),
]


def GetVectorElementCount(vectorDim):
    """
    Returns:
        int: the number of elements in a vector.
    """
    product = 1
    for dim in vectorDim:
        product *= dim
    return product


def GetVectorDimString(vectorDim):
    """
    Returns:
        str: string representation of a vector dimension.
    """
    return str(vectorDim[0])


def GetVectorClassHeaderFileName(vectorDim, scalarType):
    """
    Get the name of the source file to author the code into.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: source file name.
    """
    if len(vectorDim) == 2:
        prefix = "matrix"
    else:
        prefix = "vector"

    return "{prefix}{vectorDim}{scalarType}.h".format(
        prefix=prefix,
        vectorDim=GetVectorDimString(vectorDim),
        scalarType=scalarType[0]
    )


def GenScalarDefaultValue(scalarType):
    """
    Generate the default value for a scalar type.

    Args:
        scalarType (str): name of the scalar type.

    Returnscols=:
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
    if len(vectorDim) == 2:
        prefix = "Matrix"
    else:
        prefix = "Vector"

    return "{prefix}{vectorDim}{scalarType}".format(
        prefix=prefix,
        vectorDim=GetVectorDimString(vectorDim),
        scalarType=scalarType[0]
    )


def GenVectorClassElementMember():
    """
    Returns:
        str: member name of vector class' elements.
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


def GetVectorArg(vectorDim):
    """
    Get the name of a vector value argument.

    Args:
        vectorDim (object): vector dimension.

    Returns:
        str: argument name of a vector.
    """
    if len(vectorDim) == 2:
        return "i_matrix"
    elif len(vectorDim) == 1:
        return "i_vector"
    else:
        raise ValueError("Unsupported vector dimension: {}".format(vectorDim))


def GenScalarArg():
    """
    Get the name of a scalar value argument.

    Returns:
        str: argument name of a scalar.
    """
    return "i_scalar"


def GenVectorClassConstructor(vectorDim, scalarType):
    # Constructor arguments.
    code = "explicit {className}".format(className=GenVectorClassName(vectorDim, scalarType))
    code += "("

    elementCount = GetVectorElementCount(vectorDim)
    for index in range(elementCount):
        code += "const {scalarType}& {elementArg}".format(
            scalarType=scalarType,
            elementArg=GenVectorClassElementArg(index)
        )
        if index < elementCount - 1:
            code += ","
    code += ")\n"

    # Initializer list.
    code += ": "
    code += "{elementMember}".format(
        elementMember=GenVectorClassElementMember(),
    )
    code += "{"
    for index in range(elementCount):
        code += GenVectorClassElementArg(index)
        if index < elementCount - 1:
            code += ","
    code += "}\n"

    code += "{\n"
    code += GenAssert("!HasNans()")
    code += "}\n"
    return code


def GenVectorClassCopyMembers(vectorDim):
    """
    Generate code for copying members from a vector class to another.
    Used in copy constructor and copy assignment operator, so the source vector variable name is implied to be GetVectorArg().

    Returns:
        str: generated code.
    """
    return "std::memcpy((void*) {elementMember}, (const void*){vectorArg}.{elementMember}, sizeof({elementMember}) );".format(
        vectorArg=GetVectorArg(vectorDim),
        elementMember=GenVectorClassElementMember()
    )


def GenVectorClassCopyConstructor(vectorDim, scalarType):
    code = "{className} ( const {className}& {vectorArg} )\n".format(
        className=GenVectorClassName(vectorDim, scalarType),
        vectorArg=GetVectorArg(vectorDim)
    )

    # Copy element member.
    code += "{"
    code += GenAssert("!HasNans()")
    code += GenVectorClassCopyMembers(vectorDim)
    code += "}\n"
    return code


def GenVectorClassCopyAssignmentOperator(vectorDim, scalarType):
    code = "{className}& operator=( const {className}& {vectorArg} )\n".format(
        className=GenVectorClassName(vectorDim, scalarType),
        vectorArg=GetVectorArg(vectorDim)
    )

    # Copy element member.
    code += "{"
    code += GenAssert("!HasNans()")
    code += GenVectorClassCopyMembers(vectorDim)
    code += "return *this;"
    code += "}\n"
    return code


def GetVectorClassArithmeticOperatorArgTypeAndName(vectorDim, scalarType, operator):
    if operator in ['*', '/']:
        argType = scalarType
        argName = GenScalarArg()
    else:
        argType = GenVectorClassName(vectorDim, scalarType)
        argName = GetVectorArg(vectorDim)
    return argType, argName


def GenVectorClassArithmeticOperatorRHS(vectorDim, scalarType, operator, index):
    if operator in ['*', '/']:
        rhs = GenScalarArg()
    else:
        rhs = "{argName}.{elementMember}[{index}]".format(
            argName=GetVectorArg(vectorDim),
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
    code += GenAssert("!HasNans()")
    code += "return {className}(".format(
        className=GenVectorClassName(vectorDim, scalarType)
    )

    elementCount = GetVectorElementCount(vectorDim)
    for index in range(elementCount):
        rhs = GenVectorClassArithmeticOperatorRHS(vectorDim, scalarType, operator, index)
        code += "{elementMember}[{index}] {operator} {rhs}".format(
            elementMember=GenVectorClassElementMember(),
            index=index,
            operator=operator,
            rhs=rhs,
        )
        if index < elementCount - 1:
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

    code += GenAssert("!HasNans()")
    elementCount = GetVectorElementCount(vectorDim)
    for index in range(elementCount):
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


def GenVectorClassSquareBracketOperator(vectorDim, scalarType, constQualified=False):
    """
    Generate square brackets [] element access operator overload method.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.
        constQualified (bool): generate the const qualified variant?

    Returns:
        str: code.
    """
    code = "{constQualifier} {scalarType}& operator[]( size_t {indexArg} ) {constQualifier}\n".format(
        scalarType=scalarType,
        indexArg=GenIndexArg(),
        constQualifier=GenConstQualifier() if constQualified else ""
    )
    code += "{\n"
    code += GenAssert("!HasNans()")
    code += "return {elementMember}[{index}];\n".format(
        elementMember=GenVectorClassElementMember(),
        index=GenIndexArg(),
    )
    code += "}\n"
    return code


def GenVectorClassRoundBracketOperator(vectorDim, scalarType, constQualified=False):
    """
    Generate round brackets () element access operator overload method.
    Exclusively for matrix classes.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.
        constQualified (bool): generate the const qualified variant?

    Returns:
        str: code.
    """
    code = "{constQualifier} {scalarType}& operator()( size_t {rowIndexArg}, size_t {columnIndexArg} ) {constQualifier}\n".format(
        scalarType=scalarType,
        rowIndexArg=GenRowIndexArg(),
        columnIndexArg=GenColumnIndexArg(),
        constQualifier=GenConstQualifier() if constQualified else ""
    )
    code += "{\n"

    elementIndexExpression = "( {rowIndexArg} * {vectorColumnDim} ) + {columnIndexArg}".format(
        rowIndexArg=GenRowIndexArg(),
        vectorColumnDim=vectorDim[1],
        columnIndexArg=GenColumnIndexArg()
    )

    code += GenAssert("!HasNans()")
    code += "return {elementMember}[{index}];\n".format(
        elementMember=GenVectorClassElementMember(),
        index=elementIndexExpression,
    )
    code += "}\n"

    return code


def GenVectorClassHasNans(vectorDim, scalarType):
    """
    Generate HasNans method.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: code.
    """
    code = "bool HasNans() {constQualifier}\n".format(
        constQualifier=GenConstQualifier()
    )
    code += "{\n"
    code += GenAssert("!HasNans()")
    code += "return "
    elementCount = GetVectorElementCount(vectorDim)
    for index in range(elementCount):
        code += "std::isnan({elementMember}[{index}])".format(
            elementMember=GenVectorClassElementMember(),
            index=index
        )
        if index < elementCount - 1:
            code += " || "
    code += ";\n"
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
        vectorDim=GetVectorElementCount(vectorDim),
    )
    code += "{\n"
    elementCount = GetVectorElementCount(vectorDim)
    for index in range(elementCount):
        code += GenScalarDefaultValue(scalarType)
        if index < elementCount - 1:
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
    code = "class {className}\n".format(className=GenVectorClassName(vectorDim, scalarType))
    code += "{\n"

    #
    # Public.
    #

    code += GenClassPublicAccessSpecifier()

    code += GenVectorClassConstructor(vectorDim, scalarType)
    code += "\n"
    code += GenVectorClassCopyConstructor(vectorDim, scalarType)
    code += "\n"
    code += GenVectorClassCopyAssignmentOperator(vectorDim, scalarType)
    code += "\n"

    code += GenVectorClassSquareBracketOperator(vectorDim, scalarType, constQualified=False)
    code += "\n"
    code += GenVectorClassSquareBracketOperator(vectorDim, scalarType, constQualified=True)
    code += "\n"

    # Only generate arithmetic operator overloading for single-index vector dim.
    if len(vectorDim) == 1:
        for operator in ARITHMETIC_OPERATORS:
            code += GenVectorClassArithmeticOperator(vectorDim, scalarType, operator)
            code += "\n"
            code += GenVectorClassArithmeticAssignmentOperator(vectorDim, scalarType, operator)
            code += "\n"

    # Generate round bracket operator for matrix classes.
    if len(vectorDim) == 2:
        code += GenVectorClassRoundBracketOperator(vectorDim, scalarType, constQualified=False)
        code += "\n"
        code += GenVectorClassRoundBracketOperator(vectorDim, scalarType, constQualified=True)
        code += "\n"

    code += GenVectorClassHasNans(vectorDim, scalarType)
    code += "\n"

    #
    # Private.
    #

    code += GenClassPrivateAccessSpecifier()
    code += GenVectorClassMembers(vectorDim, scalarType)
    code += "};";

    return code


def GenVectorTypeHeader(vectorDim, scalarType):
    """
    Generate a single vector type as a header source.

    Args:
        vectorDim (int): number of elements in the vector.
        scalarType (str): scalar type of each element.

    Returns:
        str: file name of generated vector class.
    """
    code = GenPragmaOnce()
    code += "\n"

    # Includes
    code += GenInclude("cmath")
    code += GenInclude("cstring")
    code += GenInclude("pbr/tools/assert.h")
    code += "\n"

    # Body
    code += GenNamespaceBegin(NAMESPACE)
    code += GenVectorClass(vectorDim, scalarType)
    code += GenNamespaceEnd(NAMESPACE)

    return code


def GenVectorTypes(directoryPrefix):
    """
    Generate all vector type source files, across matrix VECTOR_DIM x SCALAR_TYPES.

    Args:
        directoryPrefix (str): directory prefix of generated files.

    Returns:
        list: paths to generated source files.
    """
    # Generate vector class headers.
    filePaths = []
    headerFileNames = []
    for vectorDim in VECTOR_DIMS:
        for scalarType in SCALAR_TYPES:

            # Don't generate matrices with integer elements.
            if scalarType == "int" and len(vectorDim) == 2:
                continue

            code = GenVectorTypeHeader(vectorDim, scalarType)
            fileName = GetVectorClassHeaderFileName(vectorDim, scalarType)
            filePath = os.path.join(os.path.abspath(directoryPrefix), fileName)

            PrintInfo("Generated {!r}:\n{}".format(filePath, code))
            with open(filePath, 'w') as f:
                f.write(code)

            filePaths.append(filePath)
            headerFileNames.append(fileName)

    # Generate aggregation cpp source.
    aggregateCppPath = GenAggregateCpp(directoryPrefix, headerFileNames)
    filePaths.append(aggregateCppPath)

    return filePaths
