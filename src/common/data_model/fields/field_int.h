//
// Created by Tyler on 9/26/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_INT_FIELD_H_
#define SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_INT_FIELD_H_

#include "../data_model_field.h"
#include <string>

static const char*     FIELD_INT_CODE_EXTENDED = "INT";
static const int8_t    FIELD_INT_CODE = 0;
static const int8_t    FIELD_INT_HEADER[] = {FIELD_INT_CODE, 0, 0, 0, 0};
static const short     FIELD_INT_BYTES = sizeof(int);


class IntField: public DataModelField {
public:
  ////////////////////////// Meta Data //////////////////////////
  int8_t code() final;
  const char *extended_code() final;
  size_t bytes() final;

  ////////////////////////// Constructors //////////////////////////
  explicit IntField(const std::string &name)
      : DataModelField((char *)name.c_str(), FIELD_INT_HEADER){};
  explicit IntField(int8_t* buffer, size_t& offset)
      : DataModelField(buffer, offset){};
};

#endif // SIPHON_SRC_COMMON_DATA_DATA_MODEL_FIELD_INT_FIELD_H_
