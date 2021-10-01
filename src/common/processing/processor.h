//
// Created by tyler on 8/30/21.
//
#ifndef SIPHON_SRC_VALUEFILTER_VALUE_FILTER_H_
#define SIPHON_SRC_VALUEFILTER_VALUE_FILTER_H_

#include "frame/frame.h"


namespace siphon {

class Processor {
 public:
  /**
   * Determine if the provided data passes the given test
   * @return
   */
  virtual bool process(Frame*) = 0;
};

}

#endif //SIPHON_SRC_VALUEFILTER_VALUE_FILTER_H_
