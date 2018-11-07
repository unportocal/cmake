
# https://github.com/ttroy50/cmake-examples/tree/master/01-basic/G-compile-flags
#	CMake supports setting compile flags in a number of different ways:
#	using target_compile_definitions() function using the CMAKE_C_FLAGS and CMAKE_CXX_FLAGS variables.

cmake_minimum_required(VERSION 3.5)

# Set a default C++ compile flag
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compiler Flags" FORCE)

# Set the project name
project (compile_flags)

# Add an executable
add_executable(cmake_examples_compile_flags src/noDepend.cpp)

target_compile_definitions(cmake_examples_compile_flags
    PRIVATE EX3
	)
