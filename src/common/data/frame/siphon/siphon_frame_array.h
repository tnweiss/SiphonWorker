//
// Created by tyler on 9/30/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_FRAME_ARRAY_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_FRAME_ARRAY_H_

#include "../frame.h"
#include "../data_type.h"
#include "../../data_model/data_model.h"

#include <vector>

class SiphonFrameArray: Frame {
  SiphonFrameArray(DataModel*, size_t*, int8_t*);


 private:
  const DataModel* _data_model;
  size_t* const data_size;
  std::vector<DataType*>* const _data;
};

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_FRAME_ARRAY_H_
