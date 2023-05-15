#ifndef FLIGHTLIST_H
#define FLIGHTLIST_H

#include <iostream>
#include "Flight.h"
#include "EconomyClass.h"
#include "BusinessClass.h"
#include "FirstClass.h"

using namespace std;

class FlightList
{
public:
	int k;
	Flight* list[100];
	FlightList();
	void input();
	void output();
	void sortBirth();
	void getFromFile();
	void exportToFile();
	float totalPrice();
	float minPrice();
 	float maxPrice();
	void sortByPriceAsc();
	void sortByPriceDesc();
	void sortByidAsc();
	void sortByidDesc();
	void sortBybirth();
	void findById();
	void findByName();
	void findPassengerByFlight();
	void findPassengerByDoor();
	void findPassengerByDestination();
	void sortByTime();
	void editPassengerById();
	void editFlight();
	void editTime();
	void editDestination();
	void removeById();
	void removeByName();
	void removeByDoor();
	void removeByChair();
	void removeByDestination();
	void appendPassenger();
	void rotateList();
	void printinvoice();
};
#endif
