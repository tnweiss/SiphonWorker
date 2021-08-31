//
// Created by tyler on 8/30/21.
//
#include "processor.hpp"

#ifndef SIPHON_SRC_COMMON_VALUEFILTERS_PARSER_H_
#define SIPHON_SRC_COMMON_VALUEFILTERS_PARSER_H_
namespace siphon {
class Parser {
 public:
  /**
   * Parse fields out of
   * @return
   */
  virtual std::unique_ptr<Processor> parse(nlohmann::json&, DataModel&) = 0;

  /**
   *
   * @return
   */
  virtual std::unique_ptr<Processor> parse(nlohmann::json&) = 0;

};
}
#endif //SIPHON_SRC_COMMON_VALUEFILTERS_PARSER_H_
