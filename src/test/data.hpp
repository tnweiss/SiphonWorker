#include <string>
#include "json.hpp"

#ifndef SIPHON_TEST_DATA_H
#define SIPHON_TEST_DATA_H

std::string genericData1 = 
R"(
{
    "hello": "world",
    "instantiations": 3
}
)";


nlohmann::json getGenericData1() {
    return nlohmann::json::parse(genericData1);
}

std::string dataModelData =
        R"(
{
    "data_structure": "array",
    "fields": [
        {
            "field_name": "test",
            "field_type": "INTEGER",
            "description": "This is a general description"
        }
    ]
}
        )";

nlohmann::json getDataModelData() {
    return nlohmann::json::parse(dataModelData);
}


std::string dataModelFieldData =
        R"(
{
    "field_name": "test",
    "field_type": "STRING",
    "description": "This is a general description"
}
        )";

nlohmann::json getDataModelFieldData() {
    return nlohmann::json::parse(dataModelFieldData);
}

#endif
