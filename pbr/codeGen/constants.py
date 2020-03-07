"""
Global constants used for code gen.
"""

__all__ = [
    "ARITHMETIC_OPERATORS",
    "NAMESPACE",
    "TYPES_SUBDIRECTORY",
]

# Namespace of all the symbols.
NAMESPACE = "pbr"

# Name of the subdirectory that all data types should reside.
TYPES_SUBDIRECTORY = "types"

# Available arithmetic operators.
ARITHMETIC_OPERATORS = ['+', '-', '*', '/']
