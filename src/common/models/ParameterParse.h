#ifndef PARAMETER_PARSE_H
#define PARAMETER_PARSE_H

#include <map>
#include "boost/any.hpp"
#include "boost/format.hpp"
#include <tuple>
#include "exceptions/parse_exception.hpp"
#include "json.hpp"

namespace siphon {
    template <typename T>
    T parameterParse(nlohmann::json&, std::string);

    template <typename T>
    T parameterParse(nlohmann::json&, std::string, T);
}
#include "ParameterParse.tpp"
#endif