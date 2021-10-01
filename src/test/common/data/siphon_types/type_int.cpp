//
// Created by tyler on 9/29/21.
//
#include "catch2.hpp"

#include "frame/siphon/types/int_type.h"
#include "frame/data_type_arithmetic.h"


TEST_CASE( "TestIntField", "[common][data][data_model]" ) {
  std::unique_ptr<int> data = std::make_unique<int>(9);
  std::unique_ptr<DataType> st = std::make_unique<IntType>(data.get());

  std::unique_ptr<int> data2 = std::make_unique<int>(18);
  std::unique_ptr<DataType> st2 = std::make_unique<IntType>(data2.get());


  //auto t = (*st + *st + 9 / 7.9);
  //REQUIRE(t->as_int() == 18);
  //int y = 0;
//
//
//  REQUIRE(st2->as_int() == 18);
}