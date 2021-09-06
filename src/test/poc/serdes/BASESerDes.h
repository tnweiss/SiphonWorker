//
// Created by Tyler on 9/4/2021.
//
#include <vector>
#include <iostream>
#include "serdes_test.h"

#ifndef SIPHON_BASESERDES_H
#define SIPHON_BASESERDES_H

class BASESerDes: public SerDesTest {
public:
    const char* type() final;
    std::shared_ptr<char> serialize(PyObject*) final;
    std::shared_ptr<void> deserialize(const char*) final;
    std::shared_ptr<char> serialize(std::shared_ptr<void>) final;
};


#endif //SIPHON_BASESERDES_H
