#include <iostream>
#include "distance.h"

using namespace std;

#define ECHO_ON 0

template <class T>
void ECHO(T var)
{ if (ECHO_ON)    cout << " << " << var << " >>\n";
else cout << '\n';  }


int main()
{
	Distance d1, d2, d3(123456), d4(987654321), d5(-1425), d6(192837474);
	Distance c1(4, 120, 2, 1),
		c2(-4, 120, 2, 1),
		c3(4, -120, 2, 1),
		c4(4, 120, -2, 1),
		c5(4, 120, 2, -1),
		c6(2, 1793, 1, 17),
		c7(31, 1900, 17, 50),
		c8(62, 9500, 124, 2345);

	cout << "d1 = " << d1 << '\n';
	cout << "d2 = " << d2 << '\n';
	cout << "d3 = " << d3 << '\n';
	cout << "d4 = " << d4 << '\n';
	cout << "d5 = " << d5 << '\n';
	cout << "d6 = " << d6 << '\n';
	cout << '\n';
	cout << "c1 = " << c1 << '\n';
	cout << "c2 = " << c2 << '\n';
	cout << "c3 = " << c3 << '\n';
	cout << "c4 = " << c4 << '\n';
	cout << "c5 = " << c5 << '\n';
	cout << "c6 = " << c6 << '\n';
	cout << "c7 = " << c7 << '\n';
	cout << "c8 = " << c8 << '\n';
	cout << '\n';


	char ch;
	do
	{
		cout << "Enter first Distance object (MILES,YDS,FT,IN):  ";
		cin >> d1;
		//   ECHO(d1);

		cout << "Enter second Distance object (MILES,YDS,FT,IN):  ";
		cin >> d2;
		//   ECHO(d2);

		cout << "\n\n"; 
		cout << d1 << " + " << d2 << " = " << d1 + d2 << '\n';
		cout << d1 << " - " << d2 << " = " << d1 - d2 << '\n';
		cout << d1 << " * 3 = " << d1 * 3 << '\n';
		cout << d1 << " * 20 = " << d1 * 20 << '\n';
		cout << d1 << " * 100 = " << d1 * 100 << '\n';

		if (d1 < d2) 	cout << "d1 < d2 " << " is TRUE\n";
		if (d1 > d2) 	cout << "d1 > d2 " << " is TRUE\n";
		if (d1 <= d2) 	cout << "d1 <= d2 " << " is TRUE\n";
		if (d1 >= d2) 	cout << "d1 >= d2 " << " is TRUE\n";
		if (d1 == d2) 	cout << "d1 == d2 " << " is TRUE\n";
		if (d1 != d2) 	cout << "d1 != d2 " << " is TRUE\n\n";

		cout << d1 << " + 654321 = " << d1 + 654321 << '\n';
		cout << d2 << " + 15263748 = " << d2 + 15263748 << '\n';
		cout << d1 << " + 100 = " << d1 + 100 << '\n';
		cout << d2 << " + 123579 = " << d2 + 123579 << "\n\n";

		cout << "d1++ returns: " << d1++ << '\n';
		cout << "Now d1 = " << d1 << '\n';

		cout << "++d1 returns: " << ++d1 << '\n';
		cout << "Now d1 = " << d1 << '\n';

		cout << "d2-- returns: " << d2-- << '\n';
		cout << "Now d2 = " << d2 << '\n';

		cout << "--d2 returns: " << --d2 << '\n';
		cout << "Now d2 = " << d2 << '\n';
		cout << '\n';

		cout << "\nAnother pair of distance values? (y/n): ";
		cin >> ch;
		ECHO(ch);

	} while (ch == 'Y' || ch == 'y');

	cout << "Demonstrating ++ and -- operators now:\n\n";


	const int LISTSIZE = 10;
	Distance list[LISTSIZE] = 
	{  Distance(2,1758,1,10) , Distance(3,1,1,1) , 
	Distance(4,1759,2,11) , Distance(4,0,0,1) ,
	Distance(1,1759,2,7) , Distance(7,0,1,0) ,
	Distance(7,1758,2,11) , Distance(5,1,0,1) ,
	Distance(0,0,0,0)    , Distance(0,0,0,1)   };


	for (int i = 0; i < LISTSIZE; i+=2)
	{
		cout << "list[" << i << "]++ returns: " << list[i]++ << '\n';
		cout << "Now list["<<i<<"] = " << list[i] << "\n\n";

		cout << "++list[" << i << "] returns: " << ++list[i] << '\n';
		cout << "Now list["<<i<<"] = " << list[i] << "\n\n";

		cout << "list[" << i+1 << "]-- returns: " << list[i+1]-- << '\n';
		cout << "Now list["<<i+1<<"] = " << list[i+1] << "\n\n";

		cout << "--list[" << i+1 << "] returns: " << --list[i+1] << '\n';
		cout << "Now list["<<i+1<<"] = " << list[i+1] << "\n\n";
	}

	return 0;
}

