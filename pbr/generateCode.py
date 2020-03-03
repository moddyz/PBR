#!/usr/bin/env python

"""
Executable python script for auto-generating code for components of this project.
"""

from codeGen.tools import FormatCode
from codeGen.vectorTypes import GenVectorTypes


def GenTypes():
    """
    Top-level entry point for generating all data type source files.
    Vectors and matrices types will be generated.
    Array types of scalar, vectors, and matrices will also be generated.

    Returns:
        list: names of generated source files.
    """
    fileNames = GenVectorTypes('types/')
    #fileNames += GenMatrixTypes()
    return fileNames


def GenerateCode():
    """
    Generate all code!
    """
    fileNames = GenTypes()
    FormatCode(fileNames)


if __name__ == "__main__":
    GenerateCode()


