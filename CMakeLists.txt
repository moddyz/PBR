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

# Build with C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler options
add_compile_options(-g -O3 -Werror)

# Build targets.
add_subdirectory(hdPbrt)
