#include "date.h"

int main()
{
	
	Date D1(2014, 12, 31);
	Date D2(2011, 12, 31);
	Date D3;
	cout << "Enter Date: " << endl;
	cin >> D3;
	
	cout << "D1 is: \t";
	D1.Show();
	cout << "D2 is: \t";
	D2.Show();
	cout << "D3 is: \t";
	D3.Show();

	cout << "Prefix " << endl;
	D3 = ++D2;
	cout << "D3 is: \t";
	D3.Show();	
	cout << "D2 is: \t";
	D2.Show();

	cout << "Postfix " << endl;
	D3 = D2++;
	cout << "D3 is: \t";
	D3.Show();	
	cout << "D2 is: \t";
	D2.Show();
	
	cout << "Constructor with a single integer parameter " << endl;
	Date D4(365);
	cout << "D4 is: \t";
	D4.Show();

	cout << "Conversion constructor " << endl;
	cout << "Allows automatic type conversions from int to Date" << endl;
	Date D5 = 365; 
	cout << "D5 is: \t";
	D5.Show();
	// 365 was converted to 'Date' then perform addition operation
	D5 = D5 + 365; 
	cout << "After adding 365 " << endl;
	cout << "D5 is: \t";
	D5.Show();
	
	D5++;
	cout << "D5 is: \t";
	D5.Show();

	// Another way of initializing object
	Date D6 = Date(2014,9,30);
	cout << "D6 is: \t";
	D6.Show();

	return 0;
}