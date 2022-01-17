#include <iostream>
using namespace std;

#include "Date.cpp"
#include "Date.h"



int main()
{
	cout << "constructor(共15%))\n" ;
	Date d1; 
	Date d2(4,10,1992); 
	Date d3 (13, 1, 1999);
	Date d4 (12, 11, 1989);
	Date d5 (1, 15, 2005);
	Date d6 (3, 17, 2006);
	Date d7 (4, 30, 2007);
	cout << "\nDate d1 is: ";
	d1.Show();
	cout << "\n顯示1/1/2000(5%)\n ";
	cout << "\nDate d2 is: ";
	d2.Show();
	cout << "\n顯示4/10/1992(5%)\n ";
	cout << "\nDate d3 is: ";
	d3.Show();
	cout << "\n顯示1/1/2000 (5%)\n ";
	
	
	
	
	cout << "\n\nInput(共10%))\n" ;
	cout << "d1輸入2/31/2005 印出錯誤 並再次輸入 3/31/2010 \n ";
	d1.Input();
	cout << "\nDate d1 is: ";
	d1.Show();
	cout << "\n顯示3/31/2010  (5%)\n ";
	cout << "d3輸入3/7/-2010 印出錯誤 並再次輸入 3/7/2010 \n ";
	d3.Input();
	cout << "\nDate d3 is: ";
	d3.Show();
	cout << "\n顯示3/7/2010   (5%)\n ";
	
	
	cout << "\n\nShow and SetFormat(共25%)\n" ;
	d4.SetFormat('L'); 
	cout << "\nDate d4 is: ";
	d4.Show();
	cout << "\n顯示 Dec 11, 1989   (8%)\n ";
	d2.SetFormat('T');
	cout << "\nDate d2 is: ";
	d2.Show();
	cout << "\n顯示 04/10/92   (8%)\n ";
	d4.SetFormat('D');
	cout << "\nDate d4 is: ";
	d4.Show();
	cout << "\n顯示 12/11/1989    (9%)\n ";
	
	
	cout << "\n\nSet(共10%)\n" ;
	d2.Set(11,11,2002);
	cout << "\nDate d2 is: ";
	d2.Show();
	cout << "\n顯示11/11/02    (5%)\n ";
	cout << "\nd5輸入15,15,2002 格式錯誤回傳false(2%)\n";
	if (d5.Set(15,15,2002) == 1)
  		cout<<"true"<<endl;
 	else
  		cout<<"false"<<endl;
	cout << "\nDate d5 is: ";
	d5.Show();
	cout << "\n顯示1/15/2005    (3%)\n ";
	
	
	cout << "\n\nGetMonth()、GetDay()、GetYear() (共10%)\n" ;
	cout << "\nDate d6 Month is: "<<d6.GetMonth();
	cout << "\n顯示3   (4%)\n ";
	cout << "\nDate d6 Day is: "<<d6.GetDay();
	cout << "\n顯示17   (3%)\n "; 
	cout << "\nDate d6 Year is: "<<d6.GetYear(); 
	cout << "\n顯示2006   (3%)\n "; 
	
	
	cout << "\n\nIncrement (共10%)\n" ;
	d7.Increment();
	cout << "\nDate d7 is: ";
	d7.Show();
	cout << "\n顯示5/1/2007   (5%)\n ";
	d6.Increment(5);
	cout << "\nDate d6 is: ";
	d6.Show();  
	cout << "\n顯示3/22/2006   (5%)\n ";
	
	
	cout << "\n\nCompare (共10%)\n" ;
	cout << "\n d6 Compare d7: "<<d6.Compare(d7);
	cout << "\n顯示-1   (5%)\n ";
	cout << "\n d4 Compare d3: "<<d7.Compare(d6);
	cout << "\n顯示1   (5%)\n ";
	
	
	cout << "\n\nMakefile (共10%)\n" ;
	cout << "\nmake   (7%)\n ";
	cout << "\nmake clean   (3%)\n ";
	

	return 0;
} 
