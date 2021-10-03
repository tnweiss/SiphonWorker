//
// Created by Tyler on 10/1/2021.
//

#include "siphon_frame_collection.h"
#include "../frame/siphon/siphon_frame_array.h"
#include <cmath>

siphon::SiphonFrameSet::SiphonFrameSet(int8_t threads): _threads(threads) {
  _data = new std::vector<std::vector<Frame*>*>();

  for (int i=0; i<_threads; i++) {
    _data->push_back(new std::vector<Frame*>());
  }

  _data_size = 0;
}

siphon::SiphonFrameSet::~SiphonFrameSet() {
  if (_data == nullptr) {
    return;
  }

  for (std::vector<Frame*>* v: *_data) {
    for (Frame* f: *v) {
      delete f;
    }
    delete v;
  }
  delete _data;
}

/**
 * First 8 bytes represent the number of elements
 * Second 8 bytes represent the size of the data in bytes
 * Rest of bytes belong to frame data
 * @param buffer
 * @param buffer_size
 * @param data_model
 */
void siphon::SiphonFrameSet::deserialize(int8_t *buffer, size_t buffer_size,
                                         DataModel *data_model) {
  // used to determine the number of elements per thread
  unsigned long element_count = *(unsigned long*)buffer;

  // can be used to take the size of the frames into account
  unsigned long size_bytes = *(unsigned long*)(buffer + sizeof(unsigned long));

  buffer += sizeof(unsigned long) * 2;

  // divide elements by number of threads and round that number up
  const size_t max_per_thread = std::ceil(static_cast<float>(element_count)
                                          / static_cast<float>(_threads));

  size_t current_thread_element_count;
  size_t processed_elements = 0;
  SiphonFrameArray* sfa;
  for (int thread_num=0; thread_num<_threads; thread_num++) {
    // the current thread count should be the smallest of max per thread or
    //   the number of remaining threads
    current_thread_element_count = static_cast<size_t>(
        std::min(max_per_thread, element_count - processed_elements));

    // mark the number of processed elements
    processed_elements += current_thread_element_count;

    for (int i=0; i<current_thread_element_count; i++) {
      // initialize the frame with the data model, size, and the buffer offset by the size
      sfa = new SiphonFrameArray(data_model,
                                 &_data_size,
                                 buffer + _data_size);

      // add that frame to the current thread
      _data->at(thread_num)->push_back(sfa);
    }
  }
}

