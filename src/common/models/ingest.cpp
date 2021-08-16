#include "ingest.h"

namespace siphon {
    DataModelField::DataModelField(nlohmann::json &data) {
        this->name = parameterParse<std::string>(data, "name", true);
        this->required = parameterParse<bool>(data, "required", true, false);
    }
}