#ifndef DATE_H
#define DATE_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int SEC_IN_ONE_DAY = 86400;

class Date
{
public:
	int day, month, year;
	bool leapYear;
	Date();
	Date(int day, int month, int year);
	void input();
	void output();
	void saveToFile(ofstream &fo);
	void readFromFile(ifstream &fi);
	string toString();
	friend istream &operator>>(istream &is, Date &d);
	friend ostream &operator<<(ostream &os, Date &d);
	friend bool isValidDate(int day, int month, int year);
};

bool operator==(Date d1, Date d2);
bool operator<(Date d1, Date d2);
bool operator>(Date d1, Date d2);
#endif
