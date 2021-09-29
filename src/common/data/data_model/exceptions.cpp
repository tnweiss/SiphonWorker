//
// Created by Tyler on 9/28/2021.
//

#include "exceptions.h"
#include <cstdarg>

siphon::DataModelParseException::DataModelParseException(const char* msg...) {
  va_list args;

  this->msg = std::string();

  char* tmp;
  va_start(args, msg);
  while (*tmp != '\0') {
    this->msg.append(tmp);
  }
  va_end(args);
}

const char *siphon::DataModelParseException::what() const noexcept {
  return msg.c_str();
}

siphon::UnknownDataModelCodeException::UnknownDataModelCodeException(
    const int8_t unknown_code) {
  msg = std::string("Unable to deserialize field with unknown code: ");
  msg.append(std::to_string(unknown_code));
}

const char *siphon::UnknownDataModelCodeException::what() const noexcept {
  return msg.c_str();
}
