#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
#include "Flight.h"
#include "Line.h"
#include "FlightType.h"
using namespace std;

class FirstClass:public Flight
{
public:
	PRIVATE_LINE privateLine;
	string drink, eat, service;
	float priceOfDrink, eatPrice, servicePrice, aggageWeightF;
	int roomEat, accumulation, ageF;
void input();
void output();
float tax();
FlightType classType();
float TotalPrice();
};
#endif
