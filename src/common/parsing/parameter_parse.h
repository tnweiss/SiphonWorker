#include <map>
#include <string>
#include <tuple>
#include <memory>
#include "magic_enum.hpp"
#include "boost/any.hpp"
#include "boost/format.hpp"
#include "nlohmann/json.hpp"

#include "siphon_strings.hpp"
#include "parse_exception.hpp"

#ifndef SIPHON_PARAMETER_PARSE_H
#define SIPHON_PARAMETER_PARSE_H

namespace siphon {
    /////////////////////////////// Helper Functions ///////////////////////////////
    template <typename T>
    void validate_type(const nlohmann::json&, const std::string&);

    template <typename T>
    void validate_type(const nlohmann::json&, const std::string&, const std::string&);

    void validate_exists(const nlohmann::json&, const std::string&);

    const nlohmann::json* validate_exists(const nlohmann::json&, const std::string&, const std::string&);

    /////////////////////////////// Parameter Parsing ///////////////////////////////

    template <typename T>
    T parameterParse(const nlohmann::json&, const std::string&);

    template <typename T>
    T parameterParse(const nlohmann::json&, const std::string&, const T&);

    template <typename T>
    T parameterParseEnum(const nlohmann::json&, const std::string&);

    template <typename T>
    T parameterParseEnum(const nlohmann::json&, const std::string&, const T&);

    template <typename T>
    std::unique_ptr<std::vector<T>> parameterParseArray(const nlohmann::json&, const std::string&);

    template <typename T>
    std::unique_ptr<std::vector<T>> parameterParseArray(const nlohmann::json&, const std::string&,
                                                        std::vector<T>&);

    /////////////////////////////// Parameter Parse Short Long ///////////////////////////////

    template <typename T>
    T parameterParseSL(const nlohmann::json&, const std::string&, const std::string&);

    template <typename T>
    T parameterParseSL(const nlohmann::json&, const std::string&, const std::string&, const T&);

    template <typename T>
    T parameterParseSLEnum(const nlohmann::json&, const std::string&, const std::string&);

    template <typename T>
    T parameterParseSLEnum(const nlohmann::json&, const std::string&, const std::string&, const T&);

    template <typename T>
    std::unique_ptr<std::vector<T>> parameterParseSLArray(const nlohmann::json&, const std::string&,
                                                          const std::string&);

    template <typename T>
    std::unique_ptr<std::vector<T>> parameterParseSLArray(const nlohmann::json&, const std::string&, const std::string&,
                                                          std::vector<T>&);

    bool isVariable(const nlohmann::json& data);
    int variableIndex(const nlohmann::json& data);
}
#include "parameter_parse.tpp"
#endif