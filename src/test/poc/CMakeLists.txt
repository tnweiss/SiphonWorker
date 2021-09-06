add_executable(serdesPOC
        serdes/main.cpp
        serdes/serdes_test.h
        serdes/JSONSerdes.h
        serdes/JSONSerdes.tpp
        serdes/BASESerdes.cpp serdes/BASESerdes.h)

ADD_LIBRARY( t SHARED t.cpp)
target_link_libraries( t PRIVATE ${PYTHON_LIBRARIES} ${LIB_BOOST_PYTHON})

set_target_properties(t PROPERTIES PREFIX "")
set_target_properties(t PROPERTIES OUTPUT_NAME "t")
set_target_properties(t PROPERTIES SUFFIX ".pyd")


add_executable(m main.cpp)
message(${LIB_BOOST_PYTHON})
message(${PYTHON_LIBRARIES})
target_link_libraries( m PUBLIC ${PYTHON_LIBRARIES} ${LIB_BOOST_PYTHON})