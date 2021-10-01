add_executable(siphon_parsing_test

        main.cpp
        parameter_parse_tests.cpp
        )

target_precompile_headers(siphon_parsing_test PUBLIC data.hpp)

target_link_libraries(siphon_parsing_test PRIVATE siphon_parsing)
