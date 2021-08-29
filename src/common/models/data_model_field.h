//
// Created by tyler on 8/28/21.
//
#include "nlohmann/json.hpp"

#include "siphon_strings.hpp"
#include "parsing/parameter_parse.h"

#ifndef SIPHON_SRC_COMMON_MODELS_DATA_MODEL_FIELD_H_
#define SIPHON_SRC_COMMON_MODELS_DATA_MODEL_FIELD_H_

namespace siphon {
  class DataModelField {
     public:
      explicit DataModelField(const nlohmann::json& _data): data(_data) {  };
      std::string name();
      SiphonType type();
      std::string description();

     private:
      const nlohmann::json& data;
  };
}

#endif //SIPHON_SRC_COMMON_MODELS_DATA_MODEL_FIELD_H_
