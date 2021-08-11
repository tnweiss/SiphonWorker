#include <iostream>

#include "json.hpp"
#include "filters/gt.h"
#include <string>

using nlohmann::json;

int main() {
    json data = json::parse(std::string("{\"hello\":\"world\"}"));
    GT gt(data);
    std::cout << "Hello Siphon" << std::endl;
}