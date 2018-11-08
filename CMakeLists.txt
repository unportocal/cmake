# https://github.com/ttroy50/cmake-examples/tree/master/01-basic/J-building-with-ninja
# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version

cmake_minimum_required(VERSION 2.8.8)

# Project Name:
project (HelloNinja)

# Add exec:
add_executable (HelloNinja src/noDepend.cpp)
