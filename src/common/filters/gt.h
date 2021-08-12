#ifndef GT_H
#define GT_H

#include "json.hpp"
#include "filter.h"
#include <vector>
#include "boost/any.hpp"

using nlohmann::json;

class GT: public Filter {
    public:
        GT(json);
        bool execute(std::vector<boost::any>&); 
    private:
        int left_index;
        int right_index;

        float left_value;
        float right_value;
};

#endif