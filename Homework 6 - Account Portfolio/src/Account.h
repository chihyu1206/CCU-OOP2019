#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
 public:
  Account();
  virtual ~Account(){;}
  virtual void Project() = 0;
  virtual void SavingsStore(float, float) = 0;
  virtual void CheckingStore(float) = 0;
  virtual void InvestmentStore(int, float, float, float, float) = 0;
  virtual const float getInitialBalance() const = 0;
  virtual const float getProjectedBalance() const = 0;
  void SetName(const char*, const char*);
  void SetType(const char*);
  const char *getFirstName() const;
  const char *getLastName() const;
  const char *getType() const;
  
 protected:
  char *first_name;
  char *last_name;
  char *account_type;
};
#endif
