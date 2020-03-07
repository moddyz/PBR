"""
Code generation for C++ vector types.
"""

__all__ = [
    "VectorType"
    "VECTOR_TYPES",
    "GenVectorTypes"
]

import os
import functools

from constants import (
    NAMESPACE,
    ARITHMETIC_OPERATORS,
)

from scalarTypes import (
    SCALAR_TYPES,
    SCALAR_TYPE_DEFAULT_VALUE,
    GenScalarDefaultValue,
)


from utils import (
    PrintInfo
)

from base import (
    GenPragmaOnce,
    GenNamespaceBegin,
    GenNamespaceEnd,
    GenClassDefaultConstructor,
    GenClassDefaultDestructor,
    GenClassPublicAccessSpecifier,
    GenClassPrivateAccessSpecifier,
    GenConstQualifier,
    GenInclude,
    GenIncludes,
    GenAssert,
    GenAggregateCpp,
)


class VectorType(object):
    """
    Code generation for an C++ vector type.
    """

    def __init__(self, dims, scalarType):
        assert(isinstance(dims, tuple))
        assert(isinstance(scalarType, str))
        self.dims = dims
        self.scalarType = scalarType

    def GenCode(self):
        """
        Generate a single vector type as a header source.

        Returns:
            str: file name of generated vector class.
        """
        code = GenPragmaOnce()
        code += os.linesep

        # Includes
        code += GenInclude("cmath")
        code += GenInclude("cstring")
        code += GenInclude("pbr/tools/assert.h")
        code += os.linesep

        # Body
        code += GenNamespaceBegin(NAMESPACE)
        code += self.GenClass()
        code += GenNamespaceEnd(NAMESPACE)

        return code

    def GenClass(self):
        """
        Generate a single vector type class definition.

        Returns:
            str: code.
        """
        code = "class {className} final\n".format(className=self.GetClassName())
        code += "{\n"

        #
        # Public.
        #

        code += GenClassPublicAccessSpecifier()

        code += GenClassDefaultConstructor(self.GetClassName())
        code += GenClassDefaultDestructor(self.GetClassName())
        code += os.linesep
        code += self.GenClassElementWiseConstructor()
        code += os.linesep
        code += self.GenClassCopyConstructor()
        code += os.linesep
        code += self.GenClassCopyAssignmentOperator()
        code += os.linesep

        code += self.GenClassSquareBracketOperator(constQualified=False)
        code += os.linesep
        code += self.GenClassSquareBracketOperator(constQualified=True)
        code += os.linesep

        # Only generate arithmetic operator overloading for single-index vector dim.
        if len(self.dims) == 1:
            for operator in ARITHMETIC_OPERATORS:
                code += self.GenClassArithmeticOperator(operator)
                code += os.linesep
                code += self.GenClassArithmeticAssignmentOperator(operator)
                code += os.linesep

        # Generate round bracket operator for matrix classes.
        if len(self.dims) == 2:
            code += self.GenClassRoundBracketOperator(constQualified=False)
            code += os.linesep
            code += self.GenClassRoundBracketOperator(constQualified=True)
            code += os.linesep

        code += self.GenClassHasNans()
        code += os.linesep

        #
        # Private.
        #

        code += GenClassPrivateAccessSpecifier()
        code += self.GenClassMembers()
        code += "};";

        return code

    def GetElementCount(self):
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
            scalarType=self.scalarType.title()
        )

    def GetClassName(self):
        """
        Get the name of the vector class.

        Returns:
            str: class name.
        """
        if len(self.dims) == 2:
            prefix = "Mat"
        else:
            prefix = "Vec"

        return "{prefix}{dims}{scalarType}".format(
            prefix=prefix,
            dims=str(self.dims[0]),
            scalarType=self.scalarType.title()
        )

    @staticmethod
    def GetClassElementMember():
        """
        Returns:
            str: member name of vector class' elements.
        """
        return "m_elements"

    @staticmethod
    def GetElementArg(index):
        """
        Get the name of a vector element argument.

        Examples:
            i_element0
            i_element2

        Returns:
            str: argument name of a vector element argument.
        """
        return "i_element{index}".format(index=index)

    def GetVectorArg(self):
        """
        Get the name of a vector value argument.

        Returns:
            str: argument name of a vector.
        """
        if len(self.dims) == 2:
            return "i_matrix"
        elif len(self.dims) == 1:
            return "i_vector"
        else:
            raise ValueError("Unsupported vector dimension: {}".format(self.dims))

    @staticmethod
    def GetScalarArg():
        """
        Get the name of a scalar value argument.

        Returns:
            str: argument name of a scalar.
        """
        return "i_scalar"

    def GenClassElementWiseConstructor(self):
        """
        Generate the class constructor.
        """
        # Constructor arguments.
        code = "explicit {className}".format(className=self.GetClassName())
        code += "("

        elementCount = self.GetElementCount()
        for index in range(elementCount):
            code += "const {scalarType}& {elementArg}".format(
                scalarType=self.scalarType,
                elementArg=self.GetElementArg(index)
            )
            if index < elementCount - 1:
                code += ","
        code += ")\n"

        # Initializer list.
        code += ": "
        code += "{elementMember}".format(
            elementMember=self.GetClassElementMember(),
        )
        code += "{"
        for index in range(elementCount):
            code += self.GetElementArg(index)
            if index < elementCount - 1:
                code += ","
        code += "}\n"

        code += "{\n"
        code += GenAssert("!HasNans()")
        code += "}\n"
        return code

    def GenClassMemberCopy(self):
        """
        Generate code for copying members from a vector class to another.
        Used in copy constructor and copy assignment operator, so the source vector variable name is implied to be GetVectorArg().

        Returns:
            str: generated code.
        """
        return "std::memcpy((void*) {elementMember}, (const void*){vectorArg}.{elementMember}, sizeof({elementMember}) );".format(
            vectorArg=self.GetVectorArg(),
            elementMember=self.GetClassElementMember()
        )

    def GenClassCopyConstructor(self):
        """
        Returns:
            str: code for vector class copy constructor.
        """
        code = "{className} ( const {className}& {vectorArg} )\n".format(
            className=self.GetClassName(),
            vectorArg=self.GetVectorArg()
        )

        # Copy element member.
        code += "{"
        code += GenAssert("!HasNans()")
        code += self.GenClassMemberCopy()
        code += "}\n"
        return code

    def GenClassCopyAssignmentOperator(self):
        """
        Returns:
            str: code for vector class copy assignment operator.
        """
        code = "{className}& operator=( const {className}& {vectorArg} )\n".format(
            className=self.GetClassName(),
            vectorArg=self.GetVectorArg()
        )

        # Copy element member.
        code += "{"
        code += GenAssert("!HasNans()")
        code += self.GenClassMemberCopy()
        code += "return *this;"
        code += "}\n"
        return code

    def GenClassArithmeticOperatorArgTypeAndName(self, operator):
        if operator in ['*', '/']:
            argType = self.scalarType
            argName = self.GetScalarArg()
        else:
            argType = self.GetClassName()
            argName = self.GetVectorArg()
        return argType, argName

    def GenClassArithmeticOperatorRHS(self, operator, index):
        if operator in ['*', '/']:
            rhs = self.GetScalarArg()
        else:
            rhs = "{argName}.{elementMember}[{index}]".format(
                argName=self.GetVectorArg(),
                elementMember=self.GetClassElementMember(),
                index=index,
            )
        return rhs

    def GenClassArithmeticOperator(self, operator):
        """
        Generate arithmetic arithmetic operator overload.

        Args:
            operator (str): type of arithmetic operator.

        Returns:
            str: code.
        """
        assert(operator in ARITHMETIC_OPERATORS)

        argType, argName = self.GenClassArithmeticOperatorArgTypeAndName(operator)
        code = "{className} operator{operator}( const {argType}& {argName} )\n".format(
            className=self.GetClassName(),
            operator=operator,
            argType=argType,
            argName=argName,
        )
        code += "{\n"
        code += GenAssert("!HasNans()")
        code += "return {className}(".format(
            className=self.GetClassName()
        )

        elementCount = self.GetElementCount()
        for index in range(elementCount):
            rhs = self.GenClassArithmeticOperatorRHS(operator, index)
            code += "{elementMember}[{index}] {operator} {rhs}".format(
                elementMember=self.GetClassElementMember(),
                index=index,
                operator=operator,
                rhs=rhs,
            )
            if index < elementCount - 1:
                code += ",\n"

        code += ");\n"
        code += "}\n"
        return code

    def GenClassArithmeticAssignmentOperator(self, operator):
        """
        Generate arithmetic arithmetic assignment operator overload.

        Args:
            operator (str): type of arithmetic operator.

        Returns:
            str: code.
        """
        argType, argName = self.GenClassArithmeticOperatorArgTypeAndName(operator)
        code = "{className}& operator{operator}=( const {argType}& {argName} )\n".format(
            className=self.GetClassName(),
            operator=operator,
            argType=argType,
            argName=argName,
        )
        code += "{\n"

        code += GenAssert("!HasNans()")
        elementCount = self.GetElementCount()
        for index in range(elementCount):
            rhs = self.GenClassArithmeticOperatorRHS(operator, index)
            code += "{elementMember}[{index}] {operator}= {rhs};".format(
                elementMember=self.GetClassElementMember(),
                index=index,
                operator=operator,
                rhs=rhs
            )
        code += "return *this;\n"
        code += "}\n"
        return code

    def GenClassSquareBracketOperator(self, constQualified=False):
        """
        Generate square brackets [] element access operator overload method.

        Args:
            constQualified (bool): generate the const qualified variant?

        Returns:
            str: code.
        """
        code = "{constQualifier} {scalarType}& operator[]( size_t {indexArg} ) {constQualifier}\n".format(
            scalarType=self.scalarType,
            indexArg=self.GenIndexArg(),
            constQualifier=GenConstQualifier() if constQualified else ""
        )
        code += "{\n"
        code += GenAssert("!HasNans()")
        code += "return {elementMember}[{index}];\n".format(
            elementMember=self.GetClassElementMember(),
            index=self.GenIndexArg(),
        )
        code += "}\n"
        return code

    def GenClassRoundBracketOperator(self, constQualified=False):
        """
        Generate round brackets () element access operator overload method.
        Exclusively for matrix classes.

        Args:
            constQualified (bool): generate the const qualified variant?

        Returns:
            str: code.
        """
        code = "{constQualifier} {scalarType}& operator()( size_t {rowIndexArg}, size_t {columnIndexArg} ) {constQualifier}\n".format(
            scalarType=self.scalarType,
            rowIndexArg=self.GenRowIndexArg(),
            columnIndexArg=self.GenColumnIndexArg(),
            constQualifier=GenConstQualifier() if constQualified else ""
        )
        code += "{\n"

        elementIndexExpression = "( {rowIndexArg} * {vectorColumnDim} ) + {columnIndexArg}".format(
            rowIndexArg=self.GenRowIndexArg(),
            vectorColumnDim=self.dims[1],
            columnIndexArg=self.GenColumnIndexArg()
        )

        code += GenAssert("!HasNans()")
        code += "return {elementMember}[{index}];\n".format(
            elementMember=self.GetClassElementMember(),
            index=elementIndexExpression,
        )
        code += "}\n"

        return code

    def GenClassHasNans(self):
        """
        Generate HasNans method.

        Returns:
            str: code.
        """
        code = "bool HasNans() {constQualifier}\n".format(
            constQualifier=GenConstQualifier()
        )
        code += "{\n"
        code += GenAssert("!HasNans()")
        code += "return "
        elementCount = self.GetElementCount()
        for index in range(elementCount):
            code += "std::isnan({elementMember}[{index}])".format(
                elementMember=self.GetClassElementMember(),
                index=index
            )
            if index < elementCount - 1:
                code += " || "
        code += ";\n"
        code += "}\n"
        return code

    def GenClassMembers(self):
        """
        Generate members for a vector class.

        Returns:
            str: code.
        """
        code = "{scalarType} {elementMember}[{elementCount}] =".format(
            scalarType=self.scalarType,
            elementMember=self.GetClassElementMember(),
            elementCount=self.GetElementCount(),
        )
        code += "{\n"
        elementCount = self.GetElementCount()
        for index in range(elementCount):
            code += GenScalarDefaultValue(self.scalarType)
            if index < elementCount - 1:
                code += ",\n"
        code += "};\n"
        return code

    @staticmethod
    def GenIndexArg():
        """
        Returns:
            str: index argument.
        """
        return "i_index"

    @staticmethod
    def GenRowIndexArg():
        """
        Returns:
            str: row index argument name.  Used in operator() overload.
        """
        return "i_row"

    @staticmethod
    def GenColumnIndexArg():
        """
        Returns:
            str: column index argument name.  Used in operator() overload.
        """
        return "i_column"


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


def GenVectorTypes(directoryPrefix):
    """
    Generate all vector type source files.

    Args:
        directoryPrefix (str): directory prefix of generated files.

    Returns:
        list: paths to generated source files.
    """
    # Generate vector class headers.
    filePaths = []
    headerFileNames = []
    for vectorType in VECTOR_TYPES:

        fileName = vectorType.GetHeaderFileName()
        filePath = os.path.join(os.path.abspath(directoryPrefix), fileName)
        code = vectorType.GenCode()
        PrintInfo("Generated {!r}:\n{}".format(filePath, code))
        with open(filePath, 'w') as f:
            f.write(code)

        filePaths.append(filePath)
        headerFileNames.append(fileName)

    # Generate aggregation cpp source.
    aggregateCppPath = GenAggregateCpp(directoryPrefix, headerFileNames)
    filePaths.append(aggregateCppPath)

    return filePaths
