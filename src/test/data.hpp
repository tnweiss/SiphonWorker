#include <string>
#include "nlohmann/json.hpp"

#ifndef SIPHON_TEST_DATA_H
#define SIPHON_TEST_DATA_H

static nlohmann::json genericData1() {
  return R"(
    {
        "stringField": "Hello World",
        "intField": 3,
        "floatField": 3.101,
        "boolField": true,
        "unsignedIntField": 100,
        "enumField": "TEST_PASS",
        "arrayField": ["hello", "world"],
        "varField": "$.6"
    }
    )"_json;
}


enum TEST_ENUM {
    TEST_PASS = 1,
    TEST_FAIL = 2
};


static nlohmann::json dataModelData() {
  return R"(
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
}


static nlohmann::json dataModelFieldData() {
  return R"(
    {
        "field_name": "test",
        "field_type": "STRING",
        "description": "This is a general description"
    }
  )"_json;
}


#endif
