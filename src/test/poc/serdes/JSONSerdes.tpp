//
// Created by Tyler on 9/3/2021.
//

#include "JSONSerdes.h"


template<typename T>
const char *JSONSerdes<T>::type() {
    return "JSON";
}

template<typename T>
const char *JSONSerdes<T>::serialize(const std::vector<T>& data) {
    nlohmann::json jsonData = data;

    std::string ds = jsonData.dump();

    // +1 for null terminator
    char* rd = new char[ds.size() + 1];
    // add null terminator
    rd[ds.size()] = '\0';

    // copy over everything from the string
    ds.copy(rd, ds.size());

    return rd;
}

template<typename T>
void JSONSerdes<T>::deserialize(const char *serializedData) {
    std::string a(serializedData);
    this->_deserializedData = nlohmann::json::parse(a);
}

template<typename Z>
bool JSONSerdes<Z>::test(const std::vector<Z> &expected) {
    return this->_deserializedData == expected;
}
