#include "BusinessClass.h"


void BusinessClass::input()
{
	
	Flight::input();
	cout << "----------WaitRoom-------------------"<<endl;
	cout << "1.ROOM_OF_ONE!!!" << endl;
    cout << "2.ROOM_OF_TWO!!!" << endl;
    cout << "3.ROOM_OF_THREE!!!" << endl;
    cout << "4.ROOM_OF_FOUR!!!" << endl;
	cout << "5.ROOM_OF_FIVE!!!" << endl;
	cout << "--------------------------------------"<<endl;
	
	while (true)
	{
		cout << "Hay nhap lua chon cua ban (THEO SO): ";
		cin >> roomChoice;
		if (roomChoice == 1) 
		{
			waitRoom = ROOM_OF_ONE ;
			break;
		}
		if (roomChoice == 2) 
		{
			waitRoom = ROOM_OF_TWO ;
			break;
		} 
		if (roomChoice == 3) 
		{
			waitRoom = ROOM_OF_THREE ;
			break;
		}
		if (roomChoice == 4) 
		{
			waitRoom = ROOM_OF_FOUR ;
			break;
		}
		if (roomChoice == 5)
		{
			waitRoom = ROOM_OF_FIVE ;
			break;
		}
		cout<<"Khong co phong nay xin vui long nhap lai: "<<endl;
	}
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
	cout << "--------CARD--------"<<endl;
	cout << "|1.NONE = 0         |"<<endl;
	cout << "|2.GOLD = 10 		 |"<<endl;
	cout << "|3.DIAMOND = 15     |"<<endl;
	cout << "|4.PLATINUM = 20    |"<<endl;
	cout << "--------------------"<<endl;
	cout << "Hay nhap lua chon cua ban: ";
	cin >> cardChoice;	
	while (cardChoice)
	{
		if (cardChoice==1) 
		{
			card = NONE;
			break;
		}
		if (cardChoice==2) 
		{
			card = GOLD;
			break;
		}
		if (cardChoice==3) 
		{
			card = DIAMOND;
			break;
		}
		if (cardChoice==4) 
		{
			card = PLATINUM;
			break;
		}
		cout<<"Vui long nhap lai: "<<endl;
	}
	cout<<"Cac ban chon co so phan tram giam la: "<<card<<endl;
	cout << "Age BSN: ";
	cin >> ageBSN;
	cout << "Aggage Weight BSN: ";
	cin >> aggageWeightBSN;
}
void BusinessClass::output()
{
	Flight::output();
	cout << "WaitRoom: ";
	if (roomChoice==1) cout<<"Phong cho: ROOM_OF_ONE"<<endl;
	if (roomChoice==2) cout<<"Phong cho: ROOM_OF_TWO"<<endl;
	if (roomChoice==3) cout<<"Phong cho: ROOM_OF_THREE"<<endl;
	if (roomChoice==4) cout<<"Phong cho: ROOM_OF_FOUR"<<endl;
	if (roomChoice==5) cout<<"Phong cho: ROOM_OF_FIVE"<<endl;	
	cin.ignore();
	cout << "Waiting Food: " << waitingFood << endl;
	cout << "Soft Drinks: " << softDrinks << endl;
	cout << "SoftDrinksPrice: " << softDrinksPrice << endl;
	cout << "Meal: " << meal << endl;
	cout << "MealPrice: " << mealPrice << endl;
	cout << "Card: ";
	if (cardChoice==1) cout<<"Ban dang su dung CARD NODE "<<endl;
	if (cardChoice==2) cout<<"Ban dang su dung CARD GOLD "<<endl;
	if (cardChoice==3) cout<<"Ban dang su dung CARD DIAMOND "<<endl;
	if (cardChoice==4) cout<<"Ban dang su dung CARD PLATINUM "<<endl;
	// them chuc nang
	cout << "Age BSN: " << ageBSN << endl;
	cout << "Aggage Weight BSN: " << aggageWeightBSN << endl;
}
float BusinessClass::tax()
{
	int sale;
	if (cardChoice == 1)
		sale = 0;
	else if (cardChoice == 2)
		sale = InitialPrice * 0.1;
	else if (cardChoice == 3)
		sale = InitialPrice * 0.15;
	else if (cardChoice == 4)
		sale = InitialPrice * 0.20;	
	int sale1;
	if (ageBSN > 61 && ageBSN < 11)
		sale1 = InitialPrice * 0.1;
	else
		sale1 = 0;
	int pay1;
	if (aggageWeightBSN > 15)
		pay1 = InitialPrice * 0.3;
	else
		pay1 = 0;
	return pay1 - sale - sale1;
}
float BusinessClass::TotalPrice()
{
	return BusinessClass::tax() + InitialPrice + mealPrice + softDrinksPrice;
}
void BusinessClass::saveToFile(ofstream &fo)
{
	fo << getType() << " ";
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
FlightType BusinessClass::getType()
{
	return BUSINESS;
}
