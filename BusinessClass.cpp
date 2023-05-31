#include "BusinessClass.h"

void BusinessClass::input()
{
    int cardChoice, roomChoice;
    Flight::input();
    cout << "Chon phong cho" << endl;
    cout << "1. Phong don" << endl;
    cout << "2. Phong doi" << endl;
    cout << "3. Phong 3" << endl;
    cout << "4. Phong 4" << endl;
    cout << "5. Phong 5" << endl;
    while (true)
    {
        cout << "Hay nhap lua chon cua ban (THEO SO): ";
        cin >> roomChoice;
        if (roomChoice == 1)
        {
            waitRoom = ROOM_OF_ONE;
            break;
        }
        if (roomChoice == 2)
        {
            waitRoom = ROOM_OF_TWO;
            break;
        }
        if (roomChoice == 3)
        {
            waitRoom = ROOM_OF_THREE;
            break;
        }
        if (roomChoice == 4)
        {
            waitRoom = ROOM_OF_FOUR;
            break;
        }
        if (roomChoice == 5)
        {
            waitRoom = ROOM_OF_FIVE;
            break;
        }
        cout << "Khong co phong nay xin vui long nhap lai: " << endl;
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
    cout << "Nhap card" << endl;
    cout << "1. NONE     -0%" << endl;
    cout << "2. GOLD     -10%" << endl;
    cout << "3. DIAMOND  -15%" << endl;
    cout << "4. PLATINUM -20%" << endl;
    while (true)
    {
        cout << "Hay nhap lua chon cua ban: ";
        cin >> cardChoice;
        if (cardChoice == 1)
        {
            card = NONE;
            break;
        }
        if (cardChoice == 2)
        {
            card = GOLD;
            break;
        }
        if (cardChoice == 3)
        {
            card = DIAMOND;
            break;
        }
        if (cardChoice == 4)
        {
            card = PLATINUM;
            break;
        }
        cout << "Vui long nhap lai: " << endl;
    }
    // cout << "Cac ban chon co so phan tram giam la: " << card << endl;
    cout << "Age BSN: ";
    cin >> ageBSN;
    cout << "Aggage Weight BSN: ";
    cin >> aggageWeightBSN;
}

void BusinessClass::output()
{
    Flight::output();
    // cout << "WaitRoom: ";
    // if (roomChoice == 1)
    // 	cout << "Phong cho: Phong don" << endl;
    // if (roomChoice == 2)
    // 	cout << "Phong cho: Phong doi" << endl;
    // if (roomChoice == 3)
    // 	cout << "Phong cho: Phong 3" << endl;
    // if (roomChoice == 4)
    // 	cout << "Phong cho: Phong 4" << endl;
    // if (roomChoice == 5)
    // 	cout << "Phong cho: Phong 5" << endl;

    cout << "Phong cho: ";
    switch (waitRoom)
    {
    case ROOM_OF_ONE:
        cout << "Phong don\n";
        break;
    case ROOM_OF_TWO:
        cout << "Phong doi\n";
        break;
    case ROOM_OF_THREE:
        cout << "Phong 3\n";
        break;
    case ROOM_OF_FOUR:
        cout << "Phong 4\n";
        break;
    case ROOM_OF_FIVE:
        cout << "Phong 5\n";
        break;
    default:
        cout << "Khong xac dinh\n";
        break;
    }

    // cin.ignore(); // ??
    cout << "Waiting Food: " << waitingFood << endl;
    cout << "Soft Drinks: " << softDrinks << endl;
    cout << "SoftDrinksPrice: " << softDrinksPrice << endl;
    cout << "Meal: " << meal << endl;
    cout << "MealPrice: " << mealPrice << endl;
    cout << "Card: ";
    switch (card)
    {
    case NONE:
        cout << "Khong co Card\n";
        break;
    case GOLD:
        cout << "Gold\n";
        break;
    case DIAMOND:
        cout << "Diamond\n";
        break;
    case PLATINUM:
        cout << "Platinum\n";
        break;
    default:
        cout << "Khong xac dinh\n";
        break;
    }
    // if (cardChoice == 1)
    // 	cout << "Ban dang su dung CARD NODE " << endl;
    // if (cardChoice == 2)
    // 	cout << "Ban dang su dung CARD GOLD " << endl;
    // if (cardChoice == 3)
    // 	cout << "Ban dang su dung CARD DIAMOND " << endl;
    // if (cardChoice == 4)
    // 	cout << "Ban dang su dung CARD PLATINUM " << endl;
    // them chuc nang
    cout << "Age BSN: " << ageBSN << endl;
    cout << "Aggage Weight BSN: " << aggageWeightBSN << endl;
}
float BusinessClass::tax()
{
    return 0.15;
}
float BusinessClass::TotalPrice()
{
    return this->tax() * (initialPrice + mealPrice + softDrinksPrice);
}
void BusinessClass::saveToFile(ofstream &fo)
{
    fo << getType() << " ";
    Flight::saveToFile(fo);
    fo << waitRoom << " " << card << "\n"
       << waitingFood << "\n"
       << softDrinks << "\n"
       << meal << "\n"
       << ageBSN << " " << softDrinksPrice
       << " " << mealPrice << " " << aggageWeightBSN << "\n";
}
FlightType BusinessClass::getType()
{
    return BUSINESS;
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

