#ifndef DATE_H
#define DATE_H

class Date
{
public:
	int day, month, year;
	
Date();
Date(int day, int month, int year);
void input();
void output();
friend istream &operator>>(istream &is, Date &d);
friend ostream &operator<<(ostream &os, Date &d);
friend bool isValidDate(int day, int month, int year);
};

#endif
