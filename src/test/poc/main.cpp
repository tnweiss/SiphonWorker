//
// Created by Tyler on 9/5/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include <iostream>
#include "boost/python.hpp"
#include "boost/python/converter/builtin_converters.hpp"

int main() {
    std::cout << "Hello World" << std::endl;
    Py_Initialize();


    PyObject* o = boost::python::incref(boost::python::list().ptr());
    PyObject* oa = boost::python::incref(boost::python::long_(5).ptr());
    PyList_Append(o, oa);

    boost::python::object d = boost::python::extract<boost::python::object>(o);
    boost::python::object dumps = boost::python::import("json").attr("dumps");
    boost::python::str r = boost::python::extract<boost::python::str>(dumps(d));

    char const* c_str = boost::python::extract<char const*>(r);

    std::cout << c_str  << std::endl;



//    PyObject* myModule = PyImport_ImportModule("json");
//
//    PyObject* dumps = PyObject_GetAttrString(myModule,(char*)"dumps");
//    PyObject* args = PyTuple_New(1);
//    PyTuple_SetItem(args, 0, o);
//
//    PyObject* myResult = PyObject_CallObject(dumps, args);
//
//    boost::python::str r = boost::python::extract<boost::python::str>(myResult);
//    r.
//    std::cout << r  << std::endl;

//    PyObject* op = _PyObject_NEW(PyTypeObject, &PyType_Type);
//    boost::python::tuple o = boost::python::make_tuple();
}