//
// Created by tyler on 9/28/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_H_

#include "frame/siphon/exceptions.h"
#include <string>
#include <memory>
#include <type_traits>

const static int TYPE_SHORT_CODE = 1;
const static int TYPE_INT_CODE = 2;
const static int TYPE_LONG_CODE = 3;
const static int TYPE_FLOAT_CODE = 4;
const static int TYPE_DOUBLE_CODE = 4;
const static int TYPE_STRING_CODE = 5;
const static int TYPE_CHAR_CODE = 6;
const static int TYPE_BOOL_CODE = 7;

const static int8_t TYPE_SHORT_PRECISION = 1;
const static int8_t TYPE_INT_PRECISION = 5;
const static int8_t TYPE_LONG_PRECISION = 10;
const static int8_t TYPE_FLOAT_PRECISION = 15;
const static int8_t TYPE_DOUBLE_PRECISION = 20;

const static char* TYPE_SHORT_CODE_EXTENDED = "Short";
const static char* TYPE_INT_CODE_EXTENDED = "Int";
const static char* TYPE_LONG_CODE_EXTENDED = "Long";
const static char* TYPE_FLOAT_CODE_EXTENDED = "Float";
const static char* TYPE_DOUBLE_CODE_EXTENDED = "Double";
const static char* TYPE_STRING_CODE_EXTENDED = "String";
const static char* TYPE_CHAR_CODE_EXTENDED = "Char";
const static char* TYPE_BOOL_CODE_EXTENDED = "Boolean";


class DataType {
 public:
  /**
   * Get the type code for the column
   * @return
   */
  virtual int8_t type_code() = 0;

  /**
 * Get the type code for the column
 * @return
 */
  virtual const char* type_code_extended() = 0;

  /**
   * duplicate the data
   * @return
   */
  virtual DataType* replicate() = 0;

  /**
   * return a to string representation in the format of
   *  <TYPE>(<VALUE>)
   * @return
   */
  virtual std::string to_string() = 0;

  /**
   * get the precision of the data, used to determine the return value
   * @return
   */
  virtual int8_t precision() {
    throw siphon::NotImplementedException(type_code_extended(), "precision");
  };

