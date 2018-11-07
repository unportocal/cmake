
#https://github.com/ttroy50/cmake-examples/tree/master/01-basic/C-static-library#introduction
cmake_minimum_required(VERSION 3.5)
project (hello_cmakeHeaders)

#Add static library:
add_library(helloStaticLib STATIC src/salut.cpp)
#This will be used to create a static library with the name libhello_library.a? with the sources in the add_library call.

#Will include directories with the scope set to public
target_include_directories(helloStaticLib
    PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
    )
#For public headers it is often a good idea to have your include folder be "namespaced" with sub-directories

#Wn creating an exec that will use your library you must tell the compiler about the library. done using target_link_library()

add_executable(binaryStatLibDependent src/main.cpp)

target_link_libraries( binaryStatLibDependent
    PRIVATE
    helloStaticLib
    )
