//
// Created by tyler on 9/19/21.
//

#ifndef SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_
#define SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_

#include "serdes_test.h"

///////////////////////// Static Thread Safe /////////////////////////
void add_to_vector (PyObject* data_array, std::vector<long*>* data_partition, size_t start_idx, size_t num_elements);
void add_to_buffer (PyObject* data_array, void* buffer, size_t start_idx, size_t num_elements);
void add_to_data_container(PyObject* in_data, DataContainer* dc, size_t start_idx, size_t num_elements);



class PartitionedFrame: public SerDesTest {
 public:
  explicit PartitionedFrame(int num_threads):
    _type(new char[9 + static_cast<int>(std::floor(std::log10(num_threads) + 1))]),
    _num_partitions(num_threads){
    std::sprintf(_type, "PFrame-%i", num_threads);
  };
  const char* type() final;
  DataContainer serialize(PyObject*) final;
  void* deserialize(DataContainer&) final;
  DataContainer serialize(void*) final;
  void delete_deserialized_data(void*) final;
  bool test(void*, PyObject*) final;
 private:
  char* const _type;
  const int _num_partitions;
};


class PFrame {
 public:
  PFrame(DataContainer&);
  PFrame(PyObject*, size_t);
  PFrame(void*, size_t);
  // copy constructor
  PFrame(const PFrame&);
  // move constructor
  PFrame(PFrame&&) noexcept;
  // copy assignment
  PFrame& operator=(const PFrame&);
  // move assignment
  PFrame operator=(PFrame&&) noexcept;
  explicit PFrame(void*);
  [[nodiscard]] DataContainer data_container() const;
  ~PFrame();
  const long* const at(size_t index);
  const size_t size();

 private:
  size_t _size;
  size_t _typeSize;
  std::vector<std::vector<long*>*>* _data;
};

#endif //SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_
