#include "variables.h"

bool isVariable(std::string &data) {
    return data.rfind(VARIABLE_PREFIX, 0) == 0;
}

int variableIndex(std::string &data) {
    std::string indexString = data.substr(0, VARIABLE_PREFIX.length());
    std::stoi(indexString);
}
