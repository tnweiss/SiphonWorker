//
// Created by Tyler on 9/25/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_SERIALIZER_SERIALIZER_H_
#define SIPHON_SRC_COMMON_DATA_SERIALIZER_SERIALIZER_H_

namespace siphon {

class Serializer {
  virtual std::pair<void*, size_t > serialize(siphon::Frame) = 0;
};

}
#endif // SIPHON_SRC_COMMON_DATA_SERIALIZER_SERIALIZER_H_
