//
// Created by Tyler on 9/25/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_WRITER_WRITER_H_
#define SIPHON_SRC_COMMON_DATA_WRITER_WRITER_H_

namespace siphon {

class Writer {
public:
  virtual void write(int8_t*, size_t) = 0;
};

}
#endif // SIPHON_SRC_COMMON_DATA_WRITER_WRITER_H_
