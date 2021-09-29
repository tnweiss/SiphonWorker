//
// Created by Tyler on 9/28/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DATA_MODEL_EXCEPTIONS_H_
#define SIPHON_SRC_COMMON_DATA_DATA_MODEL_EXCEPTIONS_H_
#include <exception>
#include <string>

namespace siphon {

class DataModelParseException : public std::exception {
public:
  explicit DataModelParseException(const char* msg...);
  [[nodiscard]] const char *what() const noexcept override;
private:
  std::string msg;
};

class UnknownDataModelCodeException : public std::exception {
public:
  explicit UnknownDataModelCodeException(const int8_t);
  [[nodiscard]] const char *what() const noexcept override;
private:
  std::string msg;
};

}

#endif // SIPHON_SRC_COMMON_DATA_DATA_MODEL_EXCEPTIONS_H_
