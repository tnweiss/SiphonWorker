#include <string>
#include "json.hpp"

#ifndef DATA_H
#define DATA_H
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
#endif
