//
// Created by tyler on 8/30/21.
//
#include "nlohmann/json.hpp"

#include "processing/parser.hpp"
#include "processing/processor.hpp"
#include "processing/filters/processors/gt.h"

#ifndef SIPHON_SRC_COMMON_VALUEFILTERS_PARSERS_GTPARSER_H_
#define SIPHON_SRC_COMMON_VALUEFILTERS_PARSERS_GTPARSER_H_

namespace siphon {
class gtParser : Parser {
  std::unique_ptr<Processor> parse(nlohmann::json &, DataModel &) final;
};
}

#endif //SIPHON_SRC_COMMON_VALUEFILTERS_PARSERS_GTPARSER_H_
