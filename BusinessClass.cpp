#include "BusinessClass.h"

void BusinessClass::input()
{
	Flight::input();
	cout << "WaitRoom: ";
	waitRoom = ROOM_OF_FOUR;
	// them chuc nang 
	cin.ignore();
	cout<<"Waiting Food: ";
	getline(cin, waitingFood);
	cout<<"Soft Drinks: ";
	getline(cin, softDrinks);
	cout<<"SoftDrinksPrice: ";
	cin>>softDrinksPrice;
	cout<<"Meal: ";
	getline(cin, meal);
	cout<<"MealPrice: ";
	cin>>mealPrice;
	cout<<"Card: ";
	card = NODE;
	// them chuc nang
	getline(cin, eat);
	cout << "Age BSN: ";
	cin >> ageBSN;
	cout << "Aggage Weight BSN: ";
	cin >> aggageWeightBSN;
}
void BusinessClass::output()
{
	Flight::output();
	cout << "WaitRoom: ";
	waitRoom = ROOM_OF_FOUR;
	if (waitRoom = ROOM_OF_FOUR) cout<<"Wait Room: ROOM_OF_FOUR";
	// them tiep 
	cin.ignore();
	cout<<"Waiting Food: "<<waitingFood<<endl;
	cout<<"Soft Drinks: "<<softDrinks<<endl;
	cout<<"SoftDrinksPrice: "<<softDrinksPrice<<endl;
	cout<<"Meal: "<<meal<<endl;
	cout<<"MealPrice: "<<mealPrice<<endl;
	cout<<"Card: ";
	if (card = NODE) cout<<"Card: NODE";
	// them chuc nang
	cout << "Age BSN: "<<ageBSN<<endl;
	cout << "Aggage Weight BSN: "<<aggageWeightBSN<<endl;
}
float BusinessClass::tax()
{
	int sale;
		if (card > 15) sale = InitialPrice*0.15;
		else if (card > 10) sale = InitialPrice*0.1;
		else sale=0;
	int pay;
		if (ageBSN > 61 && ageBSN < 11) pay = InitialPrice*0.1;
		else pay = 0;
	int pay1;
		if (aggageWeightBSN>15) pay1=InitialPrice*0.3;
		else pay1=0;
	return sale-pay-pay1;
}
FlightType BusinessClass::classType()
{
	return BUSINESS;
}
float BusinessClass::price()
{
	return BusinessClass::tax()+InitialPrice+eatPrice;
}
