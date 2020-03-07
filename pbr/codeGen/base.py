"""
Common code generation logic for pbr.
"""

import os

from constants import NAMESPACE

__all__ = [
    "GenPragmaOnce",
    "GenNamespaceBegin",
    "GenNamespaceEnd",
    "GenClassPublicAccessSpecifier",
    "GenClassPrivateAccessSpecifier",
    "GenConstQualifier",
    "GenInclude",
    "GenIncludes",
    "GenAssert",
    "GenAggregateCpp",
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


def GenClassPublicAccessSpecifier():
    """
    Generate class public qualifier.

    Returns:
        str: code.
    """
    return "public:\n"


def GenClassPrivateAccessSpecifier():
    """
    Generate class private qualifier.

    Returns:
        str: code.
    """
    return "private:\n"


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
    """
    Generate a PBR_ASSERT for an expression.
    """
    return "PBR_ASSERT({expression});\n".format(expression=expression)


def GenAggregateCpp(directoryPrefix, headerFileNames):
    """
    Generate an aggregating cpp which includes multiple header files.

    Args:
        directoryPrefix (str): directory prefix which contain the header files.
        headerFileNames (list): header files to include in the aggregating cpp.

    Returns:
        str: file path to the aggregated cpp written to disk.
    """
    includePaths = [os.path.join(NAMESPACE, directoryPrefix, fileName) for fileName in headerFileNames]
    code = GenIncludes(includePaths)
    aggregateCppPath = os.path.join(directoryPrefix, "vectorTypes.cpp")
    with open(aggregateCppPath, 'w') as f:
        f.write(code)
    return aggregateCppPath



