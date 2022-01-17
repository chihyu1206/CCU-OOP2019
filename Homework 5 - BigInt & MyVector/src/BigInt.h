#ifndef _BIGINT_H_
#define _BIGINT_H_
class BigInt {
 private:
  char *num;
  int size;  
 public:
  BigInt();
  BigInt(const int *tmp, int length);
  BigInt(const BigInt &);
  ~BigInt();
  const BigInt &operator=(const BigInt &);
  char &operator[](int index);
  int length() const;
  char *getNum();
  BigInt &operator++(); //prefix increment
  BigInt &operator++(int); //postfix increment
};
#endif 
