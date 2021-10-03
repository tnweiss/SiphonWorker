//
// Created by tyler on 9/28/21.
//

#include "int_type.h"


/////////////////// Constructor / Destructor ///////////////////
IntType::IntType(int *data, size_t &offset): _data(data) {
  offset += INT_SIZE;
}

IntType::IntType(int *data): _data(data) { }

IntType::~IntType() = default;

/////////////////// Overrrides ///////////////////

int8_t IntType::type_code() {
  return TYPE_INT_CODE;
}

const char *IntType::type_code_extended() {
  return TYPE_INT_CODE_EXTENDED;
}

DataType *IntType::replicate() {
  return new IntTypeN(*_data);
}

int8_t IntType::precision() {
  return TYPE_INT_PRECISION;
}

//////////////////////////////// Assignment ////////////////////////////////
IntType& IntType::operator=(int new_val) {
  *_data = new_val;
  return *this;
}

IntType &IntType::operator=(float new_val) {
  *_data = static_cast<int>(new_val);
  return *this;
}

IntType &IntType::operator=(long new_val) {
  *_data = static_cast<int>(new_val);
  return *this;
}

IntType &IntType::operator=(short new_val) {
  *_data = static_cast<int>(new_val);
  return *this;
}

IntType &IntType::operator=(const char * new_val) {
  *_data = std::stoi(new_val);
  return *this;
}

IntType& IntType::operator=(DataType& st) {
  switch (st.type_code()) {
    case TYPE_INT_CODE:
      *_data = *st.as_int_ptr();
      break;
    case TYPE_SHORT_CODE:
      *_data = static_cast<int>(st.as_short());
      break;
    case TYPE_LONG_CODE:
      *_data = static_cast<int>(st.as_long());
      break;
    case TYPE_FLOAT_CODE:
      *_data = static_cast<int>(st.as_float());
      break;
    case TYPE_STRING_CODE:
      *_data = std::stoi(st.as_string_ptr());
      break;
    default:
      std::string err(type_code_extended());
      err.append(" No Assignment for ");
      err.append(st.type_code_extended());
      throw siphon::NotImplementedException(type_code_extended(), err.c_str());
  }
  return *this;
}

IntType &IntType::operator=(std::shared_ptr<DataType>& data) {
  this->operator=(*data);
  return *this;
}

IntType &IntType::operator=(std::unique_ptr<DataType> data) {
  this->operator=(*data);
  return *this;
}

std::string IntType::to_string() {
  return to_string_helper(type_code_extended(), std::to_string(*_data));
}

//////////////////////////////// Data Getters ////////////////////////////////

int IntType::as_int() {
  return *_data;
}

int *IntType::as_int_ptr() {
  return _data;
}

//////////////////////////////// Addition Assignment ////////////////////////////////

IntType& IntType::operator+=(DataType& st) {
  switch (st.type_code()) {
    case TYPE_INT_CODE:
      *_data += *st.as_int_ptr();
      break;
    case TYPE_SHORT_CODE:
      *_data += static_cast<int>(st.as_short());
      break;
    case TYPE_LONG_CODE:
      *_data += static_cast<int>(st.as_long());
      break;
    case TYPE_FLOAT_CODE:
      *_data += static_cast<int>(st.as_float());
      break;
    case TYPE_STRING_CODE:
      *_data += std::stoi(st.as_string_ptr());
      break;
    default:
      std::string err(type_code_extended());
      err.append(" No Assignment for ");
      err.append(st.type_code_extended());
      throw siphon::NotImplementedException(type_code_extended(), err.c_str());
  }
  return *this;
}

IntType &IntType::operator+=(int data) {
  *_data += data;
  return *this;
}

IntType &IntType::operator+=(float data) {
  *_data += static_cast<int>(data);
  return *this;
}

IntType &IntType::operator+=(long data) {
  *_data += static_cast<int>(data);
  return *this;
}

IntType &IntType::operator+=(short data) {
  *_data += static_cast<int>(data);
  return *this;
}

//////////////////////////////// Subtraction Assignment ////////////////////////////////

IntType &IntType::operator-=(DataType &st) {
  switch (st.type_code()) {
    case TYPE_INT_CODE:
      *_data -= *st.as_int_ptr();
      break;
    case TYPE_SHORT_CODE:
      *_data -= static_cast<int>(st.as_short());
      break;
    case TYPE_LONG_CODE:
      *_data -= static_cast<int>(st.as_long());
      break;
    case TYPE_FLOAT_CODE:
      *_data -= static_cast<int>(st.as_float());
      break;
    case TYPE_STRING_CODE:
      *_data -= std::stoi(st.as_string_ptr());
      break;
    default:
      std::string err(type_code_extended());
      err.append(" No Assignment for ");
      err.append(st.type_code_extended());
      throw siphon::NotImplementedException(type_code_extended(), err.c_str());
  }
  return *this;
}

IntType &IntType::operator-=(int data) {
  *_data -= data;
  return *this;
}

IntType &IntType::operator-=(float data) {
  *_data -= static_cast<int>(data);
  return *this;
}

IntType &IntType::operator-=(long data) {
  *_data -= static_cast<int>(data);
  return *this;
}

IntType &IntType::operator-=(short data) {
  *_data -= static_cast<int>(data);
  return *this;
}

const int *IntType::data() {
  return _data;
}

IntTypeN::IntTypeN(int data): IntType(new int(data)) {

}

IntTypeN::~IntTypeN() {
  delete data();
}