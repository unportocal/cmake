# first we add the executables to generate the tables
add_executable(MakeSquareTable BuildMathTable.cxx)

# add the command to generate source code:
add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	COMMAND MakeSquareTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	DEPENDS MakeSquareTable
	)
	
# add the binary tree directory to the search path for
# include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

# add the main library 
add_library (mathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install (TARGETS mathFunctions/mathFunctions.hpp DESTINATION bin)
install (FILES mathFunctions.hpp DESTINATION include)