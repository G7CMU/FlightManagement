#include "FirstClass.h"

void FirstClass::input()
{
	Flight::input();
	cout<<"PrivateLine: ";
	privateLine == NO_LINE;
	//them chuc nang
	cin.ignore();
	cout<<"Drink: ";
	getline(cin, drink);
	cout<<"PriceOfDrink: "<<endl;
	cin>>priceOfDrink;
	cout<<"Eat: "<<endl;
	getline(cin, eat);
	cout<<"RoomEat: "<<endl;
	cin>>roomEat;
	cout<<"EatPrice: "<<endl;
	cin>>eatPrice;
	cout<<"Service: "<<endl;
	getline(cin, service);
	cout<<"ServicePrice: "<<endl;
	cin>>servicePrice;
	cout<<"Accumulation: "<<endl;
	cin>>accumulation;
	cout <<"Age F: "<<endl;
	cin >> ageF;
	cout <<"Aggage Weight F: "<<endl;
	cin >> aggageWeightF;
}
void FirstClass::output()
{
	Flight::output();
	cout<<"PrivateLine: ";
	if (privateLine == NO_LINE) cout<<"NO_LINE";
	// them chuc nang
	cout<<"Drink: "<<drink<<endl;
	cout<<"PriceOfDrink: "<<priceOfDrink<<endl;
	cout<<"Eat: "<<eat<<endl;
	cout<<"RoomEat: "<<roomEat<<endl;
	cout<<"EatPrice: "<<eatPrice<<endl;
	cout<<"Service: "<<service<<endl;
	cout<<"ServicePrice: "<<servicePrice<<endl;
	cout<<"Accumulation: "<<accumulation<<endl;
	cout<<"Age F: "<<ageF<<endl;
	cout<<"Aggage Weight F: "<<aggageWeightF<<endl;
}
float FirstClass::tax()
{
	int sale;
		if (accumulation > 30) sale = InitialPrice*0.3;
		else if (accumulation > 15) sale = InitialPrice*0.15;
		else sale=0;
	int pay;
		if (ageF > 62 && ageF < 10) pay = InitialPrice*0.1;
		else pay = 0;
	int pay1;
		if (aggageWeightF>20) pay1=InitialPrice*0.4;
		else pay1=0;
	return sale-pay-pay1;
}
FlightType FirstClass::classType()
{
	return FIRST;
}
float FirstClass::Totalprice()
{
	return  FirstClass::tax()+InitialPrice+servicePrice;
}
