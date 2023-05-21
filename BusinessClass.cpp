#include "BusinessClass.h"

void BusinessClass::input()
{
	int choice;
	Flight::input();
	cout << "WaitRoom: ";
	cout << "1.ROOM_OF_FOUR!!!" << endl;
	cout << "Hay nhap lua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
		waitRoom = ROOM_OF_FOUR;
	// them chuc nang
	cin.ignore();
	cout << "Waiting Food: ";
	getline(cin, waitingFood);
	cout << "Soft Drinks: ";
	getline(cin, softDrinks);
	cout << "SoftDrinksPrice: ";
	cin >> softDrinksPrice;
	cin.ignore();
	cout << "Meal: ";
	getline(cin, meal);
	cout << "MealPrice: ";
	cin >> mealPrice;
	cout << "Card: ";
	card = NONE;
	// them chuc nang
	//	getline(cin, eat);
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
	if (waitRoom = ROOM_OF_FOUR)
		cout << "Wait Room: ROOM_OF_FOUR";
	// them tiep
	cin.ignore();
	cout << "Waiting Food: " << waitingFood << endl;
	cout << "Soft Drinks: " << softDrinks << endl;
	cout << "SoftDrinksPrice: " << softDrinksPrice << endl;
	cout << "Meal: " << meal << endl;
	cout << "MealPrice: " << mealPrice << endl;
	cout << "Card: ";
	if (card = NONE)
		cout << "Card: NODE";
	// them chuc nang
	cout << "Age BSN: " << ageBSN << endl;
	cout << "Aggage Weight BSN: " << aggageWeightBSN << endl;
}
float BusinessClass::tax()
{
	int sale;
	if (card > 15)
		sale = InitialPrice * 0.15;
	else if (card > 10)
		sale = InitialPrice * 0.1;
	else
		sale = 0;
	int pay;
	if (ageBSN > 61 && ageBSN < 11)
		pay = InitialPrice * 0.1;
	else
		pay = 0;
	int pay1;
	if (aggageWeightBSN > 15)
		pay1 = InitialPrice * 0.3;
	else
		pay1 = 0;
	return sale - pay - pay1;
}
float BusinessClass::TotalPrice()
{
	return BusinessClass::tax() + InitialPrice + mealPrice;
}
void BusinessClass::saveToFile(ofstream &fo)
{
	Flight::saveToFile(fo);
	fo << waitRoom << " " << card << "\n"
	   << waitingFood << "\n" << softDrinks << "\n" 
	   << meal << "\n" << ageBSN << " " << softDrinksPrice 
	   << " " << mealPrice << " " << aggageWeightBSN << "\n";
}
void BusinessClass::readFromFile(ifstream &fi)
{
	int _waitRoom, _card;
	Flight::readFromFile(fi);
	fi >> _waitRoom >> _card;
	fi.ignore();
	getline(fi, waitingFood);
	getline(fi, softDrinks);
	getline(fi, meal);
	fi >> ageBSN >> softDrinksPrice >> mealPrice >> aggageWeightBSN;
	
	waitRoom = (WAITING_ROOM)_waitRoom;
	card = (CARD)_card;
}
