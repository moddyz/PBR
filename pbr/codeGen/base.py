"""
Common code generation logic for pbr.
"""

__all__ = [
    "GenPragmaOnce",
    "GenNamespaceBegin",
    "GenNamespaceEnd",
    "GenClassPublicQualifier",
    "GenClassPrivateQualifier",
    "GenIndexArg",
    "GenConstQualifier",
    "GenInclude",
    "GenIncludes",
    "GenAssert",
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


def GenIndexArg():
    """
    Generate index argument name.  Used in operator[] overload.

    Returns:
        str: code.
    """
    return "i_index"


def GenConstQualifier():
    """
    Generate the const qualifier.

    Returns:
        str: code.
    """
    return "const"


def GenInclude(includePath):
    """
    Returns:
        str: an include statement.
    """
    return "#include <{includePath}>\n".format(includePath=includePath)


def GenIncludes(includePaths):
    """
    Returns:
        str: multiple include statements.
    """
    code = ""
    for includePath in includePaths:
        code += GenInclude(includePath)
    return code


def GenAssert(expression):
    return "ASSERT({expression});\n".format(expression=expression)



