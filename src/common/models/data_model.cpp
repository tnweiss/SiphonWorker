//
// Created by tyler on 8/28/21.
//

#include "data_model.h"


namespace siphon {
  DataStructure DataModel::dataStructure() {
    return this->_data_structure;
  }

  std::vector<DataModelField>* DataModel::fields() {
    return this->_fields.get();
  }
}