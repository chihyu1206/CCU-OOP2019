#ifndef _INVESTMENT_H_
#define _INVESTMENT_H_
#include "Account.h"
struct ETF {
  float InvestedAmount;
  float CurrentValue;
  float DividendYield;
  float InitialValuePerShare;
  float CurrentValuePerShare;
  float InterestRate;
};
  
class Investment: public Account{
 public:
  Investment();
  ~Investment(); 
  void Project();
  void InvestmentStore(int, float, float, float, float);
  void CheckingStore(float);
  void SavingsStore(float, float);
  const float getInitialBalance() const;
  const float getProjectedBalance() const;
 protected:
 private:
  struct ETF *ETFs;
  float ProjectedBalance;
};
#endif