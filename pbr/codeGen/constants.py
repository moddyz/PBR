"""
Global constants used for code gen.
"""

__all__ = [
    "ARITHMETIC_OPERATORS",
    "PROJECT",
    "TYPES_SUBDIRECTORY",
    "TYPES_CLASS_PREFIX",
]

# Namespace of all the symbols.
PROJECT = "pbr"

# Name of the subdirectory that all data types should reside.
TYPES_SUBDIRECTORY = "types"

# Prefix for all data type class names.
TYPES_CLASS_PREFIX = "Dt"

# Available arithmetic operators.
ARITHMETIC_OPERATORS = ['+', '-', '*', '/']
