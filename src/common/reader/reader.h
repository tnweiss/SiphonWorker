//
// Created by Tyler on 9/25/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_READER_READER_H_
#define SIPHON_SRC_COMMON_DATA_READER_READER_H_

#include <utility>

namespace siphon {

class Reader {
  /**
   * Read from the source into a buffer
   * @return a pointer to the buffer + the size of the buffer
   */
  virtual std::pair<void*, size_t > read() = 0;
};

}

#endif // SIPHON_SRC_COMMON_DATA_READER_READER_H_
