//
// Created by tyler on 9/28/21.
//

#include "int_type.h"

int8_t IntType::type_code() {
  return TYPE_INT_CODE;
}

const char *IntType::type_code_extended() {
  return TYPE_INT_CODE_EXTENDED;
}

IntType& IntType::operator=(int new_val) {
  *_data = new_val;
  return *this;
}

int IntType::as_int() {
  return *_data;
}

int *IntType::as_int_ptr() {
  return _data;
}


IntType& IntType::operator=(SiphonType& st) {
  switch (st.type_code()) {
    case TYPE_INT_CODE:
      *_data = *st.as_int_ptr();
      break;
  }
  return *this;
}

IntType::~IntType() = default;


