#include "FirstClass.h"

//ifstream& operator>>(ifstream &is, PRIVATE_LINE &p)
//{
//	int val;
//	is >> val;
//	
//	switch(val)
//	{
//		case 0: p = NO_LINE; break;
//		case 300000: p = QUEUE_LINE; break;
//		case 2000000: p = NO_QUEUE_LINE; break;
//	}
//}
void FirstClass::input()
{
	Flight::input();
	cout << "---------PrivateLine----------"<<endl;
	cout << "|1.NO_LINE = 0                |"<<endl; 
	cout << "|2.QUEUE_LINE = 100000        |"<<endl;
	cout << "|3.NO_QUEUE_LINE = 200000     |"<<endl;
	cout << "------------------------------"<<endl;
	cout << "Vui long nhap cong vao: ";
	cin >> lineChoice;
	while (true)
	{
		if (lineChoice==1)
		{
			privateLine = NO_LINE; 
			break;
		}
		if (lineChoice==2)
		{
			privateLine = QUEUE_LINE;
			break;
		}
		if (lineChoice==3) 
		{
			privateLine = NO_QUEUE_LINE; 
			break;
		}
		cout<<"Vui long nhap lai: "<<endl;
	}
	cout<<"Phi vao cong la: "<<	privateLine<<endl;
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
	if (lineChoice==1) cout<<"Cong vao la: NO_LINE"<<endl; 
	if (lineChoice==2) cout<<"Cong vao la: QUEUE_LINE"<<endl; 
	if (lineChoice==3) cout<<"Cong vao la: NO_QUEUE_LINE"<<endl; 
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
	int pay2;
	if (lineChoice==1) pay2= 0;
	if (lineChoice==2) pay2= 100000;
	if (lineChoice==3) pay2= 200000;
	int sale;
	if (accumulation > 30)
		sale = InitialPrice * 0.3;
	else if (accumulation > 15)
		sale = InitialPrice * 0.15;
	else
		sale = 0;
	int pay;
	if (ageF > 62 && ageF < 10)
		pay = InitialPrice * 0.1;
	else
		pay = 0;
	int pay1;
	if (aggageWeightF > 20)
		pay1 = InitialPrice * 0.4;
	else
		pay1 = 0;
	return pay+pay1+pay2-sale;
}
float FirstClass::TotalPrice()
{
	return FirstClass::tax() + InitialPrice + servicePrice + priceOfDrink + eatPrice;
}
void FirstClass::saveToFile(ofstream &fo)
{
//	PRIVATE_LINE privateLine;
//	string drink, eat, service;
//	float priceOfDrink, eatPrice, servicePrice, aggageWeightF;
//	int roomEat, accumulation, ageF;
	Flight::saveToFile(fo);
	fo << privateLine << "\n"
	   << drink << "\n" << eat << "\n"
	   << priceOfDrink << " " << eatPrice << " "
	   << servicePrice << " " << aggageWeightF << " "
	   << roomEat << " " << accumulation << " "
	   << ageF << "\n";
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
