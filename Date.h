#ifndef DATE_H
#define DATE_H

#include <fstream>
#include <iostream>

using namespace std;

class Date
{
public:
	int day, month, year;
	
Date();
Date(int day, int month, int year);
void input();
void output();
void saveToFile(ofstream &fo);
void readFromFile(ifstream &fi);
friend istream &operator>>(istream &is, Date &d);
friend ostream &operator<<(ostream &os, Date &d);
friend bool isValidDate(int day, int month, int year);
};

#endif
