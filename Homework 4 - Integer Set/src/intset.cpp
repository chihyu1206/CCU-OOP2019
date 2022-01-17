#include "intset.h"
#include <iostream>
IntSet::IntSet() {
  for (int i = 0; i < 101; i++)
    this->set[i] = 0;
}
IntSet::IntSet(int container) {
  for (int i = 0; i < 101; i++)
    this->set[i] = 0;
  if ((container >= 0) && (container <= 100)) {
    this->set[container] = 1;
  }
}
IntSet IntSet::setUnion(const IntSet &s) {
  IntSet ret;
  for (int i = 0; i < 101; i++) {
    if (this->set[i] || s.set[i])
      ret.set[i] = 1;
  }
  return ret;
}
IntSet IntSet::setIntersection(const IntSet &s) {
  IntSet ret;
  for (int i = 0; i < 101; i++) {
    if (this->set[i] && s.set[i])
      ret.set[i] = 1;
  }
  return ret;
}
bool IntSet::isEmpty(void) {
  for (int i = 0; i < 101; i++) {
    if (this->set[i] != 0)
      return false;
  }
  return true;
}
const int IntSet::size(void) const{
  int total = 0;
  for (int i = 0; i < 101; i++) {
    if (this->set[i])
      total++;
  }
  return total;
}
IntSet IntSet::relativeComplement(const IntSet &s) {
  IntSet ret;
  int i = 0;
  for (i = 0; i < 101; i++) {
    if (this->set[i] && !s.set[i])
      ret.set[i] = 1; 
  }
  return ret;
}
IntSet IntSet::symmetricDifference(const IntSet &s) {
  IntSet ret;
  for (int i = 0; i < 101; i++) {
    if ((this->set[i] && !s.set[i]) ||
        (!this->set[i] && s.set[i]))
      ret.set[i] = 1;
  }
  return ret;
}
void IntSet::setPrint(void) const {
  if (size() == 0) {
    std::cout << "{ --- }";
  } else {
    std::cout << '{';
    bool first = true;
    for (int i = 0; i < 101; i++) {
      if (this->set[i]) {
        if (first) {
          std::cout << i;
          first = false;
        } else {
          std::cout << ", " << i;
        }
      } else {
        continue;
      }
    }
    std::cout << '}';
  }
  return;
}
bool IntSet::isEqualTo(const IntSet &s) const {
  for (int i = 0; i < 101; i++) {
    if (this->set[i] && !s.set[i])
      return false;
  }
  return true;
}