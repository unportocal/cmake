cmake_minimum_required (VERSION 2.6)
project (Tutorial)
#add_executable (Tutorial tutor.cxx)
#The version number.

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 001)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/inc/TutorialConfig.hpp.in"
  "${PROJECT_BINARY_DIR}/inc/TutorialConfig.hpp"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.hpp
include_directories("${PROJECT_BINARY_DIR}")

#Add executable
add_executable(Tutorial src/tutor.cxx)
