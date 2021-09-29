ADD_LIBRARY( siphon_data
        ####### Data Model #######
        data_model/ser_des.h
        data_model/exceptions.cpp
        data_model/data_model.cpp
        data_model/data_model_field.cpp
        data_model/field_float.cpp
        data_model/field_int.cpp

        ####### Deserializers #######
        deserializer/deserializer.h
        deserializer/data_model_des.cpp

        ####### Frames #######
        frame/frame.h

        ####### Readers #######
        reader/reader.h

        ####### Serializers #######
        serializer/serializer.h

        ####### Writers #######
        writer/writer.h
        )

target_include_directories(siphon_data PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
