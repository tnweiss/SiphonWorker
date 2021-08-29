#include "parameter_parse.h"
#include <iostream>

namespace siphon {
    bool isVariable(const nlohmann::json& data) {
      // if the data is a string it may be a variable
      if (data.is_string()){
        // get the pointer to the value
        const std::string* sVal = data.get_ptr<const nlohmann::json::string_t*>();
        // determine if the string starts with the prefix
        return sVal->rfind(siphon::VARIABLE_PREFIX, 0) == 0;
      }
      // if the data is not a string it can not be a variable
      return false;
    }

    int variableIndex(const nlohmann::json& data) {
      if (!data.is_string()) {
        throw siphon::ParseException("Unable to parse variable index from: " + to_string(data) +
          "Required type is string");
      }

      const std::string* d = data.get_ptr<const nlohmann::json::string_t*>();
      return std::stoi(d->substr(strlen(siphon::VARIABLE_PREFIX)));
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