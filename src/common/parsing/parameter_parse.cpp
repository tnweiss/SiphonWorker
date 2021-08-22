#include "parameter_parse.h"


namespace siphon {
    bool isVariable(std::string &data) {
        return data.rfind(siphon::VARIABLE_PREFIX, 0) == 0;
    }

    int variableIndex(std::string &data) {
        std::string indexString = data.substr(0, siphon::VARIABLE_PREFIX.length());
        return std::stoi(indexString);
    }
}