//
// Created by tyler on 9/28/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_H_

#include "exceptions.h"

const static int TYPE_INT_CODE = 0;

const static char* TYPE_INT_CODE_EXTENDED = "Int";


class SiphonType {
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

  //////////////////////////////// Operators ////////////////////////////////
  /**
 * Siphon Type setter
 * @return
 */
  virtual SiphonType& operator=(int) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=int)");
  };

  /**
 * Siphon Type setter
 * @return
 */
  virtual bool operator<(SiphonType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Less Than (<SiphonType)");
  };

  virtual SiphonType& operator=(SiphonType&) {
    throw siphon::NotImplementedException(type_code_extended(), "Assignment (=SiphonType)");
  };

  //////////////////////////////// Data Getters ////////////////////////////////
  /**
   *
   * @return
   */
  virtual int* as_int_ptr() {
    throw siphon::NotImplementedException(type_code_extended(), "as_int_ptr");
  };

  /**
   *
   * @return
   */
  virtual int as_int() {
    throw siphon::NotImplementedException(type_code_extended(), "as_int_ptr");
  };

};

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_H_
