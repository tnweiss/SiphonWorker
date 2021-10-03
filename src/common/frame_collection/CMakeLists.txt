ADD_LIBRARY( siphon_frame_collection STATIC

        ####### Frame Set #######
        frame_collection.h

        siphon_frame_collection.cpp siphon_frame_collection.h frame_collection.cpp)

target_include_directories(siphon_frame_collection PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
