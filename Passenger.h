#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include "DateOfBirth.h"
#include <string>
using namespace std;
class Passenger
{
public:
	string id, name, phoneNumber, passengerID;
	DateOfBirth dateOfBirth;
	void input();
	void output();
	int getday();
	int getmonth();
	int getyear();
	friend ostream &operator << (ostream &os , Passenger a);
	friend istream &operator >> (ostream &is, Passenger &a);
};
#endif
