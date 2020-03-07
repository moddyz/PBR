#!/usr/bin/env python

"""
Executable python script for auto-generating code for components of this project.
"""

import os

from codeGen.utils import FormatCode
from codeGen.vectorTypes import GenVectorTypes
from codeGen.arrayTypes import GenArrayTypes


def GenTypes():
    """
    Top-level entry point for generating all data type source files.
    Vectors and matrices types will be generated.
    Array types of scalar, vectors, and matrices will also be generated.

    Returns:
        list: paths to of generated source files.
    """
    filePaths = GenVectorTypes()
    filePaths += GenArrayTypes()
    return filePaths


def GenerateCode():
    """
    Generate all code!
    """
    filePaths = GenTypes()
    FormatCode(filePaths)


if __name__ == "__main__":
    GenerateCode()


