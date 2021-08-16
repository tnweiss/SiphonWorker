namespace siphon {

    template <typename T>
    T parameterParse(nlohmann::json& data, std::string key) {
        // ensure the key exists in the data
        if (!data.contains(key)) {
            throw siphon::KeyNotFoundParseException(key);
        }

        // ensure the value that exists is of the same type
        if (
            (typeid(T) == typeid(std::string) && !data[key].is_string()) ||
            (typeid(T) == typeid(int) && !data[key].is_number_integer())) {
                
            throw siphon::InvalidTypeParseException(key, data[key].type_name(), 
                data[key].dump(), std::string(typeid(T).name()));
        }

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
}