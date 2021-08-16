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

// TEST_CASE( "Test Greater Than Filter", "[greaterThan]" ) {
//     // create instantiation data
//     nlohmann::json gtFilterJson = nlohmann::json::parse("{ \
//         \"action\": \"filterRows\",\
//         \"filter\": \"gt\",\
//         \"values\": [\
//           \"$.1\",\
//           60\
//         ]\
//       }");
//       // Python::dict d();
//     nlohmann::json gtFilterJsonBad = nlohmann::json::parse("{ \
//     \"action\": \"filterRows\",\
//     \"filter\": \"gt\",\
//     \"values\": [\
//       \"$.1\"\
//     ]\
//       }");

//     //create incoming data
//     std::vector<boost::any> d;
//     d.push_back(5);
//     d.push_back(6);
//     d.push_back("hello");

//     std::vector<boost::any> d1;
//     d1.push_back(5);
//     d1.push_back(6);
//     d1.push_back("hello");

//     SECTION("Greater Than") {
//         siphon::GT gt(gtFilterJson);
//         REQUIRE(gt.execute(d));
//         REQUIRE_THROWS(siphon::GT(gtFilterJsonBad));
//         siphon::GT gg(gtFilterJsonBad);
//     }
// }