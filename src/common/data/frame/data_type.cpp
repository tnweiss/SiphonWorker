//
// Created by tyler on 9/28/21.
//

#include "data_type.h"

std::string DataType::to_string_helper(const char * type_name, const std::string& value) {
  std::string r_val(type_name);
  r_val.append("(");
  r_val.append(value);
  r_val.append(")");
  return r_val;
}
