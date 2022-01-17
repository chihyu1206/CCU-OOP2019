#ifndef _CHECKING_H_
#define _CHECKING_H_
#include "Account.h"
class Checking: public Account {
 public:
  Checking(); 
  ~Checking();
  void CheckingStore(float);
  void SavingsStore(float, float);
  void InvestmentStore(int, float, float, float, float);
  const float getInitialBalance() const;
  const float getProjectedBalance() const;
  void Project();
 protected:
 private:
  float CurrentBalance;
  float ProjectedBalance;
};
#endif