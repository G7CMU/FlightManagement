#include "EconomyClass.h"

void EconomyClass::input()
{
	int foodChoice;
	Flight::input();

	cout << "Chon do an nhanh: " << endl;
	cout << "1.  FRIES " << endl;
	cout << "2.  SANDWICH " << endl;
	cout << "3.  INSTANT_NOODLES " << endl;
	cout << "4.  TOKBOKKI " << endl;
	cout << "5.  PIZZA " << endl;
	cout << "6.  HAMBURGER " << endl;
	cout << "7.  KIMBAP " << endl;
	cout << "8.  SNACK " << endl;
	cout << "9.  KFC_FRIED_CHICKEN " << endl;
	cout << "10. SALAD " << endl;
	cout << "11. YOGURT " << endl;
	cout << "Vui long chon mon(theo so): ";
	cin >> foodChoice;
	switch (foodChoice)
	{
	case 1:
		fastFood = FRIES;
		break;
	case 2:
		fastFood = SANDWICH;
		break;
	case 3:
		fastFood = INSTANT_NOODLES;
		break;
	case 4:
		fastFood = TOKBOKKI;
		break;
	case 5:
		fastFood = PIZZA;
		break;
	case 6:
		fastFood = HAMBURGER;
		break;
	case 7:
		fastFood = KIMBAP;
		break;
	case 8:
		fastFood = SNACK;
		break;
	case 9:
		fastFood = KFC_FRIED_CHICKEN;
		break;
	case 10:
		fastFood = SALAD;
		break;
	case 11:
		fastFood = YOGURT;
		break;
	}
	// them chuc nang
	//	getline(cin, fastFood);
	cout << "Fastfood price: ";
	cin >> fastfoodPrice;
	cout << "Vocher: " << endl;
	cin >> voucher;
	cout << "Nhap tuoi cua ban: ";
	cin >> ageECN;
	cout << "Aggage Weight ECN: " << endl;
	cin >> aggageWeightECN;
}
void EconomyClass::output()
{
	Flight::output();
	cout << "Do uong ban chon la: ";
	switch (fastFood)
	{
		case FRIES: cout << "FRIES\n"; break;
		case SANDWICH: cout << "SANDWICH\n"; break;
		case INSTANT_NOODLES: cout << "INSTANT NOODLES\n"; break;
		case TOKBOKKI: cout << "TOKBOKKI\n"; break;
		case PIZZA: cout << "PIZZA\n"; break;
		case HAMBURGER: cout << "HAMBURGER\n"; break;
		case KIMBAP: cout << "KIMBAP\n"; break;
		case SNACK: cout << "SNACK\n"; break;
		case KFC_FRIED_CHICKEN: cout << "KFC FRIED CHICKEN\n"; break;
		case SALAD: cout << "SALAD\n"; break;
		case YOGURT: cout << "YOGURT\n"; break;
	}
	cout << "Price_Fastfood: " << fastFood << endl;
	cout << "Voucher: " << voucher << endl;
	cout << "Age ECN: " << ageECN << endl;
	cout << "Aggage Weight ECN: " << aggageWeightECN << endl;
}
float EconomyClass::tax()
{
	return 0.1;
}
float EconomyClass::TotalPrice()
{
	return this->tax() * (initialPrice + fastfoodPrice);
}
void EconomyClass::saveToFile(ofstream &fo)
{
	fo << getType() << " ";
	Flight::saveToFile(fo);
	fo << fastFood << " " << voucher << " " << ageECN << " " << aggageWeightECN << "\n";
}
FlightType EconomyClass::getType()
{
	return ECONOMY;
}
void EconomyClass::readFromFile(ifstream &fi)
{
	int _fastFood;
	Flight::readFromFile(fi);
	fi >> _fastFood >> voucher >> ageECN >> aggageWeightECN;
	fastFood = (FASTFOOD)_fastFood;
}

