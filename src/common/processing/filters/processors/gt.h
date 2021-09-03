//
// Created by tyler on 8/30/21.
//
#include "nlohmann/json.hpp"

#include "processing/processor.hpp"

#ifndef SIPHON_SRC_COMMON_VALUEFILTERS_GT_H_
#define SIPHON_SRC_COMMON_VALUEFILTERS_GT_H_

namespace siphon {
class gt : Processor {
 public:
  void process(std::vector<nlohmann::json> &) final;
  void process(nlohmann::json&) final;

  /**
   * trusted constructor
   * @param leftIndex
   * @param leftValue
   * @param leftKey
   * @param rightIndex
   * @param rightValue
   * @param rightKey
   */
  gt(const int* leftIndex, const float* leftValue, std::string* leftKey, const int* rightIndex,
     const float* rightValue, const std::string* rightKey): _leftIndex(leftIndex), _leftValue(leftValue),
     _leftKey(leftKey), _rightIndex(rightIndex), _rightValue(rightValue), _rightKey(rightKey) {

    // make sure we have a left val
    if (this->_leftIndex == nullptr && this->_leftValue == nullptr && this->_leftKey == nullptr) {
      //TODO threow exception
    } else if (this->_rightIndex == nullptr && this->_rightValue == nullptr && this->_rightKey == nullptr) {
      //TODO throw exception
    }

  };
 private:
  const int* _leftIndex;
  const float* _leftValue;
  const std::string* _leftKey;

  const int* _rightIndex;
  const float* _rightValue;
  const std::string* _rightKey;
};
}

#endif //SIPHON_SRC_COMMON_VALUEFILTERS_GT_H_
