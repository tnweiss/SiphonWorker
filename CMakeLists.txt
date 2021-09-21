####### Project Variables ##########
project(siphon)
cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )


####### OS Vars ##########
include(CMake/Linux.cmake)
include(CMake/Windows.cmake)


####### Python 3.8 headers ##########
find_package(PythonLibs 3.8 REQUIRED)


####### Dependencies ##########
link_directories(${DEP_LINK} ${PYTHON_LIBRARIES})
include_directories(${DEP_INCLUDE} ${PYTHON_INCLUDE_DIR})


########## Include the src subdirectory ##########
add_subdirectory(src)