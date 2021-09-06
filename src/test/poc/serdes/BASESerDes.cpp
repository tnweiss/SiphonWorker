//
// Created by Tyler on 9/4/2021.
//

#include "BASESerdes.h"

template<typename T>
const char* type() {
    return "BASE";
}

const char* serialize(const PyObject*) {
    return nullptr;
}


std::shared_ptr<void> deserialize(const char*) {
    return std::make_shared<void>(nullptr);
}


const char* serialize(std::shared_ptr<void>) {
    return nullptr;
}
