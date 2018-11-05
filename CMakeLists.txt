#http://derekmolloy.ie/hello-world-introductions-to-cmake/

cmake_minimum_required(VERSION 3.6.2)
project(StaticLib)
set(CMAKE_BUILD_TYPE RELEASE)

#Bring the headers into the project
include_directories(inc)

#Manually add the sources using set command this being a library, it does not include the main file
set(SOURCES src/student.cpp)

#However the file (GLOB...) Allows wildcard additions. 
#file(GLOB SOURCES src/*.cpp) 

#Generate shared LIB from sources
add_library(testStudStaticLib STATIC ${SOURCES})

#Set location for lib installation - i.e. usr/lib for our example
#Use sudo make install to apply
install (TARGETS testStudStaticLib DESTINATION /usr/lib)