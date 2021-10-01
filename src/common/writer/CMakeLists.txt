ADD_LIBRARY( siphon_writer

        writer.h
        )

target_include_directories(siphon_writer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(siphon_writer PROPERTIES LINKER_LANGUAGE CXX)
