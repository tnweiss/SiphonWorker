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
link_directories(dependencies/lib ${PYTHON_LIBRARIES})
include_directories(dependencies/include ${PYTHON_INCLUDE_DIR})


####### Boost Compilation ##########
add_compile_definitions(BOOST_ALL_NO_LIB )  # disables auto linking
add_compile_definitions(BOOST_PYTHON_STATIC_LIB  )  # tells boost we are statically linking


########## Include the src subdirectory ##########
add_subdirectory(src)