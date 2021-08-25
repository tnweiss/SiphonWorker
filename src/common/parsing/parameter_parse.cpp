#include "parameter_parse.h"


namespace siphon {
    bool isVariable(const std::string& data) {
        return data.rfind(siphon::VARIABLE_PREFIX, 0) == 0;
    }

    int variableIndex(const std::string& data) {
        std::string indexString = data.substr(0, siphon::VARIABLE_PREFIX.length());
        return std::stoi(indexString);
    }

    void validate_exists(const nlohmann::json& data, const std::string& key) {
        if (!data.contains(key)) {
            throw siphon::KeyNotFoundParseException(key);
        }
    }

    const nlohmann::json* validate_exists(const nlohmann::json& data, const std::string& shortKey, const std::string& longKey) {
        if (data.contains(shortKey)) {
            return &data[shortKey];
        } else if (data.contains(longKey)) {
            return &data[longKey];
        } else {
            throw siphon::KeyNotFoundParseException(shortKey, longKey);
        }
    }
}