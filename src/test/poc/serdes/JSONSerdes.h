//
// Created by Tyler on 9/3/2021.
//
#include <vector>
#include "nlohmann/json.hpp"

#include "serdes_test.h"

#ifndef SIPHON_JSONSERDES_H
#define SIPHON_JSONSERDES_H

template<typename Z>
class JSONSerdes: public SerdesTest<Z> {
public:
    const char* type() final;
    const char* serialize(const std::vector<Z>&) final;
    void deserialize(const char*) final;
    bool test(const std::vector<Z>&) final;

private:
    nlohmann::json _deserializedData;
};

#include "JSONSerdes.tpp"

#endif //SIPHON_JSONSERDES_H
