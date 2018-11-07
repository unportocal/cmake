
#https://github.com/ttroy50/cmake-examples/tree/master/01-basic/D-shared-library#introduction
cmake_minimum_required(VERSION 3.5)
project (hello_cmakeHeaders)

add_library (sharedLib
    SHARED
    src/salut.cpp)
#this will create a shared lib with libLibName.so

add_library(hello::sharedLibAlias ALIAS sharedLib)
# this will create an alias that can be used in read-only context

target_include_directories (sharedLib
	PUBLIC
	${PROJECT_SOURCE_DIR}/inc)

add_executable (helloExec
	src/main.cpp)

target_link_libraries (helloExec
	PRIVATE
	hello::sharedLibAlias)
