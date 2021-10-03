ADD_LIBRARY( siphon_processing

        processor.h

        processing_error_formatter.h
        processing_error_formatter/plaintext_error_formatter.cpp)

target_include_directories(siphon_processing PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(siphon_processing PUBLIC siphon_data siphon_frame)
set_target_properties(siphon_processing PROPERTIES LINKER_LANGUAGE CXX)