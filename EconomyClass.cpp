#include "EconomyClass.h"

void EconomyClass::input()
{
	Flight::input();

	cout << "====XIN MOI CHON MON DO AN NHANH==== " << endl;
	cout <<	"1.FRIES "<<endl;
	cout << "2.SANDWICH "<<endl;
	cout << "3.INSTANT_NOODLES "<<endl;
	cout << "4.TOKBOKKI "<<endl;
	cout << "5.PIZZA "<<endl; 
	cout << "6.HAMBURGER "<<endl; 
	cout << "7.KIMBAP "<<endl;
	cout << "8.SNACK "<<endl;
	cout << "9.KFC_FRIED_CHICKEN "<<endl;
	cout << "10.SALAD "<<endl;
	cout << "11.YOGURT "<<endl; 
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
	cout<< fastFood;
	cout << "Vocher: "<<endl;
	cout <<"-------------------"<<endl;
	cout <<"| 0-20  |  20-100 |"<<endl;
	cout <<"-------------------"<<endl;
	cin >> voucher;
	cout << "Nhap tuoi cua ban: ";
	cin >> ageECN;
	cout << "Aggage Weight ECN: "<<endl;
	cout <<"-------------------"<<endl;
	cout <<"| 0-10  |    >10  |"<<endl;
	cout <<"-------------------"<<endl;
	cin >> aggageWeightECN;
}
void EconomyClass::output()
{
	Flight::output();
	if (foodChoice==1) cout<<"Do uong ban chon la: FRIES"<<endl;
	if (foodChoice==2) cout<<"Do uong ban chon la: SANDWICH"<<endl;
	if (foodChoice==3) cout<<"Do uong ban chon la: INSTANT_NOODLES"<<endl;
	if (foodChoice==4) cout<<"Do uong ban chon la: TOKBOKKI"<<endl;
	if (foodChoice==5) cout<<"Do uong ban chon la: PIZZA"<<endl;
	if (foodChoice==6) cout<<"Do uong ban chon la: HAMBURGER"<<endl;
	if (foodChoice==7) cout<<"Do uong ban chon la: KIMBAP"<<endl;
	if (foodChoice==8) cout<<"Do uong ban chon la: SNACK"<<endl;
	if (foodChoice==9) cout<<"Do uong ban chon la: KFC_FRIED_CHICKEN"<<endl;
	if (foodChoice==10) cout<<"Do uong ban chon la: SALAD"<<endl;
	if (foodChoice==11) cout<<"Do uong ban chon la: YOGURT"<<endl;
	cout << "Price_Fastfood: " << fastFood << endl;
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

