cmake_minimum_required(VERSION 3.10)

# Project Name
project(
    Pbrt VERSION 0.0
    DESCRIPTION "Physically based rendering."
    LANGUAGES CXX
)

# Cross-platform compatibility.
if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# Find modules.
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(USD REQUIRED)

# Build with C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler options
add_compile_options(-g -O3 -Werror)

# Build targets.
#add_subdirectory(pbrt)
add_subdirectory(hdPbrt)
