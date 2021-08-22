#include <string>
#include "magic_enum.hpp"

#ifndef SIPHON_SIPHON_STRINGS
#define SIPHON_SIPHON_STRINGS

namespace siphon {
    // parsing variables
    const std::string VARIABLE_PREFIX = "$.";

    // data model fields
    const std::string DESCRIPTION_KEY = "description";
    const std::string TYPE_KEY = "field_type";
    const std::string NAME_KEY = "field_name";
    const std::string DATA_STRUCTURE_KEY = "data_structure";
    const std::string FIELDS_KEY = "fields";

    // filter variables
    const std::string GT_FILTER_LONG = "greaterThan";
    const std::string GT_FILTER_SHORT = "gt";

    enum class DataStructure {
        array = 1,
        object = 2
    };

    enum class SiphonType {
        BOOLEAN = 1,
        STRING = 2,
        FLOAT = 3,
        INTEGER = 4
    };
}

#endif