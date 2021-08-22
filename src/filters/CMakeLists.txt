ADD_LIBRARY( siphon_filters SHARED
            serdes.cpp
             filter.hpp)

#target_include_directories(siphon_filters PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")