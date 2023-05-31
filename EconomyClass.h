#ifndef ECONOMYCLASS_H
#define ECONOMYCLASS_H
#include <fstream>
#include "Flight.h"
#include "Fastfood.h"
#include "FlightType.h"

class EconomyClass : public Flight
{
public:
	FASTFOOD fastFood;
	float fastfoodPrice;
	int voucher;
	int ageECN;
	float aggageWeightECN;
	int foodChoice;
	void input();
	void output();
	void saveToFile(ofstream &fo);
	void readFromFile(ifstream &fi);
	float tax();
	float TotalPrice();
	FlightType getType();
};
#endif
