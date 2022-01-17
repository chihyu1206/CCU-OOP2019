#include <iostream>
#include "intset.h"
using namespace std;
int main(void) {
  IntSet Empty;
  IntSet S0(0), S1(1), S2(2), S3(3);
  IntSet A, B, C, D, E, F, G;
  cout << "\nShow and test the empty set...\n";
  cout << "Empty = ";
  Empty.setPrint(); 
  cout << " has " << Empty.size() << " elements." << endl;
  if (Empty.isEmpty())
    cout << "The set is empty\n" << endl;
  else
    cout << "The set is *not* empty\n" << endl;

  cout << "S1 = ";
  S1.setPrint();
  cout << " has " << S1.size() << " elements." << endl;
  if (S1.isEmpty())
    cout << "Set S1 is empty\n" << endl;
  else
    cout << "Set S1 is *not* empty\n" << endl;
  
  A = S0.setUnion(Empty);
  S0.setPrint();
  cout << " union ";
  Empty.setPrint();
  cout << " = ";
  A.setPrint();
  cout << endl << endl;
  A = S0.setUnion(S1);
  B = S3.setUnion(S2);
  A.setPrint();
  cout << " union ";
  B.setPrint();
  cout << " = ";
  C = A.setUnion(B);
  C.setPrint();
  cout << endl << endl;

  A = A.setUnion(S3);
  B = B.setUnion(S0);
  A.setPrint();
  cout << " union ";
  B.setPrint();
  cout << " = ";
  D = A.setUnion(B);
  D.setPrint();
  cout << endl << endl;

  E = A.setIntersection(S3);
  cout << "Intersection of ";
  A.setPrint();
  cout << " and ";
  S3.setPrint();
  cout << " is: ";
  E.setPrint();
  cout << endl << endl;

  G = D.relativeComplement(S0);
  cout << "Relative complement of ";
  D.setPrint();
  cout << " and ";
  S0.setPrint();
  cout << " is: ";
  G.setPrint();
  cout << endl << endl;

  F = B.symmetricDifference(A);
  cout << "Symmetric difference of ";
  B.setPrint();
  cout << " and ";
  A.setPrint();
  cout << " is: ";
  F.setPrint();
  cout << endl << endl;

  cout << "Set A: ";
  A.setPrint();
  cout << endl;
  cout << "Set B: ";
  B.setPrint();
  cout << endl;
  if (A.isEqualTo(B))
    cout << "Set A is equal to set B\n";
  else
    cout << "Set A is not equal to set B\n";
  return 0;
}
