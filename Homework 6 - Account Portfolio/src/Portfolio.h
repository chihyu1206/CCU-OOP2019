#ifndef _PORTFOLIO_H_
#define _PORTFOLIO_H_
#include "Account.h"
#include <cstdio>
class Portfolio {
 public:
  Portfolio();
  ~Portfolio();
  bool importFile(const char *filename);
  bool createReportFile(const char *filename);
  void ShowAccounts() const;
 private:
  Account **alist;
  int default_size;
  int current_size;
  FILE *fp;
};
#endif