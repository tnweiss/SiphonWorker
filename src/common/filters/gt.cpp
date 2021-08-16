#include "gt.h"
#include <vector>
#include "json.hpp"
#include "exceptions/parse_exception.hpp"

namespace siphon {

    GT::GT(nlohmann::json  data) {
        // ensure the incoming frame is an array
        if (!data["values"].is_array()) {
            throw ParseException("\"values\" must be an array of 2 values");
        }

        if (data["values"].size() != 2) {
            throw ParseException("\"values\" must be an array of 2 values");
        }
    }

    bool GT::execute(std::vector<boost::any> &data) {
        return true;
    }

    void GT::parse(nlohmann::json job, nlohmann::json data_model) {
        return ;
    }

}

