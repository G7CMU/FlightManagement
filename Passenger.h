#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <fstream>
#include "Date.h"
#include <string>

const string BASE_PASSENGER_PATH = "./data/passenger/";

using namespace std;
class Passenger
{
public:
	string id, name, phoneNumber, passengerID, sex;
	Date dateOfBirth;
	Passenger();
	void input();
	void output();
	int getday();
	int getmonth();
	int getyear();
	void saveToFile(ofstream &fo); // save to flight list
	void readFromFile(ifstream &fi); // read from flight list
	void saveToFile();
	bool readFromFile(string _passengerID);
	friend ostream &operator << (ostream &os , Passenger a);
	friend istream &operator >> (ostream &is, Passenger &a);
};
#endif
