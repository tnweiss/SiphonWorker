//
// Created by tyler on 9/19/21.
//

#ifndef SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_
#define SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_

#include "serdes_test.h"

class PartitionedFrame: public SerDesTest {
 public:
  const char* type() final;
  DataContainer serialize(PyObject*) final;
  void* deserialize(DataContainer&) final;
  DataContainer serialize(void*) final;
  void delete_deserialized_data(void*) final;
  bool test(void*, PyObject*) final;
};


class PFrame {
 public:
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
  std::vector<std::vector<long*>>* _data;
};

#endif //SIPHON_SRC_TEST_POC_SERDES_PARTITIONEDFRAME_H_
