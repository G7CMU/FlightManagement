#ifndef ECONOMYCLASS_H
#define ECONOMYCLASS_H

#include "Flight.h"
#include "Fastfood.h"
#include "FlightType.h"
class EconomyClass : public Flight
{
public:
	Fastfood fastFood;
	float priceOfFastfood;
	int vocher;
	int ageECN;
	float AggageWeightECN;
	
void input();
void output();
float tax();
FlightType classType();
float Totalprice();
};

#endif
