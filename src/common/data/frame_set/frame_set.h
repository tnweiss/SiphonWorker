//
// Created by tyler on 10/1/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SET_FRAME_SET_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SET_FRAME_SET_H_

namespace siphon {
class FrameSet {
  /**
   * Read from buffer
   */
  virtual void deserialize(void*, size_t) = 0;

  /**
   * Write to buffer
   * @return
   */
  virtual std::pair<void*, size_t > serialize() = 0;

  /**
   * Apply operations to the frames in the frame set
   */
  virtual void apply(void*) = 0;

  /**
   * get the size of the frame set
   * @return
   */
  virtual size_t bytes() = 0;
};
}

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SET_FRAME_SET_H_
