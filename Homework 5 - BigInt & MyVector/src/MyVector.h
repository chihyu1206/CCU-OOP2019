#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_
#include <iostream>
class MyVector {
 private:
  double *vector;
  int size;
 public:
  MyVector();
  MyVector(int, const double*);
  MyVector(const MyVector&);
  ~MyVector();
  const MyVector &operator=(const MyVector&);
  friend std::ostream &operator<<(std::ostream& , const MyVector&);
  double operator*(const MyVector&);
  friend MyVector operator*(const double, const MyVector&);
  friend MyVector operator*(const MyVector&, const double);
  friend MyVector operator+(const MyVector&, const MyVector&);  
};
#endif