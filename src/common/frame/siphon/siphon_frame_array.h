//
// Created by tyler on 9/30/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_FRAME_ARRAY_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_FRAME_ARRAY_H_

#include "../frame.h"
#include "../data_type.h"
#include "../../data_model/data_model.h"

#include <vector>

class SiphonFrameArray: public Frame {
public:
  /**
   *
   * @param data_model
   * @param data_size
   * @param buffer
   */
  SiphonFrameArray(DataModel* data_model, size_t* data_size, int8_t* buffer);
  ~SiphonFrameArray();

  DataType* get_(std::string&);
  std::string to_string();
 private:
  const DataModel* _data_model;
  size_t* const _data_size;
  std::vector<DataType*>* const _data;
};

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_FRAME_ARRAY_H_
