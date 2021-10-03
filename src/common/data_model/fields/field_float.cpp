//
// Created by Tyler on 9/28/2021.
//

#include "field_float.h"

namespace siphon {

int8_t FloatField::code() {
  return FIELD_FLOAT_CODE;
}

const char *FloatField::extended_code() {
  return FIELD_FLOAT_CODE_EXTENDED;
}

size_t FloatField::bytes() {
  return FIELD_FLOAT_BYTES;
}

}

