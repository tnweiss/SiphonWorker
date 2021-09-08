//
// Created by Tyler on 9/3/2021.
//

#include "boost/python.hpp"
#include "JSONSerDes.h"
#include <iostream>

const char *JSONSerDes::type() {
    return "JSON";
}

const char* JSONSerDes::serialize(PyObject * pyJson) {
    // convert pyobject to boost python object
    boost::python::object d = boost::python::extract<boost::python::object>(pyJson);

    // capture the return value of the return value
    boost::python::object rv = dumps(d);
    const char* prv = boost::python::extract<const char*>(rv);
    size_t prvLen = strlen(prv);

    // copy and return
    char* rvBuffer = new char[prvLen + 1];
    rvBuffer[prvLen] = '\0';
    strncpy(rvBuffer, prv, strlen(prv));

    // call the dumps function and capture the return value
    return rvBuffer;
}

std::shared_ptr<void> JSONSerDes::deserialize(const char *serializedData) {
    auto *ct = new JSONContainer(serializedData);
    return std::shared_ptr<void>(ct);
}

std::shared_ptr<char> JSONSerDes::serialize(std::shared_ptr<void> json) {
    // get the string representation
    std::string s = ((JSONContainer*)json.get())->j()->dump();

    // copy the data into a string buffer
    std::shared_ptr<char> rv(new char[s.length() + 1]);
    s.copy(rv.get(), s.length());
    rv.get()[s.length()] = '\0';

    return rv;
}


//const char *JSONSerDes<T>::serialize(const std::vector<T>& data) {
//    nlohmann::json jsonData = data;
//
//    std::string ds = jsonData.dump();
//
//    // +1 for null terminator
//    char* rd = new char[ds.size() + 1];
//    // add null terminator
//    rd[ds.size()] = '\0';
//
//    // copy over everything from the string
//    ds.copy(rd, ds.size());
//
//    return rd;
//}
//
//template<typename T>
//void JSONSerDes<T>::deserialize(const char *serializedData) {
//    std::string a(serializedData);
//    this->_deserializedData = nlohmann::json::parse(a);
//}
//
//template<typename Z>
//bool JSONSerDes<Z>::test(const std::vector<Z> &expected) {
//    return this->_deserializedData == expected;
//}
