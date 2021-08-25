#include <string>
#include <vector>
#include "nlohmann/json.hpp"
#include "boost/any.hpp"
#include "catch2.hpp"

#include "../data.hpp"
#include "parsing/parse_exception.hpp"
#include "parsing/parameter_parse.h"


TEST_CASE( "TestValidateType", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_type<std::string>(genericData1, "stringField");
    siphon::validate_type<int>(genericData1, "intField");
    siphon::validate_type<float>(genericData1, "floatField");
    siphon::validate_type<bool>(genericData1, "boolField");
    siphon::validate_type<unsigned int>(genericData1, "unsignedIntField");

    REQUIRE_THROWS_AS(siphon::validate_type<std::string>(genericData1, "intField"),
            siphon::InvalidTypeParseException);
}

TEST_CASE( "TestValidateTypeSL", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_type<std::string>(genericData1["stringField"], "stringField", "notThere");
    siphon::validate_type<int>(genericData1["intField"], "notThere", "intField");
    siphon::validate_type<float>(genericData1["floatField"], "floatField", "notThere");
    siphon::validate_type<bool>(genericData1["boolField"], "notThere", "boolField");
    siphon::validate_type<unsigned int>(genericData1["unsignedIntField"], "unsignedIntField", "notThere");

    REQUIRE_THROWS_AS(siphon::validate_type<std::string>(genericData1["intField"], "intField", "notThere"),
                      siphon::InvalidTypeParseException);
}

TEST_CASE( "TestValidateExists", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_exists(genericData1, "intField");

    REQUIRE_THROWS_AS(siphon::validate_exists(genericData1, "notThere"),
                      siphon::KeyNotFoundParseException);
}

TEST_CASE( "TestValidateExistsSL", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_exists(genericData1, "intField", "notThere");

    REQUIRE_THROWS_AS(siphon::validate_exists(genericData1, "notThere"),
                      siphon::KeyNotFoundParseException);
}

TEST_CASE( "TestParameterParse", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParse<int>(genericData1, "intField") == 3);
    REQUIRE(siphon::parameterParse<std::string>(genericData1, "stringField") == "Hello World");
    REQUIRE(siphon::parameterParse<float>(genericData1, "floatField") == 3.101f);
    REQUIRE(siphon::parameterParse<unsigned int>(genericData1, "unsignedIntField") == 100u);
    REQUIRE(siphon::parameterParse<bool>(genericData1, "boolField") == true);
}

TEST_CASE( "TestParameterParseDefault", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParse<int>(genericData1, "intFieldN", 5) == 5);
    REQUIRE(siphon::parameterParse<std::string>(genericData1, "stringFieldN", "Hi") == "Hi");
    REQUIRE(siphon::parameterParse<float>(genericData1, "floatFieldN", 5.12f) == 5.12f);
    REQUIRE(siphon::parameterParse<unsigned int>(genericData1, "unsignedIntFieldN", 2) == 2u);
    REQUIRE(siphon::parameterParse<bool>(genericData1, "boolFieldN", false) == false);
}

TEST_CASE( "TestParameterParseEnum", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParseEnum<TEST_ENUM>(genericData1, "enumField") == TEST_ENUM::TEST_PASS);
}

TEST_CASE( "TestParameterParseEnumDefault", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParseEnum<TEST_ENUM>(genericData1, "enumFieldN", TEST_ENUM::TEST_FAIL) ==
            TEST_ENUM::TEST_FAIL);
}

TEST_CASE( "TestParameterParseArray", "[common][parameterParse]" ) {
    std::unique_ptr<std::vector<std::string>> d = siphon::parameterParseArray<std::string>(genericData1,
                                                                                           "arrayField");

    REQUIRE(d->size() == 2);
    REQUIRE(d->at(0) == "hello");
    REQUIRE(d->at(1) == "world");
}

TEST_CASE( "TestParameterParseArrayDefault", "[common][parameterParse]" ) {
    auto* defaultData = new std::vector<std::string>({"1"});
    std::unique_ptr<std::vector<std::string>> d = siphon::parameterParseArray<std::string>(genericData1,
                                                                                           "arrayFieldN",
                                                                                           *defaultData);

    REQUIRE(d->size() == 1);
    REQUIRE(d->at(0) == "1");
}

//
//TEST_CASE( "TestParameterParseRequiredException", "[parameterParse]" ) {
//    nlohmann::json data = getGenericData1();
//
//    REQUIRE_THROWS(siphon::parameterParse<std::string>(data, "doesNotExist"));
//}
//
//
//TEST_CASE( "TestParameterParseWrongTypeException", "[parameterParse]" ) {
//    nlohmann::json data = getGenericData1();
//
//    REQUIRE_THROWS_AS(siphon::parameterParse<int>(data, "hello"), siphon::InvalidTypeParseException);
//}
//
//TEST_CASE( "TestParameterParseNotRequiredNotExists", "[parameterParse]" ) {
//    nlohmann::json data = getGenericData1();
//
//    std::string doesNotExistValue = siphon::parameterParse<std::string>(data, "doesNotExist", "nowItDoes");
//    REQUIRE(doesNotExistValue.compare("nowItDoes") == 0);
//}