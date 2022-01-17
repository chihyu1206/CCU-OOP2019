#ifndef _SAVINGS_H_
#define _SAVINGS_H_
#include "Account.h"
class Savings: public Account{
 public:
  Savings();
  ~Savings(); 
  void Project();
  void SavingsStore(float, float);
  void InvestmentStore(int, float, float, float, float);
  void CheckingStore(float);
  const float getInitialBalance() const;
  const float getProjectedBalance() const;
 private:
  float CurrentBalance;
  float InterestRate;
  float ProjectedBalance;   
};
#endif