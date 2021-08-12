ADD_LIBRARY( siphon_common
             filters/gt.cpp 
             filters/gt.h 
             filters/filter.h
             variables.cpp 
             variables.h
             exceptions/parse_exception.hpp)

target_include_directories(siphon_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")