  //////////////////////////////// Assignment ////////////////////////////////
  virtual DataType& operator=(const int) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=int)");
  };

  virtual DataType& operator=(const float) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=float)");
  };

  virtual DataType& operator=(const long) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=long)");
  };

  virtual DataType& operator=(const short) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=short)");
  };

  virtual DataType& operator=(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=char*)");
  };

  virtual DataType& operator=(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=bool)");
  };

  virtual DataType& operator=(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=DataType)");
  };

  virtual DataType& operator=(std::shared_ptr<DataType>&) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=DataType)");
  };

  virtual DataType& operator=(std::unique_ptr<DataType>) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=DataType)");
  };

  //////////////////////////////// Addition Assignment ////////////////////////////////

  virtual DataType& operator+=(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Addition Assignment (+=DataType)");
  };

  virtual DataType& operator+=(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Addition Assignment (+=int)");
  };

  virtual DataType& operator+=(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Addition Assignment (+=float)");
  };

  virtual DataType& operator+=(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Addition Assignment (+=long)");
  };

  virtual DataType& operator+=(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Addition Assignment (+=short)");
  };

  virtual DataType& operator+=(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Addition Assignment (+=char)");
  };

  virtual DataType& operator+=(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Addition Assignment (+bool)");
  };

  //////////////////////////////// Subtraction Assignment ////////////////////////////////
  virtual DataType& operator-=(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Subtraction Assignment (-=DataType)");
  };

  virtual DataType& operator-=(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Subtraction Assignment (-=int)");
  };

  virtual DataType& operator-=(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Subtraction Assignment (-=float)");
  };

  virtual DataType& operator-=(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Subtraction Assignment (-=long)");
  };

  virtual DataType& operator-=(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Subtraction Assignment (-=short)");
  };

  virtual DataType& operator-=(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Subtraction Assignment (-=char)");
  };

  virtual DataType& operator-=(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Subtraction Assignment (-bool)");
  };

  //////////////////////////////// Multiplication Assignment ////////////////////////////////
  virtual DataType& operator*=(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Multiplication Assignment (*=DataType)");
  };

  virtual DataType& operator*=(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Multiplication Assignment (*=int)");
  };

  virtual DataType& operator*=(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Multiplication Assignment (*=float)");
  };

  virtual DataType& operator*=(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Multiplication Assignment (*=long)");
  };

  virtual DataType& operator*=(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Multiplication Assignment (*=short)");
  };

  virtual DataType& operator*=(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Multiplication Assignment (*=char)");
  };

  virtual DataType& operator*=(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Multiplication Assignment (*=bool)");
  };

  //////////////////////////////// Division Assignment ////////////////////////////////
  virtual DataType& operator/=(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Division Assignment (/=DataType)");
  };

  virtual DataType& operator/=(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Division Assignment (/=int)");
  };

  virtual DataType& operator/=(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Division Assignment (/=float)");
  };

  virtual DataType& operator/=(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Division Assignment (/=long)");
  };

  virtual DataType& operator/=(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Division Assignment (/=short)");
  };

  virtual DataType& operator/=(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Division Assignment (/=char)");
  };

  virtual DataType& operator/=(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Division Assignment (/=bool)");
  };

  //////////////////////////////// Comparison ////////////////////////////////
  virtual bool operator==(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Equals (==DataType)");
  };

  virtual bool operator==(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Equals (==int)");
  };

  virtual bool operator==(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Equals (==float)");
  };

  virtual bool operator==(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Equals (==long)");
  };

  virtual bool operator==(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Equals (==short)");
  };

  virtual bool operator==(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Equals (==char)");
  };

  virtual bool operator==(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Equals (==bool)");
  };

  //////////////////////////////// Less Than ////////////////////////////////
  virtual bool operator<(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<DataType)");
  };

  virtual bool operator<(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<int)");
  };

  virtual bool operator<(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<float)");
  };

  virtual bool operator<(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<long)");
  };

  virtual bool operator<(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<short)");
  };

  virtual bool operator<(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<char)");
  };

  virtual bool operator<(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<bool)");
  };

  //////////////////////////////// Less Than Equal ////////////////////////////////
  virtual bool operator<=(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than Equal (<=DataType)");
  };

  virtual bool operator<=(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than Equal (<=int)");
  };

  virtual bool operator<=(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than Equal (<=float)");
  };

  virtual bool operator<=(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than Equal (<=long)");
  };

  virtual bool operator<=(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than Equal (<=short)");
  };

  virtual bool operator<=(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than Equal (<=char)");
  };

  virtual bool operator<=(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than Equal (<=bool)");
  };

  //////////////////////////////// Greater Than ////////////////////////////////
  virtual bool operator>(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than (>DataType)");
  };

  virtual bool operator>(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than (>int)");
  };

  virtual bool operator>(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than (>float)");
  };

  virtual bool operator>(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than (>long)");
  };

  virtual bool operator>(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than (>short)");
  };

  virtual bool operator>(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than (>char)");
  };

  virtual bool operator>(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than (>bool)");
  };

  //////////////////////////////// Greater Than Equal ////////////////////////////////
  virtual bool operator>=(DataType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than Equal (>=DataType)");
  };

  virtual bool operator>=(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than Equal (>=int)");
  };

  virtual bool operator>=(float) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than Equal (>=float)");
  };

  virtual bool operator>=(long) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than Equal (>=long)");
  };

  virtual bool operator>=(short) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than Equal (>=short)");
  };

  virtual bool operator>=(const char*) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than Equal (>=char)");
  };

  virtual bool operator>=(bool) {
    throw siphon::NotImplementedException(type_code_extended(), "Greater Than Equal (>=bool)");
  };

  //////////////////////////////// Cast ////////////////////////////////
  virtual explicit operator double() {
    throw siphon::NotImplementedException(type_code_extended(), "Cast (double)");
  };

  virtual explicit operator int() {
    throw siphon::NotImplementedException(type_code_extended(), "Cast (int)");
  };

  virtual explicit operator long() {
    throw siphon::NotImplementedException(type_code_extended(), "Cast (long)");
  };

  virtual explicit operator short() {
    throw siphon::NotImplementedException(type_code_extended(), "Cast (short)");
  };

  virtual explicit operator float() {
    throw siphon::NotImplementedException(type_code_extended(), "Cast (float)");
  };

  //////////////////////////////// Data Getters ////////////////////////////////
  virtual int* as_int_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_int_ptr");
  };

  virtual int as_int() {
    throw siphon::NotImplementedException(type_code_extended(), "as_int");
  };

  virtual short* as_short_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_short_ptr");
  };

  virtual short as_short() {
    throw siphon::NotImplementedException(type_code_extended(), "as_short");
  };

  virtual int* as_long_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_long_ptr");
  };

  virtual int as_long() {
    throw siphon::NotImplementedException(type_code_extended(), "as_long");
  };

  virtual float* as_float_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_float_ptr");
  };

  virtual float as_float() {
    throw siphon::NotImplementedException(type_code_extended(), "as_float");
  };

  virtual char* as_string_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_string_ptr");
  };

  virtual std::string as_string() {
    throw siphon::NotImplementedException(type_code_extended(), "as_string");
  };

  virtual char* as_char_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_char_ptr");
  };

  virtual char as_char() {
    throw siphon::NotImplementedException(type_code_extended(), "as_char");
  };

  virtual bool* as_bool_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_bool_ptr");
  };

  virtual bool as_bool() {
    throw siphon::NotImplementedException(type_code_extended(), "as_bool");
  };

 protected:
  std::string to_string_helper(const char*, const std::string&);
};

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_H_
