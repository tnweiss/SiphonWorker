if (UNIX)
    ####### Dependency Directories ##########
    set(DEP_INCLUDE dependencies/include)
    set(DEP_LINK dependencies/lib)


    set(LIB_BOOST_SERIALIZATION boost_serialization)
    set(LIB_BOOST_PYTHON boost_python38)


    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wno-deprecated-declarations")
endif()