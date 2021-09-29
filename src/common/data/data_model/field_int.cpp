//
// Created by Tyler on 9/26/2021.
//
#include "field_int.h"

int8_t IntField::code() {
  return FIELD_INT_CODE;
}

const char* IntField::extended_code() {
  return FIELD_INT_CODE_EXTENDED;
}

size_t IntField::bytes() {
  return FIELD_INT_BYTES;
}
