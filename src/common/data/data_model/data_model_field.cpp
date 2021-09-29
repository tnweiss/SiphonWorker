//
// Created by Tyler on 9/26/2021.
//
#include "data_model_field.h"
#include "boost/format.hpp"
#include <iostream>


const char *DataModelField::name() {
  return _name;
}

DataModelField::DataModelField(int8_t *buffer, size_t &offset) {
  _header = new int8_t [DMF_HEADER_LEN];
  memcpy(_header, buffer, DMF_HEADER_LEN);

  buffer += DMF_HEADER_LEN;
  _name_len = strlen((char*)buffer) + 1;

  _name = new char[DMF_HEADER_LEN];
  memcpy(_name, buffer, _name_len);

  offset += DMF_HEADER_LEN + _name_len;
}

void DataModelField::write_to_buffer(int8_t *buffer, size_t &offset) {
  memcpy(buffer, _header, DMF_HEADER_LEN);
  memcpy(buffer + DMF_HEADER_LEN, _name, _name_len);
  offset += DMF_HEADER_LEN + _name_len;
}

DataModelField::~DataModelField() {
  delete[] _header;
  delete[] _name;
}

DataModelField::DataModelField(const DataModelField& other) {
  _name = nullptr;
  _header = nullptr;
  _name_len = 0;
  std::cout << "\n\n\nNO COPYING DataModelField\n\n\n" << std::endl;
  exit(1);
}

DataModelField::DataModelField(DataModelField&& other) noexcept {
  _name = other._name;
  _name_len = other._name_len;
  _header = other._header;

  other._name = nullptr;
  other._header = nullptr;
}

DataModelField &DataModelField::operator=(const DataModelField &other) {
  if (&other == this) {
    return *this;
  }

  _name = nullptr;
  _header = nullptr;
  _name_len = 0;
  std::cout << "\n\n\nNO COPYING DataModelField\n\n\n" << std::endl;
  return *this;
}

DataModelField &DataModelField::operator=(DataModelField &&other) noexcept {
  _name = other._name;
  _header = other._header;
  _name_len = other._name_len;
  other._header = nullptr;
  other._name = nullptr;
  return *this;
}

DataModelField::DataModelField(char* name, const int8_t header[]) {
  _header = new int8_t[DMF_HEADER_LEN];
  memcpy(_header, header, DMF_HEADER_LEN);

  _name_len = strlen(name) + 1;

  _name = new char[_name_len];
  memcpy(_name, name, _name_len);
}
