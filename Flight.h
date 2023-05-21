#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <fstream>
#include "Passenger.h"

using namespace std;

class Flight
{
public:
	Passenger passenger;
	Date startDate;
	string airlinesLabel, flightRoute, startAirport, destinationAirport,
			flightID, flightNature, chair, destination, from, to, typeOfLuggage;
	int door;
	float flightLength, timeDelay, InitialPrice;

	Flight();
	virtual void input();
	virtual void output();
	virtual void saveToFile(ofstream &fo);
	virtual void readFromFile(ifstream &fi);
	virtual float tax() = 0;
	virtual float TotalPrice() = 0;
};

#endif
