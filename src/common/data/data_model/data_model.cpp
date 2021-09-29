//
// Created by Tyler on 9/26/2021.
//

#include "data_model.h"
#include "ser_des.h"
#include "exceptions.h"


DataModel::DataModel(int8_t type) {
  _type = 0;

  for (std::pair<int8_t, const char*> t: DM_TYPES) {
    if (t.first == type) {
      _type = type;
    }
  }

  if (_type == 0) {
    throw siphon::DataModelParseException("Unknown Data Model Type: ",
                                          std::to_string(type).c_str());
  }

  _fields = new std::vector<DataModelField*>();
}

DataModel::DataModel(const char * type_extended) {
  _type = 0;

  for (std::pair<int8_t, const char*> t: DM_TYPES) {
    if (t.second == type_extended) {
      _type = t.first;
    }
  }

  if (_type == 0) {
    throw siphon::DataModelParseException("Unknown Data Model Extended Code: ",
                                          type_extended);
  }

  _fields = new std::vector<DataModelField*>();
}

DataModel::DataModel(int8_t *buffer) {
  _type = 0;

  for (std::pair<int8_t, const char*> t: DM_TYPES) {
    if (t.first == *buffer) {
      _type = t.first;
    }
  }

  if (_type == 0) {
    throw siphon::DataModelParseException("Unknown Data Model Code: ",
                                          std::to_string(*buffer).c_str());
  }

  buffer += 1;

  _fields = new std::vector<DataModelField*>();
  size_t offset = 0;
  unsigned short num_fields = *(unsigned short*)buffer;
  _fields->reserve(num_fields);

  buffer += sizeof(unsigned short);

  DataModelField* dmf;
  for (int i=0; i<num_fields; i++) {
    dmf = des_dmf(buffer + offset, offset);

    _fields->push_back(dmf);
  }

}

DataModel::~DataModel() {
  for (DataModelField* dmf: *_fields) {
    delete dmf;
  }
  delete _fields;
}

int8_t DataModel::model_type() {
  return _type;
}

const char *DataModel::model_type_extended() {
  for (std::pair<int8_t, const char*> dm_type: DM_TYPES) {
    if (dm_type.first == _type) {
      return dm_type.second;
    }
  }

  exit(1);
}
