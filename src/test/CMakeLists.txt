INCLUDE_DIRECTORIES(../../third_party/boost)

add_executable(commonTest common/filter_tests.cpp)
target_link_libraries(commonTest PRIVATE siphon_common)

