#include "catch2.hpp"

#include "models/ingest.h"
#include "siphon_strings.hpp"
#include "../data.hpp"

TEST_CASE( "DataModelFieldConstructor", "[common]" ) {
    nlohmann::json test_data = getDataModelFieldData();
    siphon::DataModelField dmf(test_data);

    REQUIRE(dmf.name().compare("test") == 0);
    REQUIRE(dmf.description().compare("This is a general description") == 0);
    REQUIRE(dmf.type() == siphon::SiphonType::STRING);
}


TEST_CASE("DataModelConstructor", "[common]") {
    nlohmann::json test_data = getDataModelData();
    siphon::DataModel dm(test_data);

    REQUIRE(dm.fields().size() == 1);
    REQUIRE(dm.dataStructure() == siphon::DataStructure::array);
}