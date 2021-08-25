#INCLUDE_DIRECTORIES(../../third_party/boost)

#add_executable(commonTest
#    common/main.cpp
#    common/filter_tests.cpp
#    common/parameter_parse_tests.cpp
#    data.hpp)
#target_link_libraries(commonTest PRIVATE siphon_common ${PYTHON_LIBRARIES})


add_executable(commonTest
        common/main.cpp
        data.hpp
        common/models_tests.cpp
    )
target_link_libraries(commonTest PRIVATE siphon_common ${PYTHON_LIBRARIES})

add_executable(jsonTest
        common/main.cpp
        common/jsonTest.cpp
    )
