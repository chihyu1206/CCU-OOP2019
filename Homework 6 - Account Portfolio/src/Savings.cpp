#include "Savings.h"
Savings::Savings() {
  CurrentBalance = 0.0;
  InterestRate = 0.0;
  ProjectedBalance = 0.0;
} 
Savings::~Savings() {
  CurrentBalance = 0.0;
  InterestRate = 0.0;
  ProjectedBalance = 0.0;
  delete [] first_name;
  delete [] last_name;
  delete [] account_type;
}
void Savings::Project() {
  ProjectedBalance = CurrentBalance * (1 + InterestRate);
  return;
}
void Savings::SavingsStore(float current, float rate) {
  CurrentBalance = current;
  InterestRate = rate;
  return;
}
void Savings::CheckingStore(float f1) {
  return;
}
void Savings::InvestmentStore(int i1, float f1, float f2, float f3, float f4) {
  return;
}
const float Savings::getInitialBalance() const {
  return CurrentBalance;
}
const float Savings::getProjectedBalance() const {
  return ProjectedBalance;
}