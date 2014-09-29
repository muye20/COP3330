#include "date.h"

Date::Date()
{
	SetDate(DEFAULT_YEAR, DEFAULT_MONTH, DEFAULT_DAY);	
}

Date::Date(int d)
{
	SetDate(DEFAULT_YEAR, DEFAULT_MONTH, DEFAULT_DAY);
	
	if(d >= DEFAULT_DAY)
		Convert(d, *this);	
}

Date::Date(int y, int m, int d)
{
	if(!SetDate(y, m, d))
		SetDate(DEFAULT_YEAR, DEFAULT_MONTH, DEFAULT_DAY);	
}

Date::~Date()
{

}

bool Date::SetDate(int y, int m, int d)
{
	bool ret;
	ret = false;

	year = y;

	if(m <= MAX_MONTH && m >= DEFAULT_MONTH)
	{
		month = m;

		if(d >= DEFAULT_DAY && d <= DAYS[month - 1])
		{
			day = d;
			ret = true;
		}
	}

	return ret;
}

void Convert(int d, Date &D)
{
	while(d > DAYS[D.month - 1])
	{
		d = d - DAYS[D.month - 1];
		D.month = D.month + 1;

		if(D.month > MAX_MONTH)
		{
			D.month = DEFAULT_MONTH;
			D.year = D.year + 1;
		}
	}

	D.day = d;
}

ostream &operator << (ostream &output, const Date &D)
{
	output.fill('0');
	output << setw(4) << D.year << "-" << setw(2) << D.month << "-" << setw(2) << D.day;
	return output;
}

istream &operator >> (istream &input, Date &D)
{
	int y, m, d;
	
	input >> y;
	input.ignore();
	input >> m;
	input.ignore();
	input >> d;
	input.ignore();

	D.SetDate(y,m,d);

	return input;
}

Date operator+(const Date &D1, const Date &D2)
{
	Date ans;

	ans.year = D1.year + D2.year;
	ans.month = D1.month + D2.month;
	ans.day = D1.day + D2.day;

	while(ans.month > MAX_MONTH)
	{
		ans.month = ans.month - MAX_MONTH;
		ans.year = ans.year + 1;
	}

	Convert(ans.day, ans);

	return ans;
}

void Date::Show() const
{
	cout << *this << endl; 
}

Date Date::operator++(int) // postfix
{
	Date temp = *this;
	day = day + 1;
	Convert(day, *this);

	return temp;
}

Date Date::operator++() // prefix
{
	day = day + 1;
	Convert(day, *this);

	return *this;
}

