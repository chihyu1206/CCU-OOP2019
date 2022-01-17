#include <iostream>
#include <cstdlib>
#include <cstdio>
#define N 25 //There are 21 digits when n == 99 
using namespace std;
int *add(int a[], int b[]) { //  add integer array a and b to b
  int i = 0, carry = 0;
  for (i = 0; i < N; i++) {
    b[i] = a[i] + b[i] + carry;
    carry = b[i] / 10;
    b[i] %= 10;
  }     
  return b;
}

int *swap(int a[], int b[]) {//swap function to swap elements of two integer arrays
  int i = N - 1, temp = 0;
  while (a[i] == 0 && b[i] == 0 && i > 0) i--;
  for (; i >= 0; i--) {
    temp = a[i];
    a[i] = b[i];
    b[i] = temp;
  }
  return a;
}
int *f(int n, int a[], int b[]) { //fibonacci function using tail recursion
  if (n == 1) {
	  return a;
	} else if (n == 2) {
	  return b;
	} else {
    a = swap(a, b);
    b = add(a, b);
    return f(n - 1, a, b);
  }
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "[usage]:./cpphw1 n\n");
    exit(-1);
  }
  int n = atoi(argv[1]);
  if (n < 1 || n > 99) {
    fprintf(stderr, "The integer argument n should locate between 1 to 99\n");
    exit(-1);
  }
  cout << "The input number is " << n << endl;
  printf("f(%d) = ", n);
  int a[N], b[N], i = 0;
  a[0] = 1, b[0] = 1;//f(1) = 1, f(2) = 1
  for (i = 1; i < N; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  f(n, a, b);
  i = N - 1;
  while (b[i] == 0 && i > 0)
    i--;
  for (; i >= 0; i--)
    cout << b[i];
  cout << endl;
  return 0;
}
