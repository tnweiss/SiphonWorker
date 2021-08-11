#ifndef GT_H
#define GT_H

#include "../json.hpp"
#include "filter.h"
#include <vector>

using nlohmann::json;

class GT: public Filter {
    public:
        GT(json);
        bool execute(std::vector<void *>); 
    private:
        int left_index;
        int right_index;

        float left_value;
        float right_value;
};

#endif