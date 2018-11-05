cmake_minimum_required(VERSION 3.6.2)
project(directoryTest)
#Bring the headers into the project
include_directories(inc)

#Manually add the sources using set command
set(SOURCES src/mainapp.cpp src/student.cpp)

#However the file (GLOB...) Allows wildcard additions:
#file(GLOB SOURCES src/*.cpp) 

add_executable(testStudExec ${SOURCES})