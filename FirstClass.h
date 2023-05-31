#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
#include <fstream>
#include "Flight.h"
#include "Line.h"

using namespace std;

class FirstClass : public Flight
{
public:
	PRIVATE_LINE privateLine;
	string drink, eat, service;
	float priceOfDrink, eatPrice, servicePrice, aggageWeightF;
	int roomEat, accumulation, ageF;
	void input();
	void output();
	void saveToFile(ofstream &fo);
	void readFromFile(ifstream &fi);
	float tax();
	float TotalPrice();
	int lineChoice;
	friend ifstream& operator>>(ifstream &is, PRIVATE_LINE &w);
	FlightType getType();
};
#endif
