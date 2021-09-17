//
// Created by Tyler on 9/16/2021.
//

#ifndef SIPHON_PYJSON_H
#define SIPHON_PYJSON_H

#include "serdes_test.h"


class PyJSON: public SerDesTest {
public:
    PyJSON(): dumps(boost::python::import("json").attr("dumps")), loads(boost::python::import("json").attr("loads")) {};
    const char* type() final;
    DataContainer serialize(PyObject*) final;
    void* deserialize(DataContainer&) final;
    DataContainer serialize(void*) final;
    void delete_deserialized_data(void*) final;
private:
    const boost::python::object dumps;
    const boost::python::object loads;
};


#endif //SIPHON_PYJSON_H
