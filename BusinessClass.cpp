#include "BusinessClass.h"

void BusinessClass::input()
{
    int cardChoice, roomChoice;
    Flight::input();
    cout << "Chon phong cho" << endl;
    cout << "-----------------"<<endl;
    cout << "|1. Phong don   |" << endl;
    cout << "|2. Phong doi   |" << endl;
    cout << "|3. Phong 3     |" << endl;
    cout << "|4. Phong 4     |" << endl;
    cout << "|5. Phong 5     |" << endl;
    cout << "-----------------" <<endl;
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
    cout << "Do an trong luc cho: ";
    getline(cin, waitingFood);
    cout << "Nuoc uong giai khat: ";
    getline(cin, softDrinks);
    cout << "Gia cua nuoc uong: ";
    cin >> softDrinksPrice;
    cin.ignore();
    cout << "Mon an ban goi: ";
    getline(cin, meal);
    cout << "Gia cua mon an: ";
    cin >> mealPrice;
    cout << "Nhap card" << endl;
    cout << "--------------------"<<endl;
    cout << "|1. NONE     -0%   |" << endl;
    cout << "|2. GOLD     -10%  |" << endl;
    cout << "|3. DIAMOND  -15%  |" << endl;
    cout << "|4. PLATINUM -20%  |" << endl;
    cout << "--------------------"<<endl;
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
    cout << "Nhap tuoi hanh khach tren hang thuong gia: ";
    cin >> ageBSN;
    cout << "Nhap so can nang hanh ly tren chuyen bay thuong gia: ";
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
    cout << "Thuc an trong phong cho: " << waitingFood << endl;
    cout << "Nuoc uong giai khat: " << softDrinks << endl;
    cout << "Gia cua nuoc uong: " << softDrinksPrice << endl;
    cout << "Mon an chinh: " << meal << endl;
    cout << "Gia cua mon an: " << mealPrice << endl;
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
    cout << "Tuoi hanh khach: " << ageBSN << endl;
    cout << "Can nang hanh ly: " << aggageWeightBSN << endl;
}
float BusinessClass::tax()
{
	float taxx, tax1, tax2;
	if (waitRoom == ROOM_OF_ONE)
		taxx = 0.95;
	else if (waitRoom == ROOM_OF_TWO)
		taxx = 0.9;
	else if (waitRoom == ROOM_OF_THREE)
		taxx = 0.85;
	else if (waitRoom == ROOM_OF_FOUR)
		taxx = 0.80;
	else if (waitRoom == ROOM_OF_FIVE)
		taxx = 1;
	if (ageBSN > 60 && ageBSN<18)
		tax1 = 0;
	else 
		tax1 = 0.9;
	if (aggageWeightBSN > 10)
		tax2 = 0.5;
    return taxx + tax1 + tax2;
}
float BusinessClass::TotalPrice()
{
	float pricee, priceee;
	if (card == NONE)
		pricee = initialPrice * 1;
	else if (card == GOLD)
		pricee = initialPrice * 0.9;
	else if (card = DIAMOND)
		pricee = initialPrice * 0.85;
	else if (card = PLATINUM)
		pricee = initialPrice * 0.88;
	priceee = pricee + mealPrice + softDrinksPrice;
    return this->tax() * (priceee);
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

