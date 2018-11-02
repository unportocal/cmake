# this tutorial is done from: https://cmake.org/cmake-tutorial/
# run ctest cmd to run some tests after you built the target

cmake_minimum_required (VERSION 2.8.4)
project (Tutorial)
#add_executable (Tutorial tutor.cxx)
#The version number:

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 002)

# should we use our own math functions?
option (USE_MYMATH 
        "Use tutorial provided math implementation" ON) 

# does this system provide the log and exp functions?
#include (CheckFunctionExists)
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)

check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)
		
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/inc/TutorialConfig.hpp.in"
  "${PROJECT_BINARY_DIR}/inc/TutorialConfig.hpp"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.hpp
include_directories("${PROJECT_BINARY_DIR}")
if (USE_MYMATH)  # Should we add the MathFunctions library?
	include_directories("${PROJECT_SOURCE_DIR}/mathFunctions")
	add_subdirectory (mathFunctions)
	set (EXTRA_LIBS ${EXTRA_LIBS} mathFunctions)
endif(USE_MYMATH)

#Add executable
add_executable(Tutorial src/tutor.cxx)

#Link other libraries
target_link_libraries (Tutorial ${EXTRA_LIBS})

#add install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/inc/TutorialConfig.hpp"
		DESTINATION include)
		
#Running some tests cmake
include (CTest)

#define a macro to simplify adding tests, then use it
macro (do_test arg result)
  add_test (TutorialComp${arg} Tutorial ${arg})
  set_tests_properties (TutorialComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

#does the app run ok?
add_test (TutorialRuns Tutorial 25)
# does it sqrt?
add_test (TutorialComp10 Tutorial 100)
set_tests_properties (TutorialComp10 PROPERTIES PASS_REGULAR_EXPRESSION "100 is 10")
# does it handle negative No's?
add_test (TutorialNegative Tutorial -25)
set_tests_properties (TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is -1")
# does it handle small numbers
add_test (TutorialSmall Tutorial 0.0001)
set_tests_properties (TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
# does the usage message work?
add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")
# do a bunch of result based tests
do_test (25 "25 is 5")
do_test (225 "225 is 15")
do_test (111 "111 is 10.5333")


