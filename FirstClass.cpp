#include "FirstClass.h"

void FirstClass::input()
{
	int lineChoice;
	Flight::input();
	cout << "Private Line: " << endl;
	cout << "1. NO LINE         0" << endl;
	cout << "2. QUEUE LINE      100000" << endl;
	cout << "3. NO QUEUE LINE   200000" << endl;
	cout << "Nhap lua chon: ";
	cin >> lineChoice;
	while (true)
	{
		if (lineChoice == 1)
		{
			privateLine = NO_LINE;
			break;
		}
		if (lineChoice == 2)
		{
			privateLine = QUEUE_LINE;
			break;
		}
		if (lineChoice == 3)
		{
			privateLine = NO_QUEUE_LINE;
			break;
		}
		cout << "Vui long nhap lai: " << endl;
	}
	cout << "Phi vao cong la: " << privateLine << endl;
	cin.ignore();
	cout << "Drink: ";
	getline(cin, drink);
	cout << "PriceOfDrink: ";
	cin >> priceOfDrink;
	cin.ignore();
	cout << "Eat: ";
	getline(cin, eat);
	cout << "RoomEat: ";
	cin >> roomEat;
	cout << "EatPrice: ";
	cin >> eatPrice;
	cin.ignore();
	cout << "Service: ";
	getline(cin, service);
	cout << "ServicePrice: ";
	cin >> servicePrice;
	cout << "Accumulation: ";
	cin >> accumulation;
	cout << "Age F: ";
	cin >> ageF;
	cout << "Aggage Weight F: ";
	cin >> aggageWeightF;
}
void FirstClass::output()
{
	Flight::output();
	cout << "PrivateLine: ";
	switch (privateLine)
	{
	case NO_LINE:
		cout << "NO LINE\n";
		break;
	case QUEUE_LINE:
		cout << "QUEUE LINE\n";
		break;
	case NO_QUEUE_LINE:
		cout << "NO QUEUE LINE\n";
		break;
	}
	cout << "Drink: " << drink << endl;
	cout << "PriceOfDrink: " << priceOfDrink << endl;
	cout << "Eat: " << eat << endl;
	cout << "RoomEat: " << roomEat << endl;
	cout << "EatPrice: " << eatPrice << endl;
	cout << "Service: " << service << endl;
	cout << "ServicePrice: " << servicePrice << endl;
	cout << "Accumulation: " << accumulation << endl;
	cout << "Age F: " << ageF << endl;
	cout << "Aggage Weight F: " << aggageWeightF << endl;
}
float FirstClass::tax()
{
	float tax, taxx;
	if (ageF > 60 && ageF < 20)
	{
		tax = 1;	
	}	
	else 
		tax = 1.1;
	if (aggageWeightF > 20)
		taxx = 0.3;
	else 
		tax = 0;
	return tax + taxx;
}
float FirstClass::TotalPrice()
{
	float sale;
	if (accumulation > 50)
	{
		sale = 0.5 * initialPrice;
	}
	else if (accumulation > 30)
	{
		sale = 0.3 * initialPrice;
	}
	else if (accumulation > 20)
	{
		sale = 0.2 * initialPrice;
	}
	else if (accumulation > 10)
	{
		sale = 0.1 * initialPrice;
	}
	else sale = 0;
	float pricee;
	if (privateLine = NO_LINE)
	{
		pricee = 0;
	}
	else if	(privateLine = QUEUE_LINE)
	{
		pricee = 100000;
	}
	else if (privateLine = NO_QUEUE_LINE)
	{
		pricee = 200000;
	}	
	return this->tax() * (initialPrice + servicePrice + priceOfDrink + eatPrice + pricee - sale);
}
void FirstClass::saveToFile(ofstream &fo)
{
	fo << getType() << " ";
	Flight::saveToFile(fo);
	fo << privateLine << " "
		 << drink << "\n"
		 << eat << "\n"
		 << priceOfDrink << " " << eatPrice << " "
		 << servicePrice << " " << aggageWeightF << " "
		 << roomEat << " " << accumulation << " "
		 << ageF << "\n";
}
FlightType FirstClass::getType()
{
	return FIRST;
}
void FirstClass::readFromFile(ifstream &fi)
{
	int _privateLine;
	Flight::readFromFile(fi);
	fi >> _privateLine;
	fi.ignore();
	getline(fi, drink);
	getline(fi, eat);
	fi >> priceOfDrink >> eatPrice >> servicePrice
	   >> aggageWeightF >> roomEat >> accumulation
	   >> ageF;
	   
	privateLine = (PRIVATE_LINE)_privateLine;
}
