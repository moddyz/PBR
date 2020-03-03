"""
Base utilities which aid with code-gen.
"""

__all__ = [
    "PrintInfo",
    "RunCommand",
    "FormatCode",
]

import subprocess
import shlex


def PrintInfo(message):
    """
    Logging utility.
    """
    print "[INFO] %s" % (message)


def RunCommand(command):
    PrintInfo("Running command {}".format(command))
    process = subprocess.Popen(shlex.split(command))
    process.wait()


def FormatCode(fileNames):
    """
    Run clang-format over input files, formatting in-place.

    Args:
        fileNames (list): input files to automatically format.
    """
    command = "clang-format -i " + " ".join(fileNames)
    RunCommand(command)


