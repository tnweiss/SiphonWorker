//
// Created by tyler on 9/30/21.
//

#include "siphon_frame_array.h"

SiphonFrameArray::SiphonFrameArray(DataModel * data_model, size_t * data_set_size, int8_t *):
  _data(new std::vector<DataType*>()), _data_size(data_set_size), _data_model(data_model) {

}

SiphonFrameArray::~SiphonFrameArray() {

}

DataType *SiphonFrameArray::get_(std::string & key) {
  return _data->at(*(size_t*)key.c_str());
}

std::string to_string() {
  return "";
}