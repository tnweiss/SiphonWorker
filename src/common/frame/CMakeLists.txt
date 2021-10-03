ADD_LIBRARY( siphon_frame STATIC
        data_type.cpp
        data_type_arithmetic.cpp

        siphon/exceptions.cpp
        siphon/siphon_frame_array.cpp

        siphon/types/int_type.cpp
        )

target_include_directories(siphon_frame PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
