cmake_minimum_required(VERSION 3.5)

# Set the project name
project (gTestEx)

# Add an library for the example classes
add_library(gTestEx
    Addition.cpp
    Multiply.cpp
)

# link header folder
target_include_directories (gTestEx
    PRIVATE
    ${PROJECT_SOURCE_DIR})

#############################################
# Unit tests

add_subdirectory(gTestDir)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(testOperations unitTest.cpp)

target_link_libraries(testOperations
    gTestExample
    GTest::GTest
    GTest::Main
    )

# link header folder
target_include_directories (testOperations
    PRIVATE
    ${PROJECT_SOURCE_DIR})

add_test(test_all testOperations)
