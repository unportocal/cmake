# https://github.com/ttroy50/cmake-examples/tree/master/05-unit-testing/google-test-download
cmake_minimum_required(VERSION 3.5)

# Set the project name
# project (google_test_example)
project (gTestExample)

# Add an library for the example classes
add_library(gTestExample
    src/Palin.cpp
    src/Reverso.cpp
)

# link header folder
target_include_directories (gTestExample
    PRIVATE
    ${PROJECT_SOURCE_DIR}/inc)

#############################################
# Unit tests

add_subdirectory(3rd_party/gTestDir)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unitTests src/unit_tests.cpp)

target_link_libraries(unitTests
    gTestExample
    GTest::GTest
    GTest::Main
    )

# link header folder
target_include_directories (unitTests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/inc)

add_test(test_all unitTests)
