//
// Created by Tyler on 9/4/2021.
//

#include "BASESerDes.h"


const char* BASESerDes::type() {
    return "BASE";
}


std::shared_ptr<char> BASESerDes::serialize(PyObject*) {
    return nullptr;
}


std::shared_ptr<void> BASESerDes::deserialize(const char*) {
    return nullptr;
}


std::shared_ptr<char> BASESerDes::serialize(const std::shared_ptr<void>) {
    return nullptr;
}
