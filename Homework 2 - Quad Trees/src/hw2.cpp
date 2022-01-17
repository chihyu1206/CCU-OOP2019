#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <cstdlib>
using namespace std;

void MatrixToNumber(int row, int col, int length, int depth, int dir, int num);
void NumberToMatrix(int row, int col, int length, int depth);
void Base10ToBase5(int num);

const int N = 64; //The Maximum length of the matrix is 64 * 64
int matrix[N][N];                       
int base5[N + 5];
set<int> BlackNode;

enum DIR {NW = 1, NE, SW, SE};
enum COLOR {White, Black};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "[usage]: ./hw2.out n\n");
    exit(-1);   
  }
  int n = atoi(argv[1]);
  if (n > 64) {
    fprintf(stderr, "The input must be a power of 2 and unde"
		                 "r or equal to 64\n");
	  exit(-1);
  }
  int i = 0, j = 0;
  char chr = '\0';
  BlackNode.clear();
	if (n > 0) { //convert matrix to number
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        cin >> chr;
        matrix[i][j] = chr - '0';
      }
    }

    MatrixToNumber(0, 0, n, 1, 0, 0);

    int count = 0;
    set<int>::iterator iter;
    for (iter = BlackNode.begin(); iter != BlackNode.end(); iter++) {
      if (count % 12 != 0)
        cout << ' ';
      if (count % 12 == 0 && count)
        cout << endl;
      cout << *iter;
      count++;
    }
    if (count % 12 != 0)
      cout << endl;
    cout << "Total number of black nodes = " << BlackNode.size() << endl;
  } else { //convert number to matrix
    n = -n;
    int input;
    for (i = 0; i < N; i++) //initialize the matrix array
      for (j = 0; j < N; j++)
        matrix[i][j] = White; 
    while (cin >> input) {
      if (input == -1) //scan the input number until input == -1
        break;
      /*convert the number from decimal to base 5
      and store in the base5 array*/
      Base10ToBase5(input);             
      NumberToMatrix(0, 0, n, 1);          
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == Black)
          cout << "*";
        else
          cout << ".";
      }
      cout << endl;
    }
  }
  return 0;
}
/*convert the number in decimal to base 5 
and store each digit in base5 array*/ 
void Base10ToBase5(int num) {
  int i = 0, digit = 0;
  for (i = 0; i < (sizeof(base5) / sizeof(int)); i++)
    base5[i] = 0;
  for (i = N; i > 0; i--) {
    digit = num / pow(5, i);
    if (digit > 0) {
      base5[i + 1] = digit;
      num = num - digit * pow(5, i);
    }

  }
  base5[1] = num;
  return;
}

void NumberToMatrix(int row, int col, int length, int depth) {
  int i = 0, j = 0;
  if (!base5[depth]) { //The node has no child left. Paint all the block by black.
    for (i = row; i < row + length; i++) {
      for (j = col; j < col + length; j++) {
        matrix[i][j] = Black;
      }
    }
  } else {
    length /= 2;
    depth++;
    switch (base5[depth - 1]) { // 1:NW, 2:NE, 3:SW, 4:SE
    case NW:
      NumberToMatrix(row, col, length, depth);
      break;
    case NE:
      NumberToMatrix(row, col + length, length, depth);
      break;
    case SW:
      NumberToMatrix(row + length, col, length, depth);
      break;
    case SE:
      NumberToMatrix(row + length, col + length, length, depth);
      break;
    }
  }
  return;
}

void MatrixToNumber(int row, int col, int length, int depth, int dir, int num) {
  int newnum = 0, i = 0, j = 0;
  bool isWhite = false, isBlack = false;
  for (i = row; i < row + length; i++) {
    for (j = col; j < col + length; j++) {
      if (matrix[i][j] == White)
        isWhite = true;
      if (matrix[i][j] == Black)
        isBlack = true;
    }
    if (isWhite && isBlack) //isGray
      break;
  }
  if (depth > 1)                  
    newnum = pow(5, (depth - 2)) * dir + num;
  if (isWhite && isBlack) {       //isGray 
    length /= 2;
    depth++;
    MatrixToNumber(row, col, length, depth, NW, newnum);
    MatrixToNumber(row, col + length, length, depth, NE, newnum);
    MatrixToNumber(row + length, col, length, depth, SW, newnum);
    MatrixToNumber(row + length, col + length, length, depth, SE, newnum);
  } else if (isBlack) {      //The node is black 
    BlackNode.insert(newnum);
  }
  return;                    //The block is full of either black or white 
}


