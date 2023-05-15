#include "EconomyClass.h"
#include "Flight.h"

void EconomyClass::input()
{
	Flight::input();
	cout << "Fastfood: ";
	fastFood = FRIES;
	//them chuc nang
	getline(cin, fastFood);
	cout << "Fastfood price: ";
	cin >> priceOfFastfood;
	cout<<"Vocher: ";
	cin>>vocher;
	cout << "Age ACN: ";
	cin >> ageECN;
	cout << "Aggage Weight ECN: ";
	cin >> aggageWeightECN;
}
void EconomyClass::output()
{
	Flight::output();
	cout << "Fastfood: " << fastFood << endl;
	cout << "Fastfood price: " << priceOfFastfood << endl;
	cout << "Vocher: " << vocher << endl;
	cout << "Age ECN: " << ageECN << endl;
	cout << "Aggage Weight ECN: " << aggageWeightECN << endl;
}
float EconomyClass::tax()
{
	int sale;
		if (vocher > 20) sale = InitialPrice*0.2;
		else if (vocher > 10) sale = InitialPrice*0.1;
		else sale=0; 
	int pay;
		if (ageECN > 60 && ageECN < 10) pay = InitialPrice*0.1;
		else pay = 0;
	int pay1;
		if (aggageWeightECN>10) pay1=InitialPrice*0.3;
		else pay1=0;
	return pay+pay1-sale;
}
FlightType EconomyClass::classType()
{
	return ECONOMY;
} 
float EconomyClass::Totalprice()
{
	return EconomyClass::tax()+InitialPrice+fastFoodPrice;
}
