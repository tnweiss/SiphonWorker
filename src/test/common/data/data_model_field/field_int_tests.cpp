#include "catch2.hpp"

#include "data_model/field_int.h"

TEST_CASE( "TestIntField", "[common][data][data_model]" ) {
  ////////////// construct test in_data //////////////
  std::unique_ptr<int8_t> in_data = std::unique_ptr<int8_t>(new int8_t[int_constructor_data_size]);
  memcpy(in_data.get(), int_constructor_data, int_constructor_data_size);
  size_t offset = 0;

  ////////////// read from buffer //////////////
  std::unique_ptr<DataModelField> dmf =
        std::make_unique<IntField>(in_data.get(), offset);

  ////////////// check in_data //////////////
  REQUIRE(offset == (strlen(dmf->name()) + DMF_HEADER_LEN) + 1);
  REQUIRE(dmf->bytes() == sizeof(int));
  REQUIRE(dmf->code() == FIELD_INT_CODE);
  REQUIRE(strcmp(dmf->extended_code(), FIELD_INT_CODE_EXTENDED) == 0);
  REQUIRE(strcmp(dmf->name(), "test") == 0);

  ////////////// write to buffer //////////////
  std::unique_ptr<int8_t> out_data =
      std::unique_ptr<int8_t>(new int8_t[int_constructor_data_size]);
  size_t out_offset = 0;
  dmf->write_to_buffer(out_data.get(), out_offset);
  REQUIRE(memcmp(out_data.get(), in_data.get(), offset) == 0);
  REQUIRE(out_offset == offset);
}


TEST_CASE( "TestIntFieldNameConstructor", "[common][data][data_model]" ) {
  ////////////// read from buffer //////////////
  std::unique_ptr<DataModelField> dmf =
      std::make_unique<IntField>("test");

  ////////////// check in_data //////////////
  REQUIRE(dmf->bytes() == sizeof(int));
  REQUIRE(dmf->code() == FIELD_INT_CODE);
  REQUIRE(strcmp(dmf->extended_code(), FIELD_INT_CODE_EXTENDED) == 0);
  REQUIRE(strcmp(dmf->name(), "test") == 0);

  ////////////// write to buffer //////////////
  std::unique_ptr<int8_t> out_data =
      std::unique_ptr<int8_t>(new int8_t[int_constructor_data_size]);
  size_t out_offset = 0;
  dmf->write_to_buffer(out_data.get(), out_offset);
  REQUIRE(memcmp(out_data.get(), &int_constructor_data, DMF_HEADER_LEN) == 0);
}