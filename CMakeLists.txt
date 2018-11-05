cmake_minimum_required(VERSION 3.6.2)
project(TestSharedLib)
#set(CMAKE_BUILD_TYPE RELEASE)

#for the shared lib:
set (PROJECT_LINK_LIBS libTestStudent.dll )	# or so?
link_directories(/build)

#for the static library:
#set (PROJECT_LINK_LIBS libTestStudent.so )	# or dll?

include_directories(/inc)

add_executable(libtest src/mainapp.cpp)
target_link_libraries(libtest ${PROJECT_LINK_LIBS})