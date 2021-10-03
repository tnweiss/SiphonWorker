//
// Created by Tyler on 10/1/2021.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SET_SIPHON_FRAME_SET_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SET_SIPHON_FRAME_SET_H_

#include <vector>

#include "../writer/writer.h"
#include "frame_collection.h"

namespace siphon {

/**
 *
 * @param ex
 * @param task_id
 * @param step
 * @param frame
 * @param processor
 * @param exception_sink
 */
static void handle_process_exception(std::exception* ex, long task_id,
                                     long step, Frame* frame,
                                     Processor* processor,
                                     Writer* exception_sink) {
  std::string ex_string("PROCESSING ERROR\nTask(");
  ex_string.append(std::to_string(task_id));
  ex_string.append(")\nStep(");
  ex_string.append(std::to_string(step));
  ex_string.append(")\nProcessor:\n");
  ex_string.append(processor->to_string());
  ex_string.append("Frame:\n");
  ex_string.append(frame->to_string());
  ex_string.append("Exception: ");
  ex_string.append(ex->what());

  exception_sink->write((int8_t*)ex_string.data(), ex_string.length());
}

class SiphonFrameSet: public FrameSet {
  SiphonFrameSet(int8_t);
  ~SiphonFrameSet();

  void deserialize(int8_t* buffer, size_t buffer_size,
                   DataModel* data_model) final;

private:
  std::vector<std::vector<Frame*>*>* _data;
  size_t _data_size;
  const int8_t _threads;
};

}


#endif // SIPHON_SRC_COMMON_DATA_FRAME_SET_SIPHON_FRAME_SET_H_
