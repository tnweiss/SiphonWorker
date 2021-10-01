#include <string>
#include <vector>
#include "catch2.hpp"

#include "data.hpp"
#include "parse_exception.hpp"
#include "parameter_parse.h"


TEST_CASE( "TestValidateType", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_type<std::string>(genericData1(), "stringField");
    siphon::validate_type<int>(genericData1(), "intField");
    siphon::validate_type<float>(genericData1(), "floatField");
    siphon::validate_type<bool>(genericData1(), "boolField");
    siphon::validate_type<unsigned int>(genericData1(), "unsignedIntField");

    REQUIRE_THROWS_AS(siphon::validate_type<std::string>(genericData1(), "intField"),
            siphon::InvalidTypeParseException);
}

TEST_CASE( "TestValidateTypeSL", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_type<std::string>(genericData1()["stringField"], "stringField", "notThere");
    siphon::validate_type<int>(genericData1()["intField"], "notThere", "intField");
    siphon::validate_type<float>(genericData1()["floatField"], "floatField", "notThere");
    siphon::validate_type<bool>(genericData1()["boolField"], "notThere", "boolField");
    siphon::validate_type<unsigned int>(genericData1()["unsignedIntField"], "unsignedIntField", "notThere");

    REQUIRE_THROWS_AS(siphon::validate_type<std::string>(genericData1()["intField"], "intField", "notThere"),
                      siphon::InvalidTypeParseException);
}

TEST_CASE( "TestValidateExists", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_exists(genericData1(), "intField");

    REQUIRE_THROWS_AS(siphon::validate_exists(genericData1(), "notThere"),
                      siphon::KeyNotFoundParseException);
}

TEST_CASE( "TestValidateExistsSL", "[common][parameterParse]" ) {
    // ensure no exceptions are thrown
    siphon::validate_exists(genericData1(), "intField", "notThere");

    REQUIRE_THROWS_AS(siphon::validate_exists(genericData1(), "notThere"),
                      siphon::KeyNotFoundParseException);
}

TEST_CASE( "TestParameterParse", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParse<int>(genericData1(), "intField") == 3);
    REQUIRE(siphon::parameterParse<std::string>(genericData1(), "stringField") == "Hello World");
    REQUIRE(siphon::parameterParse<float>(genericData1(), "floatField") == 3.101f);
    REQUIRE(siphon::parameterParse<unsigned int>(genericData1(), "unsignedIntField") == 100u);
    REQUIRE(siphon::parameterParse<bool>(genericData1(), "boolField") == true);
}

TEST_CASE( "TestParameterParseDefault", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParse<int>(genericData1(), "intFieldN", 5) == 5);
    REQUIRE(siphon::parameterParse<std::string>(genericData1(), "stringFieldN", "Hi") == "Hi");
    REQUIRE(siphon::parameterParse<float>(genericData1(), "floatFieldN", 5.12f) == 5.12f);
    REQUIRE(siphon::parameterParse<unsigned int>(genericData1(), "unsignedIntFieldN", 2) == 2u);
    REQUIRE(siphon::parameterParse<bool>(genericData1(), "boolFieldN", false) == false);
}

TEST_CASE( "TestParameterParseEnum", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParseEnum<TEST_ENUM>(genericData1(), "enumField") == TEST_ENUM::TEST_PASS);
}

TEST_CASE( "TestParameterParseEnumDefault", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParseEnum<TEST_ENUM>(genericData1(), "enumFieldN", TEST_ENUM::TEST_FAIL) ==
            TEST_ENUM::TEST_FAIL);
}

TEST_CASE( "TestParameterParseArray", "[common][parameterParse]" ) {
    std::unique_ptr<std::vector<std::string>> d = siphon::parameterParseArray<std::string>(genericData1(),
                                                                                           "arrayField");

    REQUIRE(d->size() == 2);
    REQUIRE(d->at(0) == "hello");
    REQUIRE(d->at(1) == "world");
}

