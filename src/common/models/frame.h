//
// Created by tyler on 9/2/21.
//
#include <vector>
#include "boost/any.hpp"
#include "boost/serialization/access.hpp"
#include "siphon_strings.hpp"

#ifndef SIPHON_SRC_COMMON_MODELS_FRAME_H_
#define SIPHON_SRC_COMMON_MODELS_FRAME_H_

class frame {
 public:
  std::vector<boost::any> _data;
  const std::vector<siphon::SiphonType>& _data_model;

  char[]* bytes();

  frame(char[]*);
  frame();
 explicit frame(std::vector<siphon::SiphonType>& dataModel): _data_model(dataModel) {
   this->_data = std::vector<boost::any>();
 }
 // bytes in array
 // vector
 // json serialization


  friend class boost::serialization::access;
  // When the class Archive corresponds to an output archive, the
  // & operator is defined similar to <<.  Likewise, when the class Archive
  // is a type of input archive the & operator is defined similar to >>.
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    int z;
    for (int i=0; i<this->_data_model.size(); i++) {
      ar & z;
      this->_data.emplace_back(z);
    }
  }
};

#endif //SIPHON_SRC_COMMON_MODELS_FRAME_H_
