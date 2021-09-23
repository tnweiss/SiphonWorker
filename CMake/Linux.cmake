if (UNIX)
    ####### Boost Libraries ##########
    set(LIB_BOOST_SERIALIZATION boost_serialization)
    set(LIB_BOOST_PYTHON boost_python38)


    ####### Thread libraries ##########
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wno-deprecated-declarations")
endif()