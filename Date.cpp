#include "Date.h"

bool isValidDate(int day, int month, int year)
{
	//					     1   2   3   4   5   6   7   8   9  10  11  12
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leapYear = year % 4 == 0 || (year % 100 == 0 && year % 400 == 0);

	if (leapYear)
		daysInMonth[2] = 29;

	if (month < 0 || month > 12)
		return false;
	if (day < 0 || day > daysInMonth[month])
		return false;

	return true;
}
Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
void Date::input()
{
	int _day, _month, _year;
	do
	{
		cout << "Day: ";
		cin >> _day;
		cout << "Month: ";
		cin >> _month;
		cout << "Year: ";
		cin >> _year;

		if (!isValidDate(_day, _month, _year))
		{
			cout << "Sai dinh dang ngay thang. Vui long nhap lai!\n";
		}
	} while (!isValidDate(_day, _month, _year));

	this->day = _day;
	this->month = _month;
	this->year = _year;
}
void Date::output()
{
	cout << day << "/" << month << "/" << year << (year < 0 ? " BCE" : "");
}
istream &operator>>(istream &is, Date &d)
{
	d.input();
}
ostream &operator<<(ostream &os, Date &d)
{
	d.output();
}
void Date::saveToFile(ofstream &fo)
{
	fo << day << " " << month << " " << year << "\n";
}
void Date::readFromFile(ifstream &fi)
{
	fi >> day >> month >> year;
}
//string Date::toString()
//{
//	char toReturn[30];
//	char _month[2];
//	char _day[2];
//	sprintf(_month, "%s%d", (this->month < 10 ? "0" : ""), this->month);
//	sprintf(_day, "%s%d", (this->day < 10 ? "0" : ""), this->day);
//	sprintf(toReturn, "%d%s%s", year, _month, _day);
//	return toReturn;
//}
//
//bool operator==(Date d1, Date d2)
//{
//	return d1.toString() == d2.toString();
//}
//bool operator<(Date d1, Date d2)
//{
//	return d1.toString() < d2.toString();
//}
//bool operator>(Date d1, Date d2)
//{
//	return d1.toString() > d2.toString();
//}
