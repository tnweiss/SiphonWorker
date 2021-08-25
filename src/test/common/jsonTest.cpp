#include "catch2.hpp"
#include <iostream>
#include "nlohmann/json.hpp"

TEST_CASE("DataModelConstructor", "[common]") {
    nlohmann::json test = nlohmann::json::parse(R"(
        {"hello": 1 }
    )");

    long int* t = new long(1L);
    long int* data = test["hello"].get_ptr<nlohmann::json::number_integer_t*>();
    std::cout << data << std::endl;
    std::cout << *data << std::endl;
    std::cout << &data << std::endl;

    std::cout << std::endl;

    &data = &t;

    std::cout << data << std::endl;
    std::cout << *data << std::endl;
    std::cout << &data << std::endl;



    delete t;
}