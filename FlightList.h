#ifndef FLIGHTLIST_H
#define FLIGHTLIST_H

#include <iostream>
#include <vector>
#include "Flight.h"
#include "EconomyClass.h"
#include "BusinessClass.h"
#include "FirstClass.h"
#include "Date.h"

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
	void sortByPriceAsc();
	void sortByPriceDesc();
	void sortByidAsc();
	void sortByidDesc();
	void findAll();
	void sortBybirth();
	void sortDateStart();
	void sortByDateOfBirth();
	void sortByStartDate();
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
	void removeFlightById();
	void removeFlightByDoor();
	void removeFlightByChair();
	void removeFlightByDestination();
	void appendFlight();
	void rotateList();
	void printinvoice();
	void sortDateStart1();
	void minPrice();
	void maxPrice();
	void sortDateStart2();
	void sortByLengthAsc();
	void sortByLengthDesc();
	void sortByTaxAsc();
	void sortByTaxDesc();
	void sortByBirth1();
	void editflightRoute();
	void editairlinesLabel();
	void editDoor();
	void editChair();
	void edittypeOfLuggage();
	void removepassengerID();
};
#endif
