#include <map>
#include <tuple>
#include "magic_enum.hpp"
#include "boost/any.hpp"
#include "boost/format.hpp"
#include "nlohmann/json.hpp"

#include "siphon_strings.hpp"
#include "parsing/parse_exception.hpp"

#ifndef SIPHON_PARAMETER_PARSE_H
#define SIPHON_PARAMETER_PARSE_H

namespace siphon {
    template <typename T>
    T parameterParse(nlohmann::json&, std::string);

    template <typename T>
    T parameterParse(nlohmann::json&, std::string, T);

    template <typename T>
    T parameterParseEnum(nlohmann::json&, std::string);

    template <typename T>
    std::vector<T> parameterParseArray(nlohmann::json&, std::string);

    bool isVariable(std::string &data);
    int variableIndex(std::string &data);
}
#include "parameter_parse.tpp"
#endif