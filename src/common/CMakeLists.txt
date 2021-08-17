ADD_LIBRARY( siphon_common
             filters/gt.cpp 
             filters/gt.h 
             filters/filter.h
             variables.cpp 
             variables.h
             exceptions/parse_exception.hpp
             models/ParameterParse.h 
             models/ParameterParse.tpp)

ADD_LIBRARY( zoo SHARED zoo.cpp )
target_link_libraries( zoo boost_python38)

target_include_directories(siphon_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")