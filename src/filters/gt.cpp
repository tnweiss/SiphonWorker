#include "gt.h"
#include <vector>
#include "../json.hpp"

using nlohmann::json;

GT::GT(json data) {
    
}

bool GT::execute(std::vector<void *> data) {
    return true;
}