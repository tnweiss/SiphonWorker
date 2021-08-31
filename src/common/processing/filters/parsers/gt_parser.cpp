//
// Created by tyler on 8/30/21.
//

#include "gt_parser.h"

namespace siphon {
std::unique_ptr<Processor> gtParser::parse(nlohmann::json &, DataModel &) {
  return nullptr;
}
}