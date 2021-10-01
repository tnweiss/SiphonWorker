ADD_LIBRARY( siphon_reader

        reader.h
        )

target_include_directories(siphon_reader PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(siphon_reader PROPERTIES LINKER_LANGUAGE CXX)
