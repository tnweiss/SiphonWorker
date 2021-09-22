//
// Created by tyler on 9/19/21.
//

#include "PartitionedFrame.h"
#include <algorithm>
#include <thread>


void add_to_vector (PyObject* data_array, std::vector<long*>* data_partition, size_t start_idx, size_t num_elements) {
  // reserve enough elements for the current data set
  data_partition->reserve(num_elements);

  //
  PyObject* curr_item;
  for (auto i=static_cast<Py_ssize_t>(start_idx); i<num_elements; i++) {
    curr_item = PyList_GetItem(data_array, i);

    data_partition->emplace_back(new long(PyLong_AsLong(curr_item)));
  }
}


void add_to_buffer (PyObject* data_array, void* buffer, size_t start_idx, size_t num_elements) {
  // placeholder for data in the loop
  long curr_item;

  // set the buffer
  auto* buff_i = (int8_t*)buffer;
  buff_i += start_idx * num_elements * sizeof(long);

  for (auto i=static_cast<Py_ssize_t>(start_idx); i<num_elements; i++, buff_i += 4) {
    curr_item = PyLong_AsLong(PyList_GetItem(data_array, i));

    memcpy(buff_i, &curr_item, 4);
  }
}


void add_to_data_container(PyObject* in_data, DataContainer* dc, size_t start_idx, size_t num_elements) {
  size_t offset = start_idx;
  size_t dataSize = sizeof(long);

  PyObject *value;
  for (int i=0; i<num_elements; i++, offset += dataSize) {
    value = PyList_GetItem(in_data, i);

    dc->set(PyLong_AsLong(value), offset, dataSize);
  }
}


///////////////////////////////////////////////////////////////////////////////////


PFrame::PFrame(PyObject* data, size_t num_threads) {
  _data = new std::vector<std::vector<long*>*>();
  _data->reserve(num_threads);

  const size_t data_size = PyList_Size(data);
  const size_t max_per_thread = std::ceil(data_size / num_threads);

  size_t current_idx = 0;
  std::vector<std::thread> t{};
  t.reserve(num_threads);

  for (int i=0; i<num_threads; i++, current_idx += max_per_thread) {
    _data->emplace_back();
    t.emplace_back(add_to_vector, data, _data->at(i), current_idx, std::min(max_per_thread, data_size - current_idx));
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
  delete _data;
}

const long *const PFrame::at(size_t index) {
  return nullptr;
}

const size_t PFrame::size() {
  return 0;
}

PFrame::PFrame(DataContainer& dc) {

}

//////////////////////// Partitioned Frame ////////////////////////
bool PartitionedFrame::test(void *, PyObject *) {
  return true;
}

void PartitionedFrame::delete_deserialized_data(void * data) {
  delete (PFrame*)data;
}

DataContainer PartitionedFrame::serialize(void * data) {
  auto* pf = (PFrame*)data;

  return pf->data_container();
}

void *PartitionedFrame::deserialize(DataContainer& dc) {
  return new PFrame(dc);
}


DataContainer PartitionedFrame::serialize(PyObject * data) {
  // get the size of the data and the partition size
  const size_t data_size = PyList_Size(data);
  const size_t max_per_thread = std::ceil(data_size / _num_partitions);
  DataContainer dc((data_size * sizeof(long)) + sizeof(size_t));

  size_t current_idx = 0;
  std::vector<std::thread> t{};
  t.reserve(_num_partitions);

  // copy the number of elements on to the buffer
  dc.set((long) &data_size, current_idx, sizeof(size_t));
  current_idx += sizeof(size_t);

  for (int i=0; i<_num_partitions; i++, current_idx += max_per_thread) {
    t.emplace_back(add_to_data_container, data, &dc, current_idx, std::min(max_per_thread, data_size - current_idx));
  }

  for (std::thread& th: t) {
    th.join();
  }

  return dc;
}

const char *PartitionedFrame::type() {
  return _type;
}
