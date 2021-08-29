//
// Created by tyler on 8/28/21.
//
#include "nlohmann/json.hpp"

#include "siphon_strings.hpp"
#include "data_model_field.h"

#ifndef SIPHON_SRC_COMMON_MODELS_DATA_MODEL_H_
#define SIPHON_SRC_COMMON_MODELS_DATA_MODEL_H_

namespace siphon {
  class DataModel {
    public:
        explicit DataModel(const nlohmann::json& data):
          _data_structure(parameterParseEnum<DataStructure>(data, siphon::DATA_MODEL_DATA_STRUCTURE)),
          _fields(parameterParseArray<DataModelField>(data, siphon::DATA_MODEL_FIELDS)) {};
        DataStructure dataStructure();
        std::vector<DataModelField>* fields();

   private:
        const std::shared_ptr<std::vector<DataModelField>> _fields;
        const DataStructure _data_structure;
  };
}

#endif //SIPHON_SRC_COMMON_MODELS_DATA_MODEL_H_
