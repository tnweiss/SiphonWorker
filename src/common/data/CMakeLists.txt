ADD_LIBRARY( siphon_data
        ####### Deserializers #######
        deserializer/deserializer.h

        ####### Frames #######
        frame/frame.h

        ####### Readers #######
        reader/reader.h

        ####### Serializers #######
        serializer/serializer.h

        ####### Writers #######
        writer/writer.h


        )

####### Temporary #######
set_target_properties(siphon_data PROPERTIES LINKER_LANGUAGE CXX)
