//
// Created by Tyler on 9/28/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_FLOAT_H_
#define SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_FLOAT_H_

#include "data_model_field.h"
#include <string>

static const char*     FIELD_FLOAT_CODE_EXTENDED = "FLOAT";
static const int8_t    FIELD_FLOAT_CODE = 1;
static const int8_t    FIELD_FLOAT_HEADER[] = {FIELD_FLOAT_CODE, 0, 0, 0, 0};
static const short     FIELD_FLOAT_BYTES = sizeof(float);


class FloatField: public DataModelField {
public:
  ////////////////////////// Meta Data //////////////////////////
  int8_t code() final;
  const char *extended_code() final;
  size_t bytes() final;

  ////////////////////////// Constructors //////////////////////////
  explicit FloatField(const std::string &name)
      : DataModelField((char *)name.c_str(), FIELD_FLOAT_HEADER){};
  explicit FloatField(int8_t* buffer, size_t& offset)
      : DataModelField(buffer, offset){};
};

#endif // SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_FLOAT_H_
