//
// Created by tyler on 8/28/21.
//

#include "data_model_field.h"

namespace siphon {

  std::string DataModelField::name() {
    return siphon::parameterParse<std::string>(this->data, siphon::DATA_MODEL_FIELD_NAME);
  }

  std::string DataModelField::description() {
    return siphon::parameterParse<std::string>(this->data, siphon::DATA_MODEL_FIELD_DESCRIPTION);
  }

  SiphonType DataModelField::type() {
    return siphon::parameterParseEnum<siphon::SiphonType>(this->data, siphon::DATA_MODEL_FIELD_TYPE);
  }

}