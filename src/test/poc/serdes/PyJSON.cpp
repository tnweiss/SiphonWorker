//
// Created by Tyler on 9/16/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include "PyJSON.h"


const char* PyJSON::type() {
    return "PyJSON";
}


DataContainer PyJSON::serialize(PyObject* pyJson) {
    // convert pyobject to boost python object
    boost::python::object d = boost::python::extract<boost::python::object>(pyJson);

    // capture the return value of the return value
    boost::python::object rv = dumps(d);
    const char* prv = boost::python::extract<const char*>(rv);

    // return the data container
    return DataContainer(prv);
}

void* PyJSON::deserialize(DataContainer& dc) {
    boost::python::object o = boost::python::str(const_cast<const char *>(dc.c_str()));

    return new boost::python::object(loads(o));
}


DataContainer PyJSON::serialize(void* pyJson) {
    // capture the return value of the return value
    auto* d = (boost::python::object*)pyJson;

    boost::python::object rv = dumps(*d);
    const char* prv = boost::python::extract<const char*>(rv);

    // return the data container
    return DataContainer(prv);
}


void PyJSON::delete_deserialized_data(void* po) {
    auto* o = (boost::python::object*)po;

    delete o;
}