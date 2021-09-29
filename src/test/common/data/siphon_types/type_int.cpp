//
// Created by tyler on 9/29/21.
//
#include "catch2.hpp"

#include "frame/siphon/types/int_type.h"


TEST_CASE( "TestIntField", "[common][data][data_model]" ) {
  std::unique_ptr<int> data = std::make_unique<int>(9);
  std::unique_ptr<SiphonType> st = std::make_unique<IntType>(data.get());

  std::unique_ptr<int> data2 = std::make_unique<int>(18);
  std::unique_ptr<SiphonType> st2 = std::make_unique<IntType>(data2.get());

  *st = *st2;

  REQUIRE(st->as_int() == 18);
}