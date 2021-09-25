add_executable(commonTest
        main.cpp
        parameter_parse_tests.cpp
        models_tests.cpp)

target_precompile_headers(commonTest PUBLIC ../data.hpp)

target_link_libraries(commonTest PRIVATE siphon_common ${LIB_BOOST_PYTHON} ${LIB_BOOST_SERIALIZATION})
