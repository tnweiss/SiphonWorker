//
// Created by Tyler on 9/5/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include <iostream>
#include "boost/python.hpp"

int main() {
    std::cout << "Hello World" << std::endl;
    Py_Initialize();

    PyObject* o = boost::python::incref(boost::python::list().ptr());
    PyObject* oa = boost::python::incref(boost::python::long_(5).ptr());

    PyList_Append(o, oa);

//    PyObject* op = _PyObject_NEW(PyTypeObject, &PyType_Type);
//    boost::python::tuple o = boost::python::make_tuple();
}