#ifndef VARIABLES_H
#define VARIABLES_H

#include <string>

const std::string VARIABLE_PREFIX = "$.";

bool isVariable(std::string &data);
int variableIndex(std::string &data);

#endif
