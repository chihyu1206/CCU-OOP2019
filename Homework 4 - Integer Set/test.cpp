// Test program for the IntSet class
#include <iostream>
#include "intset.h"
#include "intset.cpp"
int main()
 {
 	
    IntSet Empty; // the empty set
 	// for singleton sets {0} .. {3}
    IntSet S0(10), S1(11), S2(21), S3(31);
    IntSet A, B, C, D, E, F, G; // to hold computed sets
    cout << "���`�S�����~ (constructor15%)\n " << endl;
    
    
 	// Show and test empty set
    cout << "\nShow and test the empty set...\n";
    cout << "Empty = ";
    Empty.setPrint();
    cout << " has "<< Empty.size() << " elements." << endl;
    cout << "��� Empty ���Ŷ��X��{--} ( setPrint 5%)" << endl;
    cout << "���0  elements (size 5%)\n" << endl;
    
    if ( Empty.isEmpty() )
        cout << "The set is empty\n" << endl;
    else
        cout << "The set is *not* empty" << endl;
    cout << "���The set is empty �άO true(isEmpty 5%)\n" << endl;
        
        
    // Show and test {1}
     cout << "S1 = ";
     S1.setPrint();
     cout << " has "<< S1.size() << " elements." << endl;
     cout << "���S1 ���X��11 ( setPrint 5%)" << endl;
     cout << "���1  elements (size 5%)\n" << endl;
     if ( S1.isEmpty() )
        cout << "Set S1 is empty" << endl;
     else
        cout << "Set S1 is *not* empty" << endl;
    cout << "���Set S1 is *not* empty �άO False(isEmpty 5%)\n" << endl;
    
    
     // Compute some unions
     A = S2.setUnion(Empty);
     S2.setPrint();
     cout << " union ";
     Empty.setPrint();
     cout << " = ";
     A.setPrint();
     cout << "\n���{21} union {} = {21}   (setUnion 3%)\n" << endl;
     cout << endl << endl;

     A = S0.setUnion(S3);
     B = S1.setUnion(S2);
     A.setPrint();
     cout << " union ";
     B.setPrint();
     cout << " = ";
     C = A.setUnion(B);
     C.setPrint();
     cout << "\n���{10 31} union {11 21} = {10 11 21 31} (setUnion 3%)\n" << endl;
     cout << endl << endl;
     
     A = A.setUnion(S2);
     B = B.setUnion(S0);
     A.setPrint();
     cout << " union ";
     B.setPrint();
     cout << " = ";
     D = A.setUnion(B);
     D.setPrint();
     cout << "\n���{10 21 31} union {10 11 21} = {10 11 21 31} (setUnion 4%)\n" << endl;
     cout << endl << endl;
     
     
     // Compute intersection, relative complement, and symmetric difference
     E = A.setIntersection(S3);
     cout << "Intersection of ";
     A.setPrint();
     cout << " and ";
     S3.setPrint();
     cout << " is: ";
     E.setPrint();
     cout << "\n���Intersection of {10 21 31} and {31} is {31} (setIntersection 10%)\n" << endl;
     cout << endl << endl;
     
     G = D.relativeComplement(S0);
     cout << "Relative complement of ";
     D.setPrint();
     cout << "and ";
     S0.setPrint();
     cout << " is: ";
     G.setPrint();
     cout << "\n���Relative complement of {10 11 21 31} and {10} is {11 21 31} (relativeComplement 10%)\n" << endl;
     cout << endl << endl;
     
     F = B.symmetricDifference(A);
     cout << "Symmetric difference of ";
     B.setPrint();
     cout << " and ";
     A.setPrint();
     cout << " is: ";
     F.setPrint();
     cout << "\n���Symmetric difference of {10 11 21} and {10 21 31} is {11 31} (symmetricDifference 10%)\n" << endl;
     cout << endl << endl;

     // Test if two sets are equal
     cout << "Set E: ";
     E.setPrint();
     cout << endl;
     cout << "Set S3: ";
     S3.setPrint();
     cout << endl;
     if ( E.isEqualTo(S3) )
     cout << "Set E is equal to set S3";
     else
        cout << "Set E is not equal to set S3";
     cout << "\n���Set E is equal to set S3 �άO True(isEqualTo 5%)\n" << endl;
     cout << endl;
     
     
     cout << "Set S1: ";
     S1.setPrint();
     cout << endl;
     cout << "Set S3: ";
     S3.setPrint();
     cout << endl;
     if ( S1.isEqualTo(S3) )
     cout << "Set S1 is equal to set S3";
     else
        cout << "Set S1 is not equal to set S3";
     cout << "\n���Set S1 is not equal to set S3 �άO False(isEqualTo 5%)\n" << endl;
     cout << endl;
     
    cout << "\nMakefile (�@5%)" ;
	cout << "\nmake   (4%) ";
	cout << "\nmake clean   (1%) ";
     
     
     
     return 0;
}
