####### Project Variables ##########
project(siphon)
cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

#
#
#message("\n\n\n\nHUH\n\n\n\n")
#if (WIN32)
#    message("\n\n\n\nWTF\n\n\n\n")
#    # disable autolinking in boost
#    add_definitions( -DBOOST_ALL_NO_LIB )
#
#    # force all boost libraries to dynamic link (we already disabled
#    # autolinking, so I don't know why we need this, but we do!)
#    add_definitions( -DBOOST_ALL_DYN_LINK )
#endif()

####### Python 3.8 headers ##########
find_package(PythonLibs 3.8 REQUIRED)


####### Dependencies ##########
link_directories(C:\\Users\\Tyler\\OneDrive\\Desktop\\workspace\\SiphonDB\\SiphonWorkerDependencies\\.build\\boost_1_71_0\\stage\\lib ${PYTHON_LIBRARIES})
include_directories(C:\\Users\\Tyler\\OneDrive\\Desktop\\workspace\\SiphonDB\\SiphonWorkerDependencies\\.build\\boost_1_71_0 ${PYTHON_INCLUDE_DIR} dependencies/include)


####### Boost Libraries ##########
set (LIBRARY_PREFIX )
set (LIBRARY_SUFFIX )
if (MSVC)
    set (LIBRARY_PREFIX lib)
    set (LIBRARY_SUFFIX -vc142-mt-gd-x64-1_71)
endif (MSVC)

if (WIN32)
    # Prefix all shared libraries with 'lib'.
    set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
    # Prefix all static libraries with 'lib'.
    set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
endif()

set(LIB_BOOST_SERIALIZATION ${LIBRARY_PREFIX}boost_serialization${LIBRARY_SUFFIX})
set(LIB_BOOST_PYTHON ${LIBRARY_PREFIX}boost_python38${LIBRARY_SUFFIX})

########## Include the src subdirectory ##########
add_subdirectory(src)