//
// Created by Tyler on 9/3/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include "JSONSerDes.h"


const char *JSONSerDes::type() {
    return "JSON";
}

DataContainer JSONSerDes::serialize(PyObject * pyJson) {
    // convert pyobject to boost python object
    boost::python::object d = boost::python::extract<boost::python::object>(pyJson);

    // capture the return value of the return value
    boost::python::object rv = dumps(d);
    const char* prv = boost::python::extract<const char*>(rv);

    // return the data container
    return DataContainer(prv);
}

void* JSONSerDes::deserialize(DataContainer& serializedData) {
    // cast the data as a string
    auto* jsonStr = serializedData.c_str();

    // parse the string
    return new nlohmann::json(nlohmann::json::parse(jsonStr));
}


DataContainer JSONSerDes::serialize(void* json) {
    // cast the pointer as a pointer to json
    auto* j = (nlohmann::json*)json;

    // dump the data to a string
    std::string s = j->dump();

    // pass ownership to the data container
    return DataContainer(s.c_str());
}


void JSONSerDes::delete_deserialized_data(void* json) {
    delete (nlohmann::json*)json;
}