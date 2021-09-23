//
// Created by tyler on 9/19/21.
//

#ifndef SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_
#define SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_

#include "serdes_test.h"


///////////////////////// Static Thread Safe /////////////////////////
//void py_to_vector (PyObject*, std::vector<long*>*, size_t, size_t);
void bytes_to_vector (const int8_t*, std::vector<long*>*, size_t);
//void py_to_buffer (PyObject*, void*, size_t, size_t);
void py_to_data_container(PyObject*, DataContainer*, size_t, size_t, size_t);
void vector_to_data_container (std::vector<long*>*, DataContainer*, size_t);


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
  PFrame(DataContainer&, size_t);
  // copy constructor
  PFrame(const PFrame&);
  // move constructor
  PFrame(PFrame&&) noexcept;
  // copy assignment
  PFrame& operator=(const PFrame&);
  // move assignment
  PFrame& operator=(PFrame&&) noexcept;
  [[nodiscard]] DataContainer data_container() const;
  ~PFrame();
  const long* at(size_t index);
  size_t size();
  std::vector<long*> flatten();

 private:
  std::vector<std::vector<long*>*>* _data;
};

#endif //SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_
