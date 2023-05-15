#ifndef ECONOMYCLASS_H
#define ECONOMYCLASS_H

#include "Flight.h"
#include "Fastfood.h"
#include "FlightType.h"
class EconomyClass : public Flight
{
public:
	FASTFOOD fastFood;
	float fastfoodPrice;
	int vocher;
	int ageECN;
	float aggageWeightECN;
	
void input();
void output();
float tax();
FlightType classType();
float TotalPrice();
};

#endif
