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

    template <typename T>
    T parameterParseEnum(nlohmann::json& data, std::string key) {
        // get the string representation of the type
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
    std::vector<T> parameterParseArray(nlohmann::json& data, std::string key) {
        // ensure the key exists in the data
        if (!data.contains(key)) {
            throw siphon::KeyNotFoundParseException(key);
        }

        if (!data[key].is_array()) {
            throw siphon::InvalidTypeParseException(key, data[key].type_name(), 
                data[key].dump(), "ARRAY");
        }

        std::vector<nlohmann::json> dataArray = data[key];

        std::vector<T> output{};
        for(nlohmann::json d: dataArray) {
            output.push_back(T(d));
        }

        return output;
    }
}