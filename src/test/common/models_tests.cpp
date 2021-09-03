#include "catch2.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

#include "siphon_strings.hpp"
#include "../data.hpp"
#include "models/data_model_field.h"
#include "models/data_model.h"

#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/pool/object_pool.hpp>

TEST_CASE( "TESTDataModelField", "[common]" ) {
  const nlohmann::json data = dataModelFieldData();
  siphon::DataModelField dmf(data);

  REQUIRE(dmf.name() == "test");
  REQUIRE(dmf.description() == "This is a general description");
  REQUIRE(dmf.type() == siphon::SiphonType::STRING);
}

TEST_CASE("DataModelConstructor", "[common]") {
    nlohmann::json test_data = dataModelData();
    siphon::DataModel dm(test_data);

    REQUIRE(dm.fields()->size() == 1);
    REQUIRE(dm.dataStructure() == siphon::DataStructure::array);
}


//TEST_CASE("jsonTest", "[common]") {
//  nlohmann::json test_data = tableData();
//  std::vector<nlohmann::json>* element = test_data[0].get_ptr<nlohmann::json::array_t *>();
//  element->erase(element->begin(), element->end());
////  test_data.erase(element->at());
////  delete element;
////  test_data.erase(element->at());
////  test_data.erase(element->begin());
////  element->push_back("test");
////  //element.erase(element[0].begin() + 1);
//  for (int i=0; i<test_data.size(); i++) {
//    if (test_data[i].empty()) {
//      test_data.erase(i);
//    }
//  }
//
//  test_data[0][2].get_ptr<nlohmann::json::string_t *>();
//  //std::cout << typeid(decltype(i)).name() << std::endl;
//
//  std::cout << test_data.dump() << std::endl;
//}
//
TEST_CASE("jsonTest2", "[common]") {
  std::vector<std::vector<boost::any>> frames{{"k", 1, 9L}, {}};

  std::vector<int> d{1,2,3};

  std::ofstream ofs("filename.txt");
  boost::archive::binary_oarchive oa(ofs);
  oa & boost::serialization::make_binary_object(&frames, sizeof(frames));
  //int h = boost::any_cast<int>(frames.at(0).at(2));
  //REQUIRE(8 < h);
}
//
//TEST_CASE("jsonTest3", "[common]") {
//  std::vector<std::vector<boost::any>> frames{};
//  boost::serialization::binary_object o(&frames, 10);
//
//  std::vector<int> d{1,2,3};
//
//  std::ifstream ifs("filename.txt");
//  boost::archive::binary_iarchive ia(ifs);
//  ia >> o;
//
//  std::cout << frames.size() << std::endl;
//  //int h = boost::any_cast<int>(frames.at(0).at(2));
//  //REQUIRE(8 < h);
//}
//
//TEST_CASE("jsonTest4", "[common]") {
//
//  boost::any t = 1;
//
//  std::ofstream ofs("filename3.txt");
//  boost::archive::binary_oarchive oa(ofs);
//  oa & boost::serialization::make_binary_object(&t, sizeof(boost::any));
//  //int h = boost::any_cast<int>(frames.at(0).at(2));
//  //REQUIRE(8 < h);
//}
//
//TEST_CASE("jsonTest6", "[common]") {
//
//  // frame serialization with this
//  https://www.boost.org/doc/libs/1_76_0/libs/serialization/doc/index.html
//
//  boost::object_pool<boost::any> mr_pool{};
//
//
//  boost::any* t = mr_pool.construct();
//
//
//  std::ifstream ifs("filename2.txt");
//  boost::archive::binary_iarchive ia(ifs);
//  int* r;
//
//  ia >>  r;
//
//}

//TEST_CASE("jsonTest9", "[common]") {
//  int* a = new int(1);
//  auto* b = new float(5.0);
//  auto* c = new std::string("hello world");
//  uint8_t d = 9;
//
//  char* e[100];
//
//  int offset = 0;
//  memmove(e, a, sizeof(int));
//  offset += sizeof(int);
//
//  memmove(e + offset, b, sizeof(float));
//  offset += sizeof(float);
//  std::vector<int> t{};
//  t.data()
//
//  std::memmove(&c, e + offset + c->size(), c->size());
//
//  delete b;
//  delete a;
//  delete c;
//
//  int* aa = (int *)e;
//  auto* bb = (float *)e[sizeof(int)];
//
//  std::cout << aa << " " << bb << std::endl;
//
//}