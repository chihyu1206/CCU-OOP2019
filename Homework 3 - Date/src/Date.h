#ifndef _DATE_H
#define _DATE_H

class Date {
 private:
  int month;
  int day;
  int year;
  char format;
 public:
  Date();
  Date(int, int, int);
  
  void Input();
  void Show();
	bool Set(int, int, int);
	int GetMonth();
	int GetDay();
	int GetYear();
  bool SetFormat(char);
	void Increment(int = 1);
	int Compare(const Date& d);
};
#endif
