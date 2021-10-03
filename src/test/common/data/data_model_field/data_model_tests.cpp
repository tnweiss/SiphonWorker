//
// Created by Tyler on 9/28/2021.
//
#include "catch2.hpp"

#include "data_model.h"

TEST_CASE( "DataModelTest", "[common][data][data_model]" ) {
  ////////////// construct test in_data //////////////
  std::unique_ptr<int8_t> in_data = std::unique_ptr<int8_t>(new int8_t[dm_constructor_data_size]);
  memcpy(in_data.get(), dm_constructor_data, dm_constructor_data_size);

  ////////////// read from buffer //////////////
  std::unique_ptr<DataModel> dm =
      std::make_unique<DataModel>(in_data.get());

  REQUIRE(dm->model_type() == DATA_MODEL_CODE_ARRAY);
  REQUIRE(strcmp(dm->model_type_extended(),
                 DATA_MODEL_CODE_EXTENDED_ARRAY) == 0);
}
