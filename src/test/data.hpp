#include <string>
#include "nlohmann/json.hpp"

#ifndef SIPHON_TEST_DATA_H
#define SIPHON_TEST_DATA_H

const nlohmann::json genericData1 =
R"(
{
    "stringField": "Hello World",
    "intField": 3,
    "floatField": 3.101,
    "boolField": true,
    "unsignedIntField": 100,
    "enumField": "TEST_PASS",
    "arrayField": ["hello", "world"]
}
)"_json;


enum TEST_ENUM {
    TEST_PASS = 1,
    TEST_FAIL = 2
};


const nlohmann::json dataModelData =
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
        )"_json;


nlohmann::json dataModelFieldData =
        R"(
{
    "field_name": "test",
    "field_type": "STRING",
    "description": "This is a general description"
}
        )"_json;

#endif
