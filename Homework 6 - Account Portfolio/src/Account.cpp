#include "Account.h"
#include <cstring>
Account::Account() {
  first_name = new char[25];
  last_name = new char[25];
  account_type = new char[15];
}

void Account::SetName(const char *first, const char *last) {
  strcpy(first_name, first);
  strcpy(last_name, last);
  return;
}
void Account::SetType(const char *in) {
  strcpy(account_type, in);
  return;
}
const char *Account::getFirstName() const {
  return first_name;
} 
const char *Account::getLastName() const {
  return last_name;
}
const char *Account::getType() const {
  return account_type;
}
