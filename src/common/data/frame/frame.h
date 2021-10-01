//
// Created by tyler on 9/30/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_FRAME_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_FRAME_H_

#include "data_type.h"

class Frame {
  /**
   * Get the data provided the accessor key
   * @return
   */
  virtual DataType* get(std::string&) = 0;

  /**
   * Insert / Update data
   */
  virtual void set(std::string&, DataType*) = 0;

  /**
   * delete the data from the frame
   */
  virtual void pop(std::string&) = 0;
};

#endif //SIPHON_SRC_COMMON_DATA_FRAME_FRAME_H_
