//
// Created by tyler on 9/29/21.
//

#include "data_type_arithmetic.h"


//////////////////////////////// Addition ////////////////////////////////
std::shared_ptr<DataType> operator+(DataType& l, DataType& r) {
  std::shared_ptr<DataType> r_val;

  if (l.precision() >= r.precision()) {
    r_val = std::unique_ptr<DataType>(l.replicate());
    *r_val += r;
  } else {
    r_val = std::unique_ptr<DataType>(r.replicate());
    *r_val += l;
  }

  return r_val;
}

std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>& l, const std::shared_ptr<DataType>& r) {
  return operator+(*l, *r);
}

std::shared_ptr<DataType> operator+(DataType& l, const std::shared_ptr<DataType>& r) {
  return operator+(l, *r);
}

std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>& l, DataType& r) {
  return operator+(*l, r);
}
