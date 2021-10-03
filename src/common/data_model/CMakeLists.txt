ADD_LIBRARY( siphon_data_model STATIC
        ####### Data Model #######
        data_model.cpp
        data_model_field.cpp
        exceptions.cpp

        fields/field_float.cpp
        fields/field_int.cpp
        )

target_include_directories(siphon_data_model PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
