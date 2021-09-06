//
// Created by Tyler on 9/4/2021.
//

#define BOOST_PYTHON_STATIC_LIB
#include "boost/python/tuple.hpp"
#include "boost/python.hpp"
#include <vector>
#include <string>
#include <iostream>

void test(PyObject *v) {
    std::cout << "got it" <<  std::endl;
    //const char* buffer[100];

    PyList_Size(v);
    //const char* d = boost::python::extract<const char*>(v);

    const std::vector<PyObject>* d = boost::python::extract<const std::vector<PyObject>*>(v);
    std::cout << d->size() << std::endl;
    //std::cout << d << std::endl;
    //std::cout << *((int *)v) << std::endl;
//    if (v->contains(1)) {
//        std::cout << "found it " << std::endl;
//    }
}

PyObject *ml() {
    PyObject* o = boost::python::incref(boost::python::list().ptr());
    PyObject* oa = boost::python::incref(boost::python::long_(5).ptr());

    PyList_Append(o, oa);
    return o;
}


BOOST_PYTHON_MODULE(t) {
    using namespace boost::python;
    def("test", test, (arg("v")));
    def("ml", ml);
}