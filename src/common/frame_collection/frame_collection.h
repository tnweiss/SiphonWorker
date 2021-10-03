//
// Created by tyler on 10/1/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SET_FRAME_SET_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SET_FRAME_SET_H_

#include "../processing/processor.h"
#include "../data_model/data_model.h"
#include "../writer/writer.h"

namespace siphon {
class FrameSet {
  /**
   * Deserialize the Frame Set from a buffer. This should transfer ownership of
   *    the data to the set
   * @param buffer pointer to the data
   * @param buffer_size size of the incoming data
   * @param data_model data model to deserialize the data
   */
  virtual void deserialize(int8_t* buffer, size_t buffer_size,
                           DataModel* data_model) = 0;

  /**
   * Write to buffer
   * @return the pointer to the buffer and the size of the buffer
   */
  virtual std::pair<int8_t*, size_t > serialize() = 0;

  /**
   * Apply processor to all of the frames
   */
  virtual void apply(long query_id, long job_id, long step, Writer* error_sink,
                     Processor* processor) = 0;

  /**
   * get the size of the frame set
   * @return
   */
  virtual size_t bytes() = 0;

  /**
   * get the size of the frame set
   * @return
   */
  virtual size_t dropped_frames() = 0;
};
}

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SET_FRAME_SET_H_
