
# https://github.com/ttroy50/cmake-examples/tree/master/01-basic/E-installing#introduction
# This example shows how to generate a make install target to install files and binaries on your system.
# he base install location is controlled by the variable CMAKE_INSTALL_PREFIX which can be set using ccmake
# or by calling cmake with cmake .. -DCMAKE_INSTALL_PREFIX=/install/location

cmake_minimum_required(VERSION 3.5)
project (helloCmakeInstall)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	message (STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/makeInstall")
	set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/makeInstall" CACHE STRING "The path to use for make install" FORCE)
endif()

############################################################
# Create a library
############################################################

add_library (sharedLibInstall
    SHARED
    src/salut.cpp)
# this will create a shared lib with libLibName.so

add_library(hello::sharedLibInstAlias ALIAS sharedLibInstall)
# this will create an alias that can be used in read-only context

target_include_directories (sharedLibInstall
	PUBLIC
	${PROJECT_SOURCE_DIR}/inc)

############################################################
# Create an executable
############################################################

add_executable (execInstallBin
	src/main.cpp)

target_link_libraries (execInstallBin
	PRIVATE
	hello::sharedLibInstAlias)

############################################################
# Create an installation
############################################################

# Binaries
install (TARGETS execInstallBin
	DESTINATION bin)

# Library. Doesn't work on windows
install (TARGETS sharedLibInstall
    LIBRARY DESTINATION lib)

# Header files
install (DIRECTORY ${PROJECT_SOURCE_DIR/inc/}
	DESTINATION inc)

# Install the header files for developing against the cmake_examples_inst library into the ${CMAKE_INSTALL_PREFIX}/include directory.
# Config
install (FILES cmake-example.conf
	DESTINATION etc)
