
# https://github.com/ttroy50/cmake-examples/tree/master/01-basic/H-third-party-library
# Using third party libraries.
# exported variables:
#	XXX_FOUND
#	xxx_INCLUDE_DIRS - pointing to the include directory of the lib
#	xxx_LIBRARY - A variable pointing to the library path.
cmake_minimum_required(VERSION 3.5)

find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# Do stuff if Lib pack was found:
if (Boost_FOUND)
	message ("boost Lib found")
	include_directories ($Boost_INCLUDE_DIRS)
else()
	message (FATAL_ERROR "Cannot find boost Lib")
endif()

# Add exec
add_executable (thirdPartyIncludeExec src/boostDepend.cpp)

target_link_libraries (thirdPartyIncludeExec
	PRIVATE
	Boost::filesystem)

# Include boost Headers
target_include_directories (thirdPartyIncludeExec
	PRIVATE
	${Boost_INCLUDE_DIRS})

# lINK against boost lib:
target_link_libraries (thirdPartyIncludeExec
	PRIVATE
	${Boost_SYSTEM_LIBRARY}
	${Boost_FILESYSTEM_LIBRARY})
