########## SerDes proof of concept test ##########
add_executable(SerDesPOC
        main.cpp
        JSONSerDes.cpp
        BASESerDes.cpp
        FrameSerDes.cpp
        util.cpp
        PyJSON.cpp
        PartitionedFrame.cpp)

target_link_libraries( SerDesPOC PUBLIC ${PYTHON_LIBRARIES} ${LIB_BOOST_PYTHON})

target_precompile_headers(SerDesPOC
        PUBLIC ../../../../dependencies/include/boost/python.hpp
        PUBLIC ../../../../dependencies/include/nlohmann/json.hpp
        PUBLIC serdes_test_pch.h
        PUBLIC main_pch.h)