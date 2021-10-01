#include "magic_enum.hpp"

#ifndef SIPHON_SIPHON_STRINGS
#define SIPHON_SIPHON_STRINGS

namespace siphon {
    // parsing variables
    static const char* VARIABLE_PREFIX = "$."; // pretty version used externally
    static const char* INDEX_PREFIX = "!."; // internal usage
    static const char* KEY_PREFIX = "?.";

    // data model field keys
    static const char* DATA_MODEL_FIELD_NAME = "field_name";
    static const char* DATA_MODEL_FIELD_DESCRIPTION = "description";
    static const char* DATA_MODEL_FIELD_TYPE = "field_type";

    // data model keys
    static const char* DATA_MODEL_DATA_STRUCTURE = "data_structure";
    static const char* DATA_MODEL_FIELDS = "fields";

    // filter variables
    static const char* GT_FILTER_LONG = "greaterThan";
    static const char* GT_FILTER_SHORT = "gt";

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