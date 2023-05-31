#ifndef FLIGHTLIST_H
#define FLIGHTLIST_H

#include <iostream>
#include <vector>
#include "Flight.h"
#include "EconomyClass.h"
#include "BusinessClass.h"
#include "FirstClass.h"

using namespace std;

class FlightList
{
public:
	vector<Flight*> list;

	FlightList();
	void input();
	void output();
	void sortBirth();
	void getFromFile();
	void exportToFile();
	void TotalPrice();
//	float minPrice();
//	float maxPrice();
	void sortByPriceAsc();
	void sortByPriceDesc();
	void sortByidAsc();
	void sortByidDesc();
	// void findAll();
	void sortBybirth();
	void sortDateStart();
	void findById();
	void findByName();
	void findPassengerByFlight();
	void findPassengerByDoor();
	void findPassengerByDestination();
	void sortByTime();
	void editPassengerByPhoneNumber();
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
	void sortDateStart1();
	void minPrice();
	void maxPrice();
};
#endif
