//
// Created by Tyler on 9/4/2021.
//
#include <vector>
#include <iostream>
#include "serdes_test.h"

#ifndef SIPHON_BASESERDES_H
#define SIPHON_BASESERDES_H

template<typename T>
class BASESerdes: public SerDesTest<T> {
public:
    const char* type() override{return "BASE";};
    const char* serialize(const std::vector<T>& d) override {
        return "";
    };

    void deserialize(const char* _in) override {

    };
    bool test(const std::vector<T>&) override {
        return true;
    };

private:
    std::vector<T> _deserializedData;
};


#endif //SIPHON_BASESERDES_H
