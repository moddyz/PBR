__all__ = [
    "SCALAR_TYPES",
    "SCALAR_TYPE_DEFAULT_VALUE",
    "GenScalarDefaultValue",
]


# Scalar types we are interested in generating code for.
SCALAR_TYPES = ['float', 'int']

# Default values of scalar types.
SCALAR_TYPE_DEFAULT_VALUE = {
    'float': '0.0f',
    'int': '0',
}

def GenScalarDefaultValue(scalarType):
    """
    Generate the default value for a scalar type.

    Args:
        scalarType (str): name of the scalar type.

    Returnscols=:
        str: code.
    """
    return SCALAR_TYPE_DEFAULT_VALUE[scalarType]


