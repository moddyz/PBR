#!/bin/bash

set -euxo pipefail

mkdir -p build && cd build

ARGS=-DUSD_ROOT=/apps/usd/dev/

# Only build if installation path not specified.
if [ $# -eq 0 ]
then
    cmake $ARGS ..
    cmake --build .
else
    cmake $ARGS -DCMAKE_INSTALL_PREFIX=$1 ..
    cmake --build . --target install
fi
