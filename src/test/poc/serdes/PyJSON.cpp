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

bool PyJSON::test(void* actual, PyObject* expected) {
    auto* o = ((boost::python::object*)actual)->ptr();

    // get the list len + data size to calculate the size of the buffer
    size_t expectedLen = PyList_Size(expected);
    size_t actualLen = PyList_Size(o);

    if (expectedLen != actualLen) {
        return false;
    }

    long long e;
    long long a;
    for (int i=0; i<expectedLen; i++) {
        e = PyLong_AsLong(PyList_GetItem(expected, i));
        a = PyLong_AsLong(PyList_GetItem(o, i));

        if (e != a) {
            return false;
        }
    }
    return true;
}
