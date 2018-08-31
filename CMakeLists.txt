# this tutorial is done from: https://cmake.org/cmake-tutorial/
cmake_minimum_required (VERSION 2.6)
project (Tutorial)
#add_executable (Tutorial tutor.cxx)
#The version number.

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 001)

# should we use our own math functions?
option (USE_MYMATH 
        "Use tutorial provided math implementation" ON) 

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

#add subdir_depends


#Add executable
add_executable(Tutorial src/tutor.cxx)

#Link other libraries
tarket_link_libraries (Tutorial ${EXTRA_LIBS})

