//
// Created by Tyler on 9/3/2021.
//

#ifndef SIPHON_JSONSERDES_H
#define SIPHON_JSONSERDES_H

#include "nlohmann/json.hpp"

#include "serdes_test.h"


class JSONSerDes: public SerDesTest {
public:
    JSONSerDes(): dumps(boost::python::import("json").attr("dumps")) {};
    const char* type() final;
    DataContainer serialize(PyObject*) final;
    void* deserialize(DataContainer&) final;
    DataContainer serialize(void*) final;
    void delete_deserialized_data(void*) final;
private:
    const boost::python::object dumps;
};

#endif //SIPHON_JSONSERDES_H
