# ifndef Job

#include <vector>
#include "boost/any.hpp"
#include "json.hpp"

namespace siphon {

    class Filter {
        public:
            virtual bool execute(std::vector<boost::any>&) = 0;
            virtual void parse(nlohmann::json job, nlohmann::json data_model) = 0;
    };

};


# endif