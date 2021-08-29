#include "catch2.hpp"

#include "siphon_strings.hpp"
#include "../data.hpp"
#include "models/data_model_field.h"
#include "models/data_model.h"

TEST_CASE( "TESTDataModelField", "[common]" ) {
  const nlohmann::json data = dataModelFieldData();
  siphon::DataModelField dmf(data);

  REQUIRE(dmf.name() == "test");
  REQUIRE(dmf.description() == "This is a general description");
  REQUIRE(dmf.type() == siphon::SiphonType::STRING);
}

TEST_CASE("DataModelConstructor", "[common]") {
    nlohmann::json test_data = dataModelData();
    siphon::DataModel dm(test_data);

    REQUIRE(dm.fields()->size() == 1);
    REQUIRE(dm.dataStructure() == siphon::DataStructure::array);
}