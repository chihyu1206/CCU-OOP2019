#include "Date.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const string Month[] = {"Jan", "Feb", "Mar", "Apr", "May", "June",
                       "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
enum MONTH {Jan = 1, Feb, Mar, Apr, May, June,
            July, Aug, Sept, Oct, Nov, Dec};
const int MaxDayofMonth[] = {31, 28, 31, 30, 31, 30, 
                             31, 31, 30, 31, 30, 31}; 
Date::Date() {
  this->month = 1;
	this->day = 1;
	this->year = 2000;
  this->format = 'D';
}
Date::Date(int mm, int dd, int yy) {
  if (Set(mm, dd, yy)) {
    this->month = mm;
    this->day = dd;
    this->year = yy;
  } else {
    this->month = 1;
    this->day = 1;
    this->year = 2000;
  }
}
void Date::Input() {
  int mm, dd, yy;
  while (true) {
    cout << "Please input a date as format:" << endl;
    cout << "[usage]: month/day/year" << endl;
    scanf("%d/%d/%d", &mm, &dd, &yy);
    if (Set(mm, dd, yy)) {
      break;
    } else {
      cout << "Invalid date. Try again" << endl;
    }      
  }
}
void Date::Show() {
  switch (this->format) {
    case 'D': {
      printf("%d/%d/%d\n", this->month, this->day, this->year);
      break;
    }
    case 'T': {
      printf("%02d/%02d/%02d\n", this->month, this->day, this->year % 100);
      break;
    }
    case 'L': {
      cout << Month[this->month - 1] << ' ';
      printf("%d, %d\n", this->day, this->year);   
      break;
    }
    default : {
      this->format = 'D';
      printf("%d/%d/%d\n", this->month, this->day, this->year);
      break;
    }
  }
  return;
}
int Date::GetDay() {
  return this->day;
}
int Date::GetMonth() {
  return this->month;
}
int Date::GetYear() {
  return this->year;
}
bool Date::SetFormat(char format) {
  switch (format) {
    case 'D': {
      this->format = 'D';
      break;
    }
    case 'T': {
      this->format = 'T';
      break;
    }
    case 'L': {
      this->format = 'L';
      break;
    }
    default: {
      return false;
      break;
    }
  }
  return true;
}
void Date::Increment(int numDays) {
  int input = numDays;
  this->day += input;
  while (!Set(this->month, this->day, this->year)) {
    this->day -= MaxDayofMonth[this->month - 1];
    this->month++;
  }    
  return;
}
bool Date::Set(int m, int d, int y) {
  bool isValid = false;
  int new_m = m;
  int new_d = d;
  int new_y = y;
  if (!((1 <= d) && (d <= 31))) {
    isValid = false;
    return isValid;
  }    
  if (!((1 <= m) && (m <= 12))) {
    isValid = false;
    return isValid;
  }
  if (y <= 0) {
    isValid = false;
    return isValid;
  }
  if (m == Jan || m == Mar || m == May || m == July ||
      m == Aug || m == Oct || m == Dec) {
    isValid = true;
  } else if (m == Apr || m == June || m == Sept ||
             m == Nov) {
    if (d > 30) {
      isValid = false;
      return isValid;
    } else {
      isValid = true;
    }
  } else {
    if (d > 28) {
      isValid = false;
      return isValid;
    } else {
      isValid = true;
    }
  }
  if (isValid) {
    this->month = new_m;
    this->day = new_d;
    this->year = new_y;
    return isValid;
  }
}
int Date::Compare(const Date &d) {
  if (this->year > d.year) {
    return 1;
  } else if (this->year < d.year) {
    return -1;
  }
  if (this->month > d.month) {
    return 1;
  } else if (this->month < d.month) {
    return -1;
  }
  if (this->day > d.day) {
    return 1;
  } else if (this->day < d.day) {
    return -1;
  }
  return 0;
}
