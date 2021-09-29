//
// Created by tyler on 9/28/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_TYPES_INT_TYPE_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_TYPES_INT_TYPE_H_

#include "../siphon_type.h"

class IntType: public SiphonType {
 public:
  /////////////////// Overrides ///////////////////
  int8_t type_code() final;
  const char* type_code_extended() final;

  /////////////////// Setters ///////////////////
  IntType& operator=(int) final;
  IntType& operator=(SiphonType&);

  /////////////////// Getters ///////////////////
  int as_int() final;
  int* as_int_ptr() final;

  /////////////////// Rule of 5 ///////////////////
  explicit IntType(int* data): _data(data){ };
  ~IntType();



 private:
  int* const _data;
};

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_TYPES_INT_TYPE_H_
