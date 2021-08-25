#ifndef GT_H
#define GT_H

#include "nlohmann/json.hpp"
#include "filter.hpp"
#include <vector>
#include "boost/any.hpp"

namespace siphon {

    class GT: public siphon::Filter {
        public:
            GT(nlohmann::json);

            // executes on array type
            bool execute(std::vector<boost::any>&); 

            // executes on object type
            
            void parse(nlohmann::json job, nlohmann::json data_model);
        private:
            float left_operand;
            float right_operand;
    };

}


#endif