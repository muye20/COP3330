#include "date.h"

int main()
{
	/*
	Date D1(2014, 12, 31);
	Date D2(2011, 12, 31);
	Date D3;

	//cin >> D2;
	D2.Show();
	D1.Show();
	//cout << D1 << endl;

	++D2;
	D2.Show();

	D3 = D2++;
	D2.Show();
	D3.Show();
	*/

	Date D4 = Date(2015, 10, 21);
	D4.Show();

	Date D5(365);
	//Convert(365, D5);
	D5 = D5 + 365;
	D5.Show();

	D5++;
	D5.Show();

	Date D6 = 3650;
	D6.Show();


	return 0;
}