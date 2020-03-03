"""
Common code generation logic for the C++ language.
"""

__all__ = [
    "GenPragmaOnce",
    "GenNamespaceBegin",
    "GenNamespaceEnd",
    "GenClassPublicQualifier",
    "GenClassPrivateQualifier",
]



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
