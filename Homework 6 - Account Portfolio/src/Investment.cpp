#include "Investment.h"

Investment::Investment() {
  ETFs = new ETF[5];
  for (int i = 0; i < 5; i++) {
    ETFs[i].InvestedAmount = 0.0;
    ETFs[i].CurrentValue = 0.0;
    ETFs[i].DividendYield = 0.0;
    ETFs[i].InitialValuePerShare = 0.0;
    ETFs[i].CurrentValuePerShare = 0.0;
    ETFs[i].InterestRate = 0.0;
  }
  ProjectedBalance = 0.0;
}
Investment::~Investment() {
  delete [] ETFs;
  ProjectedBalance = 0.0;
  delete [] first_name;
  delete [] last_name;
  delete [] account_type;
}
void Investment::Project() {
  int i = 0;
  for (i = 0; i < 5; i++) {
    ETFs[i].CurrentValue = (ETFs[i].InvestedAmount / ETFs[i].InitialValuePerShare) * ETFs[i].CurrentValuePerShare;
    ETFs[i].DividendYield = ETFs[i].InvestedAmount * ETFs[i].InterestRate;
  } 
  ProjectedBalance = 0.0;
  for (i = 0; i < 5; i++) {
    ProjectedBalance = ProjectedBalance + ETFs[i].CurrentValue + ETFs[i].DividendYield;
  }
  return;
}
void Investment::InvestmentStore(int index, float A, float IVS, float CVS, float I) {
  ETFs[index].InvestedAmount = A;
  ETFs[index].InitialValuePerShare = IVS;
  ETFs[index].CurrentValuePerShare = CVS;
  ETFs[index].InterestRate = I;
}
void Investment::CheckingStore(float f1) {
  return;
}
void Investment::SavingsStore(float f1, float f2) {
  return;
}
const float Investment::getInitialBalance() const{
  float sum = 0.0;
  for (int i = 0; i < 5; i++) {
    sum += ETFs[i].InvestedAmount;
  }
  return sum;
}
const float Investment::getProjectedBalance() const{
  return ProjectedBalance;
}