#include "Checking.h"
Checking::Checking() {
  CurrentBalance = 0.0;
}
Checking::~Checking() {
  CurrentBalance = 0.0;
  delete [] first_name;
  delete [] last_name;
  delete [] account_type;
}
void Checking::Project() {
  ProjectedBalance = CurrentBalance + 0.1;
  return;
}
void Checking::CheckingStore(float current) {
  CurrentBalance = current;
  return;
}
void Checking::InvestmentStore(int i1, float f1, float f2, float f3, float f4) {
  return;
}
void Checking::SavingsStore(float f1, float f2) {
  return;
}
const float Checking::getInitialBalance() const {
  return CurrentBalance;
}
const float Checking::getProjectedBalance() const {
  return ProjectedBalance;
}
