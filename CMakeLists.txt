
#https://github.com/ttroy50/cmake-examples/tree/master/01-basic/B-hello-headers
cmake_minimum_required(VERSION 3.5)
project (hello_cmakeHeaders)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES src/main.cpp src/salut.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    )
