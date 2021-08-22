#include "gt.h"
#include <vector>
#include "nlohmann/json.hpp"

namespace siphon {

    GT::GT(nlohmann::json  data) {
    }

    bool GT::execute(std::vector<boost::any> &data) {
        return true;
    }

    void GT::parse(nlohmann::json job, nlohmann::json data_model) {
        return ;
    }

}

