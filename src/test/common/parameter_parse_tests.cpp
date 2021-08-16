#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <filters/gt.h>
#include <iostream>
#include "json.hpp"
#include <string>
#include <vector>
#include "boost/any.hpp"
#include "catch2.hpp"
#include "boost/python/extract.hpp"
#include "models/ParameterParse.h"
#include "../data.hpp"
#include "exceptions/parse_exception.hpp"

TEST_CASE( "TestParameterParseString", "[parameterParse]" ) {
    nlohmann::json data = getGenericData1();
    
    std::string helloValue = siphon::parameterParse<std::string>(data, "hello");
    REQUIRE(helloValue.compare("world") == 0);
}


TEST_CASE( "TestParameterParseRequiredException", "[parameterParse]" ) {
    nlohmann::json data = getGenericData1();
    
    REQUIRE_THROWS(siphon::parameterParse<std::string>(data, "doesNotExist"));
}


TEST_CASE( "TestParameterParseWrongTypeException", "[parameterParse]" ) {
    nlohmann::json data = getGenericData1();
    
    REQUIRE_THROWS_AS(siphon::parameterParse<int>(data, "hello"), siphon::InvalidTypeParseException);
}

TEST_CASE( "TestParameterParseNotRequiredNotExists", "[parameterParse]" ) {
    nlohmann::json data = getGenericData1();
    
    std::string doesNotExistValue = siphon::parameterParse<std::string>(data, "doesNotExist", "nowItDoes");
    REQUIRE(doesNotExistValue.compare("nowItDoes") == 0);
}