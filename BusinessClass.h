#ifndef BUSINESSCLASS_H
#define BUSINESSCLASS_H
#include "Flight.h"
#include "WaitingRoom.h"
#include "Card.h"
#include <iostream>

using namespace std;

class BusinessClass : public Flight
{
public:
	WaitingRoom waitRoom;
	Card card;
	string waitingFood, softDrinks, meal;
	int ageBSN;
	float softDrinksPrice, mealPrice, aggageWeightBSN;
void input();
void output();
float tax();
FlightType classType();
float Totalprice();
};
#endif