TEST_CASE( "TestParameterParseArrayDefault", "[common][parameterParse]" ) {
    auto* defaultData = new std::vector<std::string>({"1"});
    std::unique_ptr<std::vector<std::string>> d = siphon::parameterParseArray<std::string>(genericData1(),
                                                                                           "arrayFieldN",
                                                                                           *defaultData);

    REQUIRE(d->size() == 1);
    REQUIRE(d->at(0) == "1");
}


TEST_CASE( "TestParameterParseSL", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParseSL<int>(genericData1(), "intField", "notThere") == 3);
    REQUIRE(siphon::parameterParseSL<std::string>(genericData1(), "notThere", "stringField") == "Hello World");
    REQUIRE(siphon::parameterParseSL<float>(genericData1(), "floatField", "notThere") == 3.101f);
    REQUIRE(siphon::parameterParseSL<unsigned int>(genericData1(), "notThere", "unsignedIntField") == 100u);
    REQUIRE(siphon::parameterParseSL<bool>(genericData1(), "boolField", "notThere") == true);
}

TEST_CASE( "TestParameterParseSLDefault", "[common][parameterParse]" ) {
    REQUIRE(siphon::parameterParseSL<int>(genericData1(), "intFieldN", "notThere", 5) == 5);
    REQUIRE(siphon::parameterParseSL<std::string>(genericData1(), "notThere", "stringFieldN", "Hi") == "Hi");
    REQUIRE(siphon::parameterParseSL<float>(genericData1(), "floatFieldN", "notThere", 5.12f) == 5.12f);
    REQUIRE(siphon::parameterParseSL<unsigned int>(genericData1(), "notThere", "unsignedIntFieldN", 2) == 2u);
    REQUIRE(siphon::parameterParseSL<bool>(genericData1(), "boolFieldN", "notThere", false) == false);
}

TEST_CASE( "TestParameterParseSLEnum", "[common][parameterParse]" ) {
  REQUIRE(siphon::parameterParseSLEnum<TEST_ENUM>(genericData1(), "enumField", "notThere") == TEST_ENUM::TEST_PASS);
}

TEST_CASE( "TestParameterParseSLEnumDefault", "[common][parameterParse]" ) {
  REQUIRE(siphon::parameterParseSLEnum<TEST_ENUM>(genericData1(), "notThere", "enumFieldN", TEST_ENUM::TEST_FAIL) ==
      TEST_ENUM::TEST_FAIL);
}

TEST_CASE( "TestParameterParseSLArray", "[common][parameterParse]" ) {
  std::unique_ptr<std::vector<std::string>> d = siphon::parameterParseSLArray<std::string>(genericData1(),
                                                                                           "arrayField",
                                                                                           "notThere");

  REQUIRE(d->size() == 2);
  REQUIRE(d->at(0) == "hello");
  REQUIRE(d->at(1) == "world");
}

TEST_CASE( "TestParameterParseArraySLDefault", "[common][parameterParse]" ) {
  auto* defaultData = new std::vector<std::string>({"1"});
  std::unique_ptr<std::vector<std::string>> d = siphon::parameterParseSLArray<std::string>(genericData1(),
                                                                                           "arrayFieldN",
                                                                                           "notThere",
                                                                                           *defaultData);

  REQUIRE(d->size() == 1);
  REQUIRE(d->at(0) == "1");
}

TEST_CASE( "TestIsVariable", "[common][parameterParse]" ) {
  REQUIRE(siphon::isVariable(genericData1()["varField"]));
  REQUIRE(!siphon::isVariable(genericData1()["intField"]));
}

TEST_CASE( "TestVariableIndex", "[common][parameterParse]" ) {
  char* vp = new char[strlen(siphon::INDEX_PREFIX) + 1];
  strcpy(vp, siphon::INDEX_PREFIX);
  strcat(vp, "1");

  REQUIRE(siphon::variableIndex(nlohmann::json(vp)) == 1);
}