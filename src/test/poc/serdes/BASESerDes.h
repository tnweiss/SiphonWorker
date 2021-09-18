//
// Created by Tyler on 9/4/2021.
//

#ifndef SIPHON_BASESERDES_H
#define SIPHON_BASESERDES_H

#include "serdes_test.h"

class BASESerDes: public SerDesTest {
public:
    const char* type() final;
    DataContainer serialize(PyObject*) final;
    void* deserialize(DataContainer&) final;
    DataContainer serialize(void*) final;
    void delete_deserialized_data(void*) final;
    bool test(void*, PyObject*) final;
};


#endif //SIPHON_BASESERDES_H
