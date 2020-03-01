#!/bin/bash

set -euxo pipefail

mkdir -p build && cd build

CMAKE_ARGS=\
\ -DUSD_ROOT="/apps/usd/20.02/"\
\ -DOPENSUBDIV_ROOT_DIR="/apps/opensubdiv/3.1.1"\
\ -DTBB_ROOT_DIR="/apps/tbb/4.4.6"\
\ -DBOOST_ROOT="/apps/boost/1.61.0"\
\ -DGLEW_LOCATION="/apps/glew/2.0.0"

# Only build if installation path not specified.
if [ $# -eq 0 ]
then
    cmake $CMAKE_ARGS ..
    cmake --build . -- -j 8
else
    cmake $CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=$1 ..
    cmake --build . --target install -- -j 8
fi
