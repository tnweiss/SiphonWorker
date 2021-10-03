//
// Created by tyler on 9/28/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_TYPES_INT_TYPE_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_TYPES_INT_TYPE_H_

#include "../../data_type.h"
#include <memory>

static const size_t INT_SIZE = sizeof(int);


/**
 * This class does not manage the memory it is instantiated with
 */
class IntType: public DataType {
 public:
  /////////////////// Overrides ///////////////////
  int8_t type_code() final;
  const char* type_code_extended() final;
  DataType* replicate() final;
  int8_t precision() final;
  std::string to_string() final;

  //////////////////////////////// Assignment ////////////////////////////////
  IntType& operator=(int) final;
  IntType& operator=(float) final;
  IntType& operator=(long) final;
  IntType& operator=(short) final;
  IntType& operator=(const char*) final;
  IntType& operator=(DataType&) final;
  IntType& operator=(std::shared_ptr<DataType>&) final;
  IntType& operator=(std::unique_ptr<DataType>) final;

  //////////////////////////////// Assignment Addition ////////////////////////////////
  IntType& operator+=(DataType&) final;
  IntType& operator+=(int) final;
  IntType& operator+=(float) final;
  IntType& operator+=(long) final;
  IntType& operator+=(short) final;

  //////////////////////////////// Subtraction Assignment ////////////////////////////////
  IntType& operator-=(DataType&) final;
  IntType& operator-=(int) final;
  IntType& operator-=(float) final;
  IntType& operator-=(long) final;
  IntType& operator-=(short) final;

  //////////////////////////////// Data Getters ////////////////////////////////
  int as_int() final;
  int* as_int_ptr() final;

  /////////////////// Constructor / Destructor ///////////////////
  explicit IntType(int*, size_t&);
  explicit IntType(int*);
  ~IntType();

protected:
  const int* data();

 private:
  int* const _data;
};

/**
 * This class will manage the memory it is instantiated with
 */
class IntTypeN: public IntType {
public:
  /////////////////// Constructor / Destructor ///////////////////
  explicit IntTypeN(int);
  ~IntTypeN();
};

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_TYPES_INT_TYPE_H_
