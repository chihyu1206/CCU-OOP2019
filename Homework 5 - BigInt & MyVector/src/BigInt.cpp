#include "BigInt.h"
#include <cassert>
#include <iostream>

BigInt::BigInt() { // Constructor
  num = NULL;
	size = 0;
}
BigInt::BigInt(const int *tmp, int length) { // Constructor
  size = length;
	num = new char[length + 1];
	for (int i = 0; i < length; i++) {
	  num[i] = (char)(tmp[i] + '0');
	}
	num[length] = '\0';
}
BigInt::BigInt(const BigInt &cp) { //Copy Constructor
  size = cp.size;
	num = new char[cp.size + 1];
	for (int i = 0; i < size + 1; i++) {
	  num[i] = cp.num[i];
	}
}
BigInt::~BigInt() { //Destructor
	delete [] num;
}
const BigInt &BigInt::operator=(const BigInt &target) { //overloading assignment operator 
  if (&target == this) 
	  return *this;
  if (size != target.size) {
		if (size != 0)
		  delete [] num;
		size = target.size;
		num = new char[size + 1];
	}
	for (int i = 0; i < size; i++)
	  num[i] = target.num[i];
  return *this;
}
char &BigInt::operator[](int index) { // getting the corresponding number
  assert(index >= 0 && index < size);
	return num[index];
}
int BigInt::length() const { // get the size
  return size;
}
char *BigInt::getNum() { // get the number
  return num;
}
BigInt& BigInt::operator++() { // prefix increment of BigInt
	num[size - 1] = num[size - 1] + 1;
	for (int i = size - 1; i > 0; i--) {
    if (num[i] > '9') {
			num[i] = num[i] - 10;
			num[i - 1] = num[i - 1] + 1;
		} else {
			break;
		}
	}
  return *this;
}
BigInt& BigInt::operator++(int) { // postfix increment of BigInt
	num[size - 1] = num[size - 1] + 1;
	for (int i = size - 1; i > 0; i--) {
    if (num[i] > '9') {
			num[i] = num[i] - 10;
			num[i - 1] = num[i - 1] + 1;
		} else {
			break;
		}
	}
  return *this;
}
