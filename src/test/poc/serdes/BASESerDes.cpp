//
// Created by Tyler on 9/4/2021.
//
#include "BASESerDes.h"


const char* BASESerDes::type() {
    return "Base";
}


DataContainer BASESerDes::serialize(PyObject*) {
    return DataContainer();
}


void* BASESerDes::deserialize(DataContainer&) {
    return nullptr;
}


DataContainer BASESerDes::serialize(void*) {
    return DataContainer();
}

void BASESerDes::delete_deserialized_data(void*) {}


bool BASESerDes::test(void*, PyObject*) {
    return true;
}