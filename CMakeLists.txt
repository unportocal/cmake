cmake_minimum_required(VERSION 3.6.2)
project(directoryTest)
set(CMAKE_BUILD_TYPE RELEASE)

#Bring the headers into the project
include_directories(inc)

#Manually add the sources using set command
#set(SOURCES src/mainapp.cpp src/student.cpp)

#However the file (GLOB...) Allows wildcard additions:
file(GLOB SOURCES src/*.cpp) 

#Generate shared LIB from sources
add_library(testStudSharedLib SHARED ${SOURCES})

#Set location for lib installation - i.e. usr/lib for our example
#Use sudo make install to apply
install (TARGETS testStudSharedLib DESTINATION /usr/lib)