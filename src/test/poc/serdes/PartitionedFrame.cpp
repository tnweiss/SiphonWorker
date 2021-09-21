//
// Created by tyler on 9/19/21.
//

#include "PartitionedFrame.h"
#include <algorithm>
#include <thread>

void add_to_data (PyObject*, std::vector<long*>& data, size_t start_idx, size_t num_elements) {

}

void ttt() {

}


PFrame::PFrame(PyObject* data, size_t num_threads) {
  _data = new std::vector<std::vector<long*>>();
  _data->reserve(num_threads);

  const size_t data_size = PyList_Size(data);
  const size_t max_per_thread = std::ceil(data_size / num_threads);

  size_t current_idx = 0;
  std::vector<std::thread> t{};
  t.reserve(num_threads);

  for (int i=0; i<num_threads; i++, current_idx += max_per_thread) {
    _data->emplace_back();
    //add_to_data(data, _data->at(i), current_idx, std::min(max_per_thread, data_size - current_idx));
    t.emplace_back(ttt);
  }

  for (std::thread& th: t) {
    th.join();
  }

}

PFrame::PFrame(void*, const size_t) {

}

PFrame::PFrame(const PFrame &) {

}

PFrame::PFrame(PFrame &&) noexcept {

}

PFrame &PFrame::operator=(const PFrame &) {
  return *this;
}

PFrame PFrame::operator=(PFrame &&) noexcept {
  return PFrame(nullptr);
}

PFrame::PFrame(void *) {

}

DataContainer PFrame::data_container() const {
  return DataContainer();
}

PFrame::~PFrame() {

}

const long *const PFrame::at(size_t index) {
  return nullptr;
}

const size_t PFrame::size() {
  return 0;
}

//////////////////////// Partitioned Frame ////////////////////////
bool PartitionedFrame::test(void *, PyObject *) {
  return true;
}

void PartitionedFrame::delete_deserialized_data(void *) {

}

DataContainer PartitionedFrame::serialize(void *) {
  return DataContainer();
}

void *PartitionedFrame::deserialize(DataContainer &) {
  return nullptr;
}

DataContainer PartitionedFrame::serialize(PyObject *) {
  return DataContainer();
}

const char *PartitionedFrame::type() {
  return "PFrame-XP" ;
}
