//
// Created by Tyler on 9/27/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DATA_MODEL_SER_DES_H_
#define SIPHON_SRC_COMMON_DATA_DATA_MODEL_SER_DES_H_

#include "../data_model_exceptions.h"
#include "../data_model_field.h"

#include "field_int.h"
#include "field_float.h"

namespace siphon {

/**
 * Use the 8 bit code to deserialize the field
 * @param buffer
 * @param offset
 * @return
 */
static DataModelField *des_dmf(int8_t *buffer, size_t &offset) {
  switch (*buffer) {
  case FIELD_INT_CODE:
    return new IntField(buffer, offset);
  case FIELD_FLOAT_CODE:
    return new FloatField(buffer, offset);
  default:
    throw UnknownDataModelCodeException(*buffer);
  }

}

}

#endif // SIPHON_SRC_COMMON_DATA_DATA_MODEL_SER_DES_H_
