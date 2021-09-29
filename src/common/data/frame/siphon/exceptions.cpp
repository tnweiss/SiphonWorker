//
// Created by Tyler on 9/28/2021.
//

#include "exceptions.h"
#include <cstdarg>

siphon::NotImplementedException::NotImplementedException(const char* type_code_extended, const char* method) {
  msg = std::string("Method: '");
  msg.append(method);
  msg.append("' has not been implemented in ");
  msg.append(type_code_extended);
}

const char *siphon::NotImplementedException::what() const noexcept {
  return msg.c_str();
}
