#include "MyVector.h"
#include <iostream>
MyVector::MyVector() { //constructor
  vector = NULL;
  size = 0;
}
MyVector::MyVector(int size, const double *df) { //constructor
  this->size = size;
  vector = new double[size];
  for (int i = 0; i < size; i++)
    vector[i] = df[i];    
}
MyVector::MyVector(const MyVector &cp) { // copy constructor
  size = cp.size;
  vector = new double[size];
  for (int i = 0; i < size; i++)
    vector[i] = cp.vector[i];
}
MyVector::~MyVector() { // destructor
  delete [] vector;
}
const MyVector& MyVector::operator=(const MyVector &target) { //overloading assignment operator
  if (&target == this)
    return *this;
  if (target.size != size) {
    if (size != 0)
      delete [] vector;
    size = target.size;
    vector = new double[size];
  }
  for (int i = 0; i < size; i++)
    this->vector[i] = target.vector[i];
  return *this;
}
std::ostream &operator<<(std::ostream &out, const MyVector &target) { //ouverloading output operator
  if (target.size <= 0) {
    out << "<>";
  } else {
    out << '<';
    for (int i = 0; i < target.size - 1; i++) {
      out << target.vector[i] <<", ";
    }
    out << target.vector[target.size - 1] << '>';
  }
}
double MyVector::operator*(const MyVector &target) { //inner product: Vector * Vector
  double ret = 0.0;
  if (this->size == target.size) {
    for (int i = 0; i < size; i++) {
      ret += vector[i] * target.vector[i];
    }
  } 
  return ret;
}
MyVector operator*(const double df, const MyVector& Vector) { // constant * Vector
  MyVector ret(Vector);
  for (int i = 0; i < Vector.size; i++)
    ret.vector[i] *= df;
  return ret;
}
MyVector operator*(const MyVector& Vector, const double df) { // Vector * constant
  MyVector ret(Vector);
  for (int i = 0; i < Vector.size; i++)
    ret.vector[i] *= df;
  return ret;
}
MyVector operator+(const MyVector &left, const MyVector &right) { // Vector + Vector
  MyVector ret(left);
  for (int i = 0; i < ret.size; i++) {
    ret.vector[i] = left.vector[i] + right.vector[i];
  }
  return ret;
}
