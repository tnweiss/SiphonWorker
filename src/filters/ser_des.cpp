#include "pybind11_json.hpp"
#include "nlohmann/json.hpp"
#include "pybind11/pybind11.h"


pybind11::dict deserialize(nlohmann::json d) {
    nlohmann::json data = nlohmann::json::parse("{}");

    return d;
}