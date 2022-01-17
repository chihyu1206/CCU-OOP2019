#include<iostream>
#include "BigInt.h"
#include "MyVector.h"
using namespace std;
int main()
{
	//Part1
	int a[] = {2, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
	BigInt A(a, sizeof(a) / sizeof(a[0]));
	cout<<A.length()<<endl;
	cout << "Show 50 (1B-5%)\n " << endl;
	cout<<A.getNum()<<endl;
	cout << "Show 22345678901234567890123456789012345678901234567899 (1B-5%)\n " << endl;
	cout<<A[0]<<endl;
	cout << "Show 2 (1A-6%)\n " << endl;
	
	BigInt B;
	B = A;//assignment operator
	cout<<B.length()<<endl;
	cout<<B.getNum()<<endl;
	cout << "Show 50 " << endl;
	cout << "Show 22345678901234567890123456789012345678901234567899 (1F-6%) \n " << endl;
	
	BigInt C = B;//copy constructor
	cout<<B.length()<<endl;
	cout<<B.getNum()<<endl;
	cout << "Show 50 " << endl;
	cout << "Show 22345678901234567890123456789012345678901234567899 (1E-6%) \n " << endl;
	
	
	C++;
	cout<<C.length()<<endl;
	cout<<C.getNum()<<endl;
	cout << "Show 50 " << endl;
	cout << "Show 22345678901234567890123456789012345678901234567900 (1D-6%) \n " << endl;
	
	++C;
	cout<<C.length()<<endl;
	cout<<C.getNum()<<endl;
	cout << "Show 50" << endl;
	cout << "Show 22345678901234567890123456789012345678901234567901 (1C-6%) \n " << endl;
	
	//Part2
	double V_1[] = {1.1, 2.2 };
	MyVector V1(sizeof(V_1) / sizeof(V_1[0]), V_1);
	cout<<V1<<endl;
	cout << "Show <1.1, 2.2> (2A-5%  2D-3%) \n " << endl;
	
	double V_2[] = {7.7, 6.6};
	MyVector V2(sizeof(V_2) / sizeof(V_2[0]), V_2);
	cout<<V2<<endl;//
	cout << "Show <7.7, 6.6> (2A-5%  2D-3%) \n " << endl;
	
	MyVector V3;
	cout<<V3<<endl;
	cout << "Show <> (2D-4%) \n " << endl;
	
	cout<<V1<<"*"<<V2<<"="<<V1*V2<<endl;
	cout << "Show <1.1, 2.2>*<7.7, 6.6>=22.99 (2E-3%) \n " << endl;
	
	cout<<V1<<"*"<<"2"<<"="<<V1*2<<endl;
	cout << "Show <1.1, 2.2>*2=<2.2, 4.4> (2F-3%) \n " << endl;
	
	cout<<V1<<"+"<<V2<<"="<<V1+V2<<endl;
	cout << "Show <1.1, 2.2>+<7.7, 6.6>=<8.8, 8.8> (2G-3%) \n " << endl;
	
	cout<<V1<<"*"<<V2<<"*"<<"5"<<"="<<V1*V2*5<<endl;
	cout << "Show <1.1, 2.2>*<7.7, 6.6>*5=114.95 (2F-2% 2E-3%) \n " << endl;
	
	cout<<V2<<"+"<<"3"<<"*"<<V1<<"="<<V2+3*V1<<endl;
	cout << "Show <7.7, 6.6>+3*<1.1, 2.2>=<11.0, 13.2> (2F-1% 2G-3%) \n " << endl;

	V3 = V1;
	cout<<V3<<endl;
	cout << "Show <1.1, 2.2> (2C-6%) \n " << endl;
	
	MyVector V4 = V3;
	cout<<V4<<endl;
	cout << "Show <1.1, 2.2> (2B-6%) \n " << endl;
	return 0;
}
