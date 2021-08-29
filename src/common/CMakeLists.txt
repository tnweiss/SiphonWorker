ADD_LIBRARY( siphon_common
        siphon_strings.hpp

        parsing/parse_exception.hpp
        parsing/parameter_parse.h
        parsing/parameter_parse.tpp
        parsing/parameter_parse.cpp

        models/data_model_field.h
        models/data_model_field.cpp
        models/data_model.h
        models/data_model.cpp
        )

target_include_directories(siphon_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
