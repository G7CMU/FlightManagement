#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include "Passenger.h"
#include "FlightType.h"
using namespace std;

class Flight 
{
public:
	Passenger a;
	Date startDate;
	string airlinesLabel, flightRoute, startAirport, destinationAirport,
	flightID, flightNature, chair, destination, from, to, passengerID, typeOfLuggage;  
	int door;
	float flightLength, timeDelay, initialPrice;
	
Flight();
virtual void input();
virtual void output();
virtual float tax() = 0;
virtual FlightType classType();
virtual float TotalPrice() = 0;
};

#endif
