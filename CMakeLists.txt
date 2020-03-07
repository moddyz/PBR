cmake_minimum_required(VERSION 3.10)

# Project Name
project(
    PBR VERSION 0.0
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
find_package(OpenSubdiv REQUIRED)
find_package(GLEW REQUIRED)
find_package(TBB REQUIRED)
find_package(Boost REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_SOURCE_DIR}/cmake/macros")
include(Public)

# Compiler options
string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--no-undefined")
set(CMAKE_CXX_FLAGS_DEBUG "-DPBR_DEBUG")

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(thirdparty)
endif()

# Build targets.
add_subdirectory(pbr)
add_subdirectory(hdPbr)
