#ifndef ECONOMYCLASS_H
#define ECONOMYCLASS_H
#include <fstream>
#include "Flight.h"
#include "Fastfood.h"

class EconomyClass : public Flight
{
public:
	FASTFOOD fastFood;
	float fastfoodPrice;
	int voucher;
	int ageECN;
	float aggageWeightECN;

	void input();
	void output();
	void saveToFile(ofstream &fo);
	void readFromFile(ifstream &fi);
	float tax();
	float TotalPrice();
};
#endif
