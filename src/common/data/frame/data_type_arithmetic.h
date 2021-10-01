//
// Created by tyler on 9/29/21.
//

#ifndef SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_ARITHMETIC_H_
#define SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_ARITHMETIC_H_

#include "frame/data_type.h"
#include<memory>

//////////////////////////////// Priority Helper ////////////////////////////////
template<typename T>
int8_t priority() {
  if(typeid(T) == typeid(int)) {
    return TYPE_INT_PRECISION;
  } else {
    throw siphon::NotImplementedException(typeid(T).name(), "priority");
  }
}

//////////////////////////////// Addition ////////////////////////////////
std::shared_ptr<DataType> operator+(DataType&, DataType&);
std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>&, const std::shared_ptr<DataType>&);
std::shared_ptr<DataType> operator+(DataType&, const std::shared_ptr<DataType>&);
std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>&, DataType&);

//std::shared_ptr<DataType> operator+(int, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator+(int, DataType&);
//std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>&, int);
//std::shared_ptr<DataType> operator+(DataType&, int);
//
//std::shared_ptr<DataType> operator+(short, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator+(short, DataType&);
//std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>&, short);
//std::shared_ptr<DataType> operator+(DataType&, short);
//
//std::shared_ptr<DataType> operator+(long, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator+(long, DataType&);
//std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>&, long);
//std::shared_ptr<DataType> operator+(DataType&, long);
//
//std::shared_ptr<DataType> operator+(float, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator+(float, DataType&);
//std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>&, float);
//std::shared_ptr<DataType> operator+(DataType&, float);
//
//std::shared_ptr<DataType> operator+(double, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator+(double, DataType&);
//std::shared_ptr<DataType> operator+(const std::shared_ptr<DataType>&, double);
//std::shared_ptr<DataType> operator+(DataType&, double);
//
////////////////////////////////// Subtraction ////////////////////////////////
//std::shared_ptr<DataType> operator-(DataType&, DataType&);
//std::shared_ptr<DataType> operator-(const std::shared_ptr<DataType>&, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator-(DataType&, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator-(const std::shared_ptr<DataType>&, DataType&);
//
//std::shared_ptr<DataType> operator-(int, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator-(int, DataType&);
//std::shared_ptr<DataType> operator-(const std::shared_ptr<DataType>&, int);
//std::shared_ptr<DataType> operator-(DataType&, int);
//
//std::shared_ptr<DataType> operator-(short, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator-(short, DataType&);
//std::shared_ptr<DataType> operator-(const std::shared_ptr<DataType>&, short);
//std::shared_ptr<DataType> operator-(DataType&, short);
//
//std::shared_ptr<DataType> operator-(long, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator-(long, DataType&);
//std::shared_ptr<DataType> operator-(const std::shared_ptr<DataType>&, long);
//std::shared_ptr<DataType> operator-(DataType&, long);
//
//std::shared_ptr<DataType> operator-(float, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator-(float, DataType&);
//std::shared_ptr<DataType> operator-(const std::shared_ptr<DataType>&, float);
//std::shared_ptr<DataType> operator-(DataType&, float);
//
//std::shared_ptr<DataType> operator-(double, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator-(double, DataType&);
//std::shared_ptr<DataType> operator-(const std::shared_ptr<DataType>&, double);
//std::shared_ptr<DataType> operator-(DataType&, double);
//
////////////////////////////////// Multiplication ////////////////////////////////
//std::shared_ptr<DataType> operator*(DataType&, DataType&);
//std::shared_ptr<DataType> operator*(const std::shared_ptr<DataType>&, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator*(DataType&, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator*(const std::shared_ptr<DataType>&, DataType&);
//
//std::shared_ptr<DataType> operator*(int, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator*(int, DataType&);
//std::shared_ptr<DataType> operator*(const std::shared_ptr<DataType>&, int);
//std::shared_ptr<DataType> operator*(DataType&, int);
//
//std::shared_ptr<DataType> operator*(short, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator*(short, DataType&);
//std::shared_ptr<DataType> operator*(const std::shared_ptr<DataType>&, short);
//std::shared_ptr<DataType> operator*(DataType&, short);
//
//std::shared_ptr<DataType> operator*(long, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator*(long, DataType&);
//std::shared_ptr<DataType> operator*(const std::shared_ptr<DataType>&, long);
//std::shared_ptr<DataType> operator*(DataType&, long);
//
//std::shared_ptr<DataType> operator*(float, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator*(float, DataType&);
//std::shared_ptr<DataType> operator*(const std::shared_ptr<DataType>&, float);
//std::shared_ptr<DataType> operator*(DataType&, float);
//
//std::shared_ptr<DataType> operator*(double, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator*(double, DataType&);
//std::shared_ptr<DataType> operator*(const std::shared_ptr<DataType>&, double);
//std::shared_ptr<DataType> operator*(DataType&, double);
//
////////////////////////////////// Division ////////////////////////////////
//std::shared_ptr<DataType> operator/(DataType&, DataType&);
//std::shared_ptr<DataType> operator/(const std::shared_ptr<DataType>&, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator/(DataType&, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator/(const std::shared_ptr<DataType>&, DataType&);
//
//std::shared_ptr<DataType> operator/(int, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator/(int, DataType&);
//std::shared_ptr<DataType> operator/(const std::shared_ptr<DataType>&, int);
//std::shared_ptr<DataType> operator/(DataType&, int);
//
//std::shared_ptr<DataType> operator/(short, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator/(short, DataType&);
//std::shared_ptr<DataType> operator/(const std::shared_ptr<DataType>&, short);
//std::shared_ptr<DataType> operator/(DataType&, short);
//
//std::shared_ptr<DataType> operator/(long, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator/(long, DataType&);
//std::shared_ptr<DataType> operator/(const std::shared_ptr<DataType>&, long);
//std::shared_ptr<DataType> operator/(DataType&, long);
//
//std::shared_ptr<DataType> operator/(float, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator/(float, DataType&);
//std::shared_ptr<DataType> operator/(const std::shared_ptr<DataType>&, float);
//std::shared_ptr<DataType> operator/(DataType&, float);
//
//std::shared_ptr<DataType> operator/(double, const std::shared_ptr<DataType>&);
//std::shared_ptr<DataType> operator/(double, DataType&);
//std::shared_ptr<DataType> operator/(const std::shared_ptr<DataType>&, double);
//std::shared_ptr<DataType> operator/(DataType&, double);

#endif //SIPHON_SRC_COMMON_DATA_FRAME_SIPHON_SIPHON_TYPE_ARITHMETIC_H_
