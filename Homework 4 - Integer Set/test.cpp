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
    cout << "正常沒有錯誤 (constructor15%)\n " << endl;
    
    
 	// Show and test empty set
    cout << "\nShow and test the empty set...\n";
    cout << "Empty = ";
    Empty.setPrint();
    cout << " has "<< Empty.size() << " elements." << endl;
    cout << "顯示 Empty 為空集合或{--} ( setPrint 5%)" << endl;
    cout << "顯示0  elements (size 5%)\n" << endl;
    
    if ( Empty.isEmpty() )
        cout << "The set is empty\n" << endl;
    else
        cout << "The set is *not* empty" << endl;
    cout << "顯示The set is empty 或是 true(isEmpty 5%)\n" << endl;
        
        
    // Show and test {1}
     cout << "S1 = ";
     S1.setPrint();
     cout << " has "<< S1.size() << " elements." << endl;
     cout << "顯示S1 集合為11 ( setPrint 5%)" << endl;
     cout << "顯示1  elements (size 5%)\n" << endl;
     if ( S1.isEmpty() )
        cout << "Set S1 is empty" << endl;
     else
        cout << "Set S1 is *not* empty" << endl;
    cout << "顯示Set S1 is *not* empty 或是 False(isEmpty 5%)\n" << endl;
    
    
     // Compute some unions
     A = S2.setUnion(Empty);
     S2.setPrint();
     cout << " union ";
     Empty.setPrint();
     cout << " = ";
     A.setPrint();
     cout << "\n顯示{21} union {} = {21}   (setUnion 3%)\n" << endl;
     cout << endl << endl;

     A = S0.setUnion(S3);
     B = S1.setUnion(S2);
     A.setPrint();
     cout << " union ";
     B.setPrint();
     cout << " = ";
     C = A.setUnion(B);
     C.setPrint();
     cout << "\n顯示{10 31} union {11 21} = {10 11 21 31} (setUnion 3%)\n" << endl;
     cout << endl << endl;
     
     A = A.setUnion(S2);
     B = B.setUnion(S0);
     A.setPrint();
     cout << " union ";
     B.setPrint();
     cout << " = ";
     D = A.setUnion(B);
     D.setPrint();
     cout << "\n顯示{10 21 31} union {10 11 21} = {10 11 21 31} (setUnion 4%)\n" << endl;
     cout << endl << endl;
     
     
     // Compute intersection, relative complement, and symmetric difference
     E = A.setIntersection(S3);
     cout << "Intersection of ";
     A.setPrint();
     cout << " and ";
     S3.setPrint();
     cout << " is: ";
     E.setPrint();
     cout << "\n顯示Intersection of {10 21 31} and {31} is {31} (setIntersection 10%)\n" << endl;
     cout << endl << endl;
     
     G = D.relativeComplement(S0);
     cout << "Relative complement of ";
     D.setPrint();
     cout << "and ";
     S0.setPrint();
     cout << " is: ";
     G.setPrint();
     cout << "\n顯示Relative complement of {10 11 21 31} and {10} is {11 21 31} (relativeComplement 10%)\n" << endl;
     cout << endl << endl;
     
     F = B.symmetricDifference(A);
     cout << "Symmetric difference of ";
     B.setPrint();
     cout << " and ";
     A.setPrint();
     cout << " is: ";
     F.setPrint();
     cout << "\n顯示Symmetric difference of {10 11 21} and {10 21 31} is {11 31} (symmetricDifference 10%)\n" << endl;
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
     cout << "\n顯示Set E is equal to set S3 或是 True(isEqualTo 5%)\n" << endl;
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
     cout << "\n顯示Set S1 is not equal to set S3 或是 False(isEqualTo 5%)\n" << endl;
     cout << endl;
     
    cout << "\nMakefile (共5%)" ;
	cout << "\nmake   (4%) ";
	cout << "\nmake clean   (1%) ";
     
     
     
     return 0;
}
