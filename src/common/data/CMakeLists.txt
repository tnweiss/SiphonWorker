ADD_LIBRARY( siphon_data
        ####### Data Model #######
        data_model/fields/field_int.cpp
        data_model/fields/field_float.cpp

        data_model/fields/ser_des.h
        data_model/exceptions.cpp
        data_model/data_model.cpp
        data_model/data_model_field.cpp

        ####### Deserializers #######
        deserializer/deserializer.h
        deserializer/data_model_des.cpp

        ####### Frames #######
        frame/data_type.cpp
        frame/data_type_arithmetic.cpp

        frame/siphon/exceptions.cpp
        frame/siphon/siphon_frame_array.cpp
        frame/siphon/types/int_type.cpp

        ####### Readers #######
        reader/reader.h

        ####### Serializers #######
        serializer/serializer.h

        ####### Writers #######
        writer/writer.h
        )

target_include_directories(siphon_data PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
