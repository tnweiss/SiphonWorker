ADD_LIBRARY( siphon_data STATIC
        ####### Data Model #######
        data_model/fields/field_int.cpp
        data_model/fields/field_float.cpp

        data_model/fields/ser_des.h
        data_model/exceptions.cpp
        data_model/data_model.cpp
        data_model/data_model_field.cpp

        ####### Frame #######
        frame/data_type.cpp
        frame/data_type_arithmetic.cpp

        frame/siphon/exceptions.cpp
        frame/siphon/siphon_frame_array.cpp
        frame/siphon/types/int_type.cpp

        ####### Frame Set #######
        frame_set/frame_set.h

        )

target_include_directories(siphon_data PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
