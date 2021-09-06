//
// Created by Tyler on 9/3/2021.
//
#include <vector>
#include "boost/python.hpp"
#include "nlohmann/json.hpp"

#include "serdes_test.h"

#ifndef SIPHON_JSONSERDES_H
#define SIPHON_JSONSERDES_H

class JSONSerDes: public SerDesTest {
public:
    JSONSerDes(): dumps(boost::python::import("json").attr("dumps")) {};
    const char* type() final;
    std::shared_ptr<char> serialize(PyObject*) final;
    std::shared_ptr<void> deserialize(const char*) final;
    std::shared_ptr<char> serialize(std::shared_ptr<void>) final;
private:
    const boost::python::object dumps;
};

class JSONContainer {
public:
    JSONContainer(const char* json) {
        std::string a{};
        a.append(json);

        this->_json = nlohmann::json::parse(a);
    }

    nlohmann::json j() {
        return this->_json;
    }

private:
    nlohmann::json _json;
};

#endif //SIPHON_JSONSERDES_H
