//
// Created by tyler on 8/30/21.
//
#include <map>
#include <vector>
#include "boost/any.hpp"

#include "models/data_model.h"

#ifndef SIPHON_SRC_VALUEFILTER_VALUE_FILTER_H_
#define SIPHON_SRC_VALUEFILTER_VALUE_FILTER_H_
namespace siphon {

class Processor {
 public:
  /**
   * Determine if the provided data passes the given test (array)
   * @return
   */
  virtual void process(std::vector<boost::any> &) = 0;

  /**
 * Determine if the provided data passes the given test (object)
 * @return
 */
  virtual void process(std::map<std::string, boost::any> &) = 0;
};

}

#endif //SIPHON_SRC_VALUEFILTER_VALUE_FILTER_H_
