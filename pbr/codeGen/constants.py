"""
Global constants used for code gen.
"""

__all__ = [
    "NAMESPACE",
    "SCALAR_TYPES",
    "SCALAR_TYPE_DEFAULT_VALUE",
    "ARITHMETIC_OPERATORS",
]

# Namespace of all the symbols.
NAMESPACE = "pbr"

# Scalar types we are interested in generating code for.
SCALAR_TYPES = ['float', 'int']

# Default values of scalar types.
SCALAR_TYPE_DEFAULT_VALUE = {
    'float': '0.0f',
    'int': '0',
}

# Available arithmetic operators.
ARITHMETIC_OPERATORS = ['+', '-', '*', '/']
