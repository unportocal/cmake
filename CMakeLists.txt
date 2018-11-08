
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
	message ($Boost_INCLUDE_DIRS)
	message ($Boost_SYSTEM_LIBRARY)
	message ($Boost_FILESYSTEM_LIBRARY)
	message ($Boost_LIBRARY)
	include_directories ($Boost_INCLUDE_DIRS)
else()
	message (FATAL_ERROR "Cannot find boost Lib")
endif()

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

print_all_variables()

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
