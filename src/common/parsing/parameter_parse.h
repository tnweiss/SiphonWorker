#include <map>
#include <tuple>
#include <memory>
#include "magic_enum.hpp"
#include "boost/any.hpp"
#include "boost/format.hpp"
#include "nlohmann/json.hpp"

#include "siphon_strings.hpp"
#include "parsing/parse_exception.hpp"

#ifndef SIPHON_PARAMETER_PARSE_H
#define SIPHON_PARAMETER_PARSE_H

namespace siphon {
    /////////////////////////////// Helper Functions ///////////////////////////////
    template <typename T>
    void validate_type(nlohmann::json, std::string);

    template <typename T>
    void validate_type(nlohmann::json&, std::string, std::string);

    template <typename T>
    void validate_exists(nlohmann::json, std::string);

    template <typename T>
    nlohmann::json* validate_exists(nlohmann::json&, std::string, std::string);

    /////////////////////////////// Parameter Parsing ///////////////////////////////

    template <typename T>
    T parameterParse(nlohmann::json&, std::string);

    template <typename T>
    T parameterParse(nlohmann::json&, std::string, T);

    template <typename T>
    T parameterParseEnum(nlohmann::json&, std::string);

    template <typename T>
    T parameterParseEnum(nlohmann::json&, std::string, T);

    template <typename T>
    std::vector<T>* parameterParseArray(nlohmann::json&, std::string);

    template <typename T>
    std::vector<T>* parameterParseArray(nlohmann::json&, std::string, std::vector<T>);

    /////////////////////////////// Parameter Parse Short Long ///////////////////////////////

    template <typename T>
    T parameterParseSL(nlohmann::json&, std::string, std::string);

    template <typename T>
    T parameterParseSL(nlohmann::json&, std::string, std::string, T);

    template <typename T>
    T parameterParseSLEnum(nlohmann::json&, std::string, std::string);

    template <typename T>
    T parameterParseSLEnum(nlohmann::json&, std::string, std::string, T);

    template <typename T>
    std::vector<T>* parameterParseSLArray(nlohmann::json&, std::string, std::string);

    template <typename T>
    std::vector<T>* parameterParseSLArray(nlohmann::json&, std::string, std::string, std::vector<T>);



    bool isVariable(std::string &data);
    int variableIndex(std::string &data);
}
#include "parameter_parse.tpp"
#endif