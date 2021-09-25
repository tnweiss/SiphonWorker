//
// Created by tyler on 9/19/21.
//

#include "PartitionedFrame.h"
#include <thread>


void bytes_to_vector (int8_t* data_array, std::vector<long*>* data_partition, size_t num_elements) {
  // get the pointer to the memory space of the vector
  long** data_partition_data = data_partition->data();

  // interpret the incoming data as an array of long
  auto* current_idx = (long*)data_array;

  for (int i=0; i<num_elements; i++) {
    // copy each pointer over
    memcpy(data_partition_data, &current_idx, sizeof(current_idx));

    data_partition_data += 1;
    current_idx += 1;
  }
}


void vector_to_data_container (std::vector<long*>* data_partition, DataContainer* dc, size_t offset) {
  size_t data_size = sizeof(long);

  for (long* l: *data_partition) {
    dc->set((void*)l, offset, data_size);

    offset += data_size;
  }
}

void py_to_data_container(PyObject* in_data, DataContainer* dc, size_t offset, size_t start_idx, size_t num_elements) {
  size_t dataSize = sizeof(long);

  auto py_start_idx = static_cast<Py_ssize_t>(start_idx);
  PyObject *value;
  for (int i=0; i<num_elements; i++, offset += dataSize) {
    value = PyList_GetItem(in_data, py_start_idx + i);

    dc->set(PyLong_AsLong(value), offset, dataSize);
  }
}


///////////////////////////////////////////////////////////////////////////////////

// copy
PFrame::PFrame(const PFrame &) {
  _data = nullptr;
  std::cout << "\n\n\nNO COPYING PFrame\n\n\n" << std::endl;
  exit(1);
}

// move
PFrame::PFrame(PFrame && other) noexcept {
    _data = other._data;
    other._data = nullptr;
    std::cout << "move" << std::endl;
}

// copy assign
PFrame &PFrame::operator=(const PFrame &) {
  std::cout << "\n\n\nNO COPYING CONTAINER\n\n\n" << std::endl;
  exit(1);
}

// move assign
PFrame& PFrame::operator=(PFrame && other) noexcept {
    _data = other._data;
    other._data = nullptr;
    std::cout << "move assign" << std::endl;
  return *this;
}


DataContainer PFrame::data_container() const {
  // set the data size
  size_t total_elements = 0;
  for (std::vector<long*>* d: *_data) {
    total_elements += d->size();
  }

  DataContainer dc((total_elements * sizeof(long)) + sizeof(size_t));
  size_t offset = 0;

  dc.set(&total_elements, offset);
  offset += sizeof(size_t);

  std::vector<std::thread> t{};
  t.reserve(_data->size());

  for (auto & i : *_data) {
    //vector_to_data_container(i, &dc, offset);
    t.emplace_back(vector_to_data_container, i, &dc, offset);

    offset += sizeof(long) * i->size();
  }

  for (std::thread& th: t) {
    th.join();
  }

  return dc;
}

PFrame::~PFrame() {
      if (_data == nullptr) {
        return;
    }

    for (std::vector<long*>* li: *_data) {
        delete li;
    }
    delete _data;
}

long *PFrame::at(size_t index) {
  for (std::vector<long*>* e: *_data) {
    if (index >= e->size()) {
      index -= e->size();
    } else {
      return e->at(index);
    }
  }
  return nullptr;
}

size_t PFrame::size() {
  size_t s = 0;
  for (std::vector<long*>* e: *_data) {
    s += e->size();
  }
  return s;
}

PFrame::PFrame(DataContainer& dc, size_t num_threads) {
  _data = new std::vector<std::vector<long*>*>();
  _data->reserve(num_threads);

  if (dc.size() == 0) {
    for (int i=0; i<num_threads; i++) {
      _data->push_back(new std::vector<long*>());
    }
    return;
  }

  // get the pointer to the data
  auto* data = (int8_t*)dc.v();

  // the size of the data is at the beginning of the frame
  const size_t data_size = *(size_t*)data;

  // after we get the size we can ignore it
  data += sizeof(size_t);
  const size_t max_per_thread = std::ceil(static_cast<float>(data_size) / static_cast<float>(num_threads));

  size_t current_idx = 0;
  std::vector<std::thread> t{};
  t.reserve(num_threads);

  size_t element_count;
  std::vector<long*>* partition;
  for (int i=0; i<num_threads; i++) {
    element_count = static_cast<size_t>(std::min(max_per_thread, data_size - current_idx));

    partition = new std::vector<long*>(element_count);
    _data->push_back(partition);

    t.emplace_back(bytes_to_vector, data, _data->at(i), element_count);
    data += sizeof(long) * element_count;
    current_idx += element_count;
  }

  for (std::thread& th: t) {
    th.join();
  }
}

//////////////////////// Partitioned Frame ////////////////////////
bool PartitionedFrame::test(void * data, PyObject * py_obj) {
  auto* pf = (PFrame*)data;
  Py_ssize_t len = PyList_Size(py_obj);

  if (len != pf->size()) {
    std::cout << "\nLen mismatch, Actual: " << pf->size() << " Expected: " << len  << std::endl;
    return false;
  }

  for (Py_ssize_t i=0; i<len; i++) {
    if (PyLong_AsLong(PyList_GetItem(py_obj, i)) != *pf->at(i)) {
      std::cout << "Val Mismatch at index: " << i << "/" << len << ", Excpected: " <<
        PyLong_AsLong(PyList_GetItem(py_obj, i)) <<
        " != Actual: " << pf->at(i) << std::endl;
      return false;
    }
  }
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
  auto* pf = new PFrame(dc, _num_partitions);

  return pf;
}


DataContainer PartitionedFrame::serialize(PyObject * data) {
  // get the size of the data and the partition size
  const size_t num_elements = PyList_Size(data);
  const size_t num_elements_per_thread = std::ceil(static_cast<float>(num_elements) / static_cast<float>(_num_partitions));

  // size of buffer is elements * size of each plus the size of the num_elements
  DataContainer dc((num_elements * sizeof(long)) + sizeof(size_t));

  // tracks the index in the pyObject
  size_t current_idx = 0;
  size_t current_offset = 0;

  // create a vector with space for enough space to hold all partitions
  std::vector<std::thread> t{};
  t.reserve(_num_partitions);

  // copy the number of elements on to the buffer and increa
  dc.set(&num_elements, current_offset);
  current_offset += sizeof(size_t);

  size_t element_count = 0;
  for (int i=0; i<_num_partitions; i++) {
    element_count = std::min(num_elements_per_thread, num_elements - current_idx);

    t.emplace_back(py_to_data_container, data, &dc, current_offset, current_idx, element_count);

    current_idx += element_count;
    current_offset += element_count * sizeof(long);
  }

  for (std::thread& th: t) {
    th.join();
  }

  return dc;
}

const char *PartitionedFrame::type() {
  return _type;
}
