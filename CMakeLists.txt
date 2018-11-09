# https://github.com/ttroy50/cmake-examples/tree/master/03-code-generation/configure-files
# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version

cmake_minimum_required(VERSION 3.5.0)

# Set the project name
project(configExample)

# set a project version
set (cf_example_VERSION_MAJOR 5)
set (cf_example_VERSION_MINOR 2)
set (cf_example_VERSION_PATCH 21)
set (cf_example_VERSION "${cf_example_VERSION_MAJOR}.${cf_example_VERSION_MINOR}.${cf_example_VERSION_PATCH}")

# Call configure files on ver.h.in to set the version.
# Uses the standard ${VARIABLE} syntax in the file
configure_file (inc/cmakeIn/ver.h.in ${PROJECT_BINARY_DIR}/myVer.h)

# configure the path.h.in file.
# This file can only use the @VARIABLE@ syntax in the file
configure_file (inc/cmakeIn/path.h.in ${PROJECT_BINARY_DIR}/myPath.h @ONLY)

add_executable (configExample
    src/main.cpp)

#include directory with the new files
target_include_directories (configExample
    PUBLIC
    ${CMAKE_BINARY_DIR})
