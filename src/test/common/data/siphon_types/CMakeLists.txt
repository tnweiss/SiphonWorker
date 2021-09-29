add_executable(siphonTypesTest
        main.cpp

        type_int.cpp
        )

target_precompile_headers(siphonTypesTest
        PUBLIC common.h
        PUBLIC data.hpp)

target_link_libraries(siphonTypesTest PRIVATE siphon_data)
