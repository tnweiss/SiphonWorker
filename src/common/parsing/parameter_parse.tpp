namespace siphon {
    /////////////////////////////// Helper Functions ///////////////////////////////
    template <typename T>
    void validate_type(nlohmann::json &data, std::string key) {
        if (
            (typeid(T) == typeid(std::string) && !data[key].is_string()) ||
            (typeid(T) == typeid(int) && !data[key].is_number_integer())) {
                
            throw siphon::InvalidTypeParseException(key, data[key].type_name(), 
                data[key].dump(), std::string(typeid(T).name()));
        }
    }

    template <typename T>
    void validate_type(nlohmann::json &data, std::string shortKey, std::string longKey) {
        if (
            (typeid(T) == typeid(std::string) && !data.is_string()) ||
            (typeid(T) == typeid(int) && !data.is_number_integer())) {
            
            std::string key = shortKey + " " + longKey;
                
            throw siphon::InvalidTypeParseException(key, data.type_name(), 
                data.dump(), std::string(typeid(T).name()));
        }
    }

    void validate_exists(nlohmann::json &data, std::string key) {
        if (!data.contains(key)) {
            throw siphon::KeyNotFoundParseException(key);
        }
    }

    nlohmann::json* validate_exists(nlohmann::json &data, std::string shortKey, std::string longKey) {
        if (data.contains(shortKey)) {
            return &data[shortKey];
        } else if (data.contains(longKey)) {
            return &data[longKey];
        } else {
            throw siphon::KeyNotFoundParseException(shortKey, longKey);
        }
    }

    /////////////////////////////// Parameter Parsing ///////////////////////////////

    template <typename T>
    T parameterParse(nlohmann::json& data, std::string key) {
        validate_exists(data, key);
        validate_type<T>(data, key);
        return data[key].get<T>();
    }

    template <typename T>
    T parameterParse(nlohmann::json& data, std::string key, T defaultVal) {
        try {
            return parameterParse<T>(data, key);
        } catch (siphon::KeyNotFoundParseException e) {
            return defaultVal;
        }
    }

    template <typename T>
    T parameterParseEnum(nlohmann::json& data, std::string key) {
        validate_exists(data, key);

        // get the string representation of the type then cast it
        std::string _type = parameterParse<std::string>(data, key);
        auto cast_val = magic_enum::enum_cast<T>(_type);

        // if the value can not be cast throw an exception
        if (!cast_val.has_value()) {
            std::string error = (boost::format("Unable to parse '%1%' to SiphonType") % _type).str();
            throw siphon::ParseException(error); 
        }
        return cast_val.value();
    }

    template <typename T>
    T parameterParseEnum(nlohmann::json& data, std::string key, T defaultVal) {
        try {
            return parameterParseEnum<T>(data, key);
        } catch (siphon::KeyNotFoundParseException e) {
            return defaultVal;
        }
    }

    template <typename T>
    std::vector<T>* parameterParseArray(nlohmann::json& data, std::string key) {
        validate_exists(data, key);
        validate_type<std::vector>(data, key);

        std::vector<nlohmann::json> dataArray = data[key];

        std::shared_ptr<std::vector<T>> output(std::vector<T>());

        for(nlohmann::json d: dataArray) {
            output.push_back(T(d));
        }

        return output;
    }

    template <typename T>
    std::vector<T>* parameterParseArray(nlohmann::json& data, std::string key, std::vector<T>& defaultVal) {
        try {
            return parameterParseArray<T>(data, key);
        } catch (siphon::KeyNotFoundParseException e) {
            return defaultVal;
        }
    }

    /////////////////////////////// Parameter Parse Short Long ///////////////////////////////

    template <typename T>
    T parameterParseSL(nlohmann::json& data, std::string shortKey, std::string longKey) {
        nlohmann::json *o = validate_exists<T>(data, shortKey, longKey);
        validate_type<T>(data, shortKey, longKey);

        return o->get<T>();
    }

    template <typename T>
    T parameterParseSL(nlohmann::json& data, std::string shortKey, std::string longKey, T defaultVal) {
        try {
            return parameterParseSL<T>(data, shortKey, longKey);
        } catch (siphon::KeyNotFoundParseException e) {
            return defaultVal;
        }
    }

    template <typename T>
    T parameterParseEnumSL(nlohmann::json& data, std::string shortKey, std::string longKey) {
        // get the string representation of the type
        std::string _type = parameterParseSL<std::string>(data, shortKey, longKey);
        auto cast_val = magic_enum::enum_cast<T>(_type);

        // if the value can not be cast throw an exception
        if (!cast_val.has_value()) {
            std::string error = (boost::format("Unable to parse '%1%' to SiphonType") % _type).str();
            throw siphon::ParseException(error); 
        }
        return cast_val.value();
    }

    template <typename T>
    T parameterParseEnumSL(nlohmann::json& data, std::string shortKey, std::string longKey, T defaultVal) {
        try {
            return parameterParseEnumSL<T>(data, shortKey, longKey);
        } catch (siphon::KeyNotFoundParseException e) {
            return defaultVal;
        }
    }

    template <typename T>
    std::vector<T> parameterParseArraySL(nlohmann::json& data, std::string shortKey, std::string longKey) {
        nlohmann::json *o = validate_exists<T>(data, shortKey, longKey);

        if (!o->is_array()) {
            std::string key = shortKey + " " + longKey;
            throw siphon::InvalidTypeParseException(key, data[key].type_name(), 
                data[key].dump(), "ARRAY");
        }

        std::vector<T> output{};
        for(nlohmann::json d: &o) {
            output.push_back(T(d));
        }

        return output;
    }

    template <typename T>
    std::vector<T> parameterParseArraySL(nlohmann::json& data, std::string shortKey, std::string longKey, std::vector<T> defaultVal) {
        try {
            return parameterParseArray<T>(data, shortKey, longKey);
        } catch (siphon::KeyNotFoundParseException e) {
            return defaultVal;
        }
    }
}