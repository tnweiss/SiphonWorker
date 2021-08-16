#ifndef GT_H
#define GT_H

#include "json.hpp"
#include "filter.h"
#include <vector>
#include "boost/any.hpp"

namespace siphon {

    class GT: public siphon::Filter {
        public:
            GT(nlohmann::json );
            bool execute(std::vector<boost::any>&); 
            void parse(nlohmann::json job, nlohmann::json data_model);
        private:
            int left_index;
            int right_index;

            float left_value;
            float right_value;
    };

}


#endif