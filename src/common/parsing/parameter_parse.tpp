namespace siphon {
    /////////////////////////////// Helper Functions ///////////////////////////////
    template <typename T>
    void validate_type(const nlohmann::json &data, const std::string& key) {
        if (
            (typeid(T) == typeid(std::string) && !data[key].is_string()) ||
            (typeid(T) == typeid(int) && !data[key].is_number_integer()) ||
            (typeid(T) == typeid(float) && !data[key].is_number_float()) ||
            (typeid(T) == typeid(unsigned int) && !data[key].is_number_unsigned()) ||
            (typeid(T) == typeid(bool) && !data[key].is_boolean())
            ) {
                
            throw siphon::InvalidTypeParseException(key, data[key].type_name(), 
                data[key].dump(), std::string(typeid(T).name()));
        }
    }

    template <typename T>
    void validate_type(const nlohmann::json& data, const std::string& shortKey, const std::string& longKey) {
        if (
            (typeid(T) == typeid(std::string) && !data.is_string()) ||
            (typeid(T) == typeid(int) && !data.is_number_integer()) ||
            (typeid(T) == typeid(float) && !data.is_number_float()) ||
            (typeid(T) == typeid(unsigned int) && !data.is_number_unsigned()) ||
            (typeid(T) == typeid(bool) && !data.is_boolean())
            ) {
            
            std::string key = shortKey + " " + longKey;
                
            throw siphon::InvalidTypeParseException(key, data.type_name(), 
                data.dump(), std::string(typeid(T).name()));
        }
    }

    /////////////////////////////// Parameter Parsing ///////////////////////////////

    template <typename T>
    T parameterParse(const nlohmann::json& data, const std::string& key) {
        validate_exists(data, key);
        validate_type<T>(data, key);
        return data[key].get<T>();
    }

    template <typename T>
    T parameterParse(const nlohmann::json& data, const std::string& key, const T& defaultVal) {
        try {
            return parameterParse<T>(data, key);
        } catch (siphon::KeyNotFoundParseException& e) {
            (void)e;
            return defaultVal;
        }
    }

    template <typename T>
    T parameterParseEnum(const nlohmann::json& data, const std::string& key) {
        validate_exists(data, key);

        // get the string representation of the type then cast it
        auto _type = parameterParse<std::string>(data, key);
        auto cast_val = magic_enum::enum_cast<T>(_type);

        // if the value can not be cast throw an exception
        if (!cast_val.has_value()) {
            std::string error = (boost::format("Unable to parse '%1%' to SiphonType") % _type).str();
            throw siphon::ParseException(error); 
        }
        return cast_val.value();
    }

    template <typename T>
    T parameterParseEnum(const nlohmann::json& data, const std::string& key, const T& defaultVal) {
        try {
            return parameterParseEnum<T>(data, key);
        } catch (siphon::KeyNotFoundParseException& e) {
            (void)e;
            return defaultVal;
        }
    }

    template <typename T>
    std::unique_ptr<std::vector<T>> parameterParseArray(const nlohmann::json& data, const std::string& key) {
        validate_exists(data, key);

        // assure the data is an array
        if (!data[key].is_array()) {
            throw siphon::InvalidTypeParseException(key, data.type_name(),
                                                    data.dump(), "array");
        }

        // get the array
        std::vector<nlohmann::json> dataArray = data[key];
        // instantiate the output as a shared pointer to a vector of Type t
        std::unique_ptr<std::vector<T>> output(new std::vector<T>());

        for(nlohmann::json d: dataArray) {
            output->push_back(T(d));
        }

        return output;
    }

    template <typename T>
    std::unique_ptr<std::vector<T>> parameterParseArray(const nlohmann::json& data, const std::string& key,
                                                        std::vector<T>& defaultVal) {
        try {
            return parameterParseArray<T>(data, key);
        } catch (siphon::KeyNotFoundParseException& e) {
            return std::unique_ptr<std::vector<T>>(&defaultVal);
        }
    }

    /////////////////////////////// Parameter Parse Short Long ///////////////////////////////

    template <typename T>
    T parameterParseSL(const nlohmann::json& data, const std::string& shortKey, const std::string& longKey) {
        const nlohmann::json *o = validate_exists(data, shortKey, longKey);
        validate_type<T>(data, shortKey, longKey);

        return o->get<T>();
    }

    template <typename T>
    T parameterParseSL(const nlohmann::json& data, const std::string& shortKey, const std::string& longKey,
                       T& defaultVal) {
        try {
            return parameterParseSL<T>(data, shortKey, longKey);
        } catch (siphon::KeyNotFoundParseException& e) {
            return defaultVal;
        }
    }

    template <typename T>
    T parameterParseEnumSL(const nlohmann::json& data, const std::string& shortKey, const std::string& longKey) {
        // get the string representation of the type
        auto _type = parameterParseSL<std::string>(data, shortKey, longKey);
        auto cast_val = magic_enum::enum_cast<T>(_type);

        // if the value can not be cast throw an exception
        if (!cast_val.has_value()) {
            std::string error = (boost::format("Unable to parse '%1%' to SiphonType") % _type).str();
            throw siphon::ParseException(error); 
        }
        return cast_val.value();
    }

    template <typename T>
    T parameterParseEnumSL(const nlohmann::json& data, const std::string& shortKey, const std::string& longKey,
                           const T& defaultVal) {
        try {
            return parameterParseEnumSL<T>(data, shortKey, longKey);
        } catch (siphon::KeyNotFoundParseException& e) {
            return defaultVal;
        }
    }

    template <typename T>
    std::vector<T> parameterParseArraySL(const nlohmann::json& data, const std::string& shortKey,
                                         const std::string& longKey) {
        const nlohmann::json *o = validate_exists(data, shortKey, longKey);

        if (!o->is_array()) {
            std::string key = shortKey + " " + longKey;
            throw siphon::InvalidTypeParseException(key, data[key].type_name(), 
                data[key].dump(), "ARRAY");
        }

        std::vector<nlohmann::json> v = o->get<std::vector<nlohmann::json>>();

        std::vector<T> output{};
        for(nlohmann::json d:  v) {
            output.push_back(T(d));
        }

        return output;
    }

    template <typename T>
    std::vector<T> parameterParseArraySL(const nlohmann::json& data, const std::string& shortKey,
                                         const std::string& longKey, const std::vector<T>& defaultVal) {
        try {
            return parameterParseArray<T>(data, shortKey, longKey);
        } catch (siphon::KeyNotFoundParseException& e) {
            return defaultVal;
        }
    }
}