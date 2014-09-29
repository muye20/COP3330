#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int DEFAULT_YEAR = 0;
const int DEFAULT_MONTH = 1;
const int DEFAULT_DAY = 1;
const int MAX_MONTH = 12;
const int DAYS[MAX_MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {

	friend ostream &operator << (ostream &output, const Date &D);
	friend istream &operator >> (istream &input, Date &D);
	friend Date operator+(const Date& D1, const Date& D2);
	friend void Convert(int d, Date &D);

public:

	Date(); // default constructor
	Date(int d); // conversion constructor
	Date(int y, int m, int d); // constructor takes 3 parameters
	~Date(); // destructor
	bool SetDate(int y, int m, int d);
	void Show() const;
	Date operator++(); // prefix
	Date operator++(int); // postfix

private:
	int year;
	int month;
	int day;
};