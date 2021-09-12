//
// Created by Tyler on 9/5/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include <iostream>
#include "boost/python.hpp"
#include <chrono>
#include "boost/python/converter/builtin_converters.hpp"

int main() {
    std::cout << "hello world" << std::endl;
    long d1 = 500;
    const char* he = "hello world";
    auto* data = new int8_t[100];

    memcpy(data, &d1, sizeof(long));
    memcpy(data + sizeof(long), he, strlen(he));
    memset(data + strlen(he) + sizeof(long), '\0', 1);



//    auto start = std::chrono::steady_clock::now();
//    delete[] data;
//    auto end = std::chrono::steady_clock::now();
//
//    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "long output " << *((long *)data) << std::endl;
    std::cout << "str output " << ((char *)(data + sizeof(long))) << std::endl;

    delete[] data;
//    ((long*)data)[0] = 100;

//    std::cout << "Hello World" << std::endl;
//    Py_Initialize();
//
//
//    PyObject* o = boost::python::incref(boost::python::list().ptr());
//    PyObject* oa = boost::python::incref(boost::python::long_(5).ptr());
//    PyList_Append(o, oa);
//
//    boost::python::object d = boost::python::extract<boost::python::object>(o);
//    boost::python::object dumps = boost::python::import("json").attr("dumps");
//    boost::python::str r = boost::python::extract<boost::python::str>(dumps(d));
//
//    char const* c_str = boost::python::extract<char const*>(r);
//
//    std::cout << c_str  << std::endl;



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