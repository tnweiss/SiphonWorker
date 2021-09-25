//
// Created by Tyler on 9/25/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_DESERIALIZER_DESERIALIZER_H_
#define SIPHON_SRC_COMMON_DATA_DESERIALIZER_DESERIALIZER_H_

#include "../frame/frame.h"

namespace siphon {

class Deserializer {
  virtual siphon::Frame deserialize(void*, size_t) = 0;
};

}


#endif // SIPHON_SRC_COMMON_DATA_DESERIALIZER_DESERIALIZER_H_
