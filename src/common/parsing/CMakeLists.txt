ADD_LIBRARY( siphon_parsing STATIC
        parameter_parse.cpp
        )

target_include_directories(siphon_parsing PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
