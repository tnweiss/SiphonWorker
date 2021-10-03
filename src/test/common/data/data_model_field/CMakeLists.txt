add_executable(dataModelFieldTest
        main.cpp

        field_int_tests.cpp
        common_lib.h
        field_data.hpp data_model_tests.cpp)

target_precompile_headers(dataModelFieldTest
        PUBLIC common_lib.h
        PUBLIC field_data.hpp)
target_link_libraries(dataModelFieldTest PUBLIC siphon_data_model)
