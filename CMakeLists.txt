project(PID)

set(sources src/main.cpp src/filters/gt.cpp)

cmake_minimum_required (VERSION 3.5)
add_definitions(-std=c++11)

file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp ../src/json.hpp)

add_executable(test ${sources})