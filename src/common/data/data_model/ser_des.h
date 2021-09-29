//
// Created by Tyler on 9/27/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DATA_MODEL_SER_DES_H_
#define SIPHON_SRC_COMMON_DATA_DATA_MODEL_SER_DES_H_

#include "exceptions.h"
#include "data_model_field.h"

#include "field_int.h"
#include "field_float.h"


static DataModelField *des_dmf(int8_t *buffer, size_t &offset) {
  switch (*buffer) {
  case FIELD_INT_CODE:
    return new IntField(buffer, offset);
  case FIELD_FLOAT_CODE:
    return new FloatField(buffer, offset);
  default:
    throw siphon::UnknownDataModelCodeException(*buffer);
  }

}
#endif // SIPHON_SRC_COMMON_DATA_DATA_MODEL_SER_DES_H_
