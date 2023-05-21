#include "EconomyClass.h"

void EconomyClass::input()
{
	Flight::input();
	int foodChoice;
	cout << "Fastfood: ";
	cout << "Xin moi chon mon :))))" << endl;
	cout << "1.FoodChoice!" << endl;
	cout << "Fastfood: ";
	cin >> foodChoice;
	switch (foodChoice)
	{
	case 1:
		fastFood = FRIES;
		break;
	}
	// them chuc nang
	//	getline(cin, fastFood);
	cout << "Fastfood price: ";
	cin >> fastfoodPrice;
	cout << "Vocher: ";
	cin >> voucher;
	cout << "Age ACN: ";
	cin >> ageECN;
	cout << "Aggage Weight ECN: ";
	cin >> aggageWeightECN;
}
void EconomyClass::output()
{
	Flight::output();
	cout << "Fastfood: " << fastFood << endl;
	cout << "Fastfood price: " << fastfoodPrice << endl;
	cout << "Voucher: " << voucher << endl;
	cout << "Age ECN: " << ageECN << endl;
	cout << "Aggage Weight ECN: " << aggageWeightECN << endl;
}
float EconomyClass::tax()
{
	int sale;
	if (voucher > 20)
		sale = InitialPrice * 0.2;
	else if (voucher > 10)
		sale = InitialPrice * 0.1;
	else
		sale = 0;
	int pay;
	if (ageECN > 60 && ageECN < 10)
		pay = InitialPrice * 0.1;
	else
		pay = 0;
	int pay1;
	if (aggageWeightECN > 10)
		pay1 = InitialPrice * 0.3;
	else
		pay1 = 0;
	return pay + pay1 - sale;
}
float EconomyClass::TotalPrice()
{
	return EconomyClass::tax() + InitialPrice + fastfoodPrice;
}
void EconomyClass::saveToFile(ofstream &fo)
{
	Flight::saveToFile(fo);
	fo << fastFood << " " << voucher << " " << ageECN << " " << aggageWeightECN << "\n";	
}
void EconomyClass::readFromFile(ifstream &fi)
{
	int _fastFood;
	Flight::readFromFile(fi);
	fi >> _fastFood >> voucher >> ageECN >> aggageWeightECN;
	fastFood = (FASTFOOD)_fastFood;
}

