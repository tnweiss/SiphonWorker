####### Project Variables ##########
project(siphon)
cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )


####### Python 3.8 headers ##########
find_package(PythonLibs 3.8 REQUIRED)


####### Dependencies ##########
link_directories(dependencies/lib)
include_directories(dependencies/include ${PYTHON_INCLUDE_DIRS})


####### Boost Libraries ##########
set (LIBRARY_PREFIX )
set (LIBRARY_SUFFIX )
if (MSVC)
    set (LIBRARY_PREFIX lib)
    set (LIBRARY_SUFFIX -vc142-mt-x64-1_71)
endif (MSVC)

set(LIB_BOOST_SERIALIZATION ${LIBRARY_PREFIX}boost_serialization${LIBRARY_SUFFIX})


########## Include the src subdirectory ##########
add_subdirectory(src)