#include "Flight.h"

Flight::Flight()
{
}

void Flight::input()
{
	int choice;
	cout << "Hanh khach nay da ton tai chua\n 1.Da ton tai\n 2.Chua ton tai \n";
	cout << "Nhap lua chon: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		string _phoneNumber;
		int retype = 1;
		do
		{
			cout << "Vui long nhap SDT: ";
			cin.ignore();
			getline(cin, _phoneNumber);
			cout << "Dang lay du lieu khach hang. Xin vui long cho!\n";
			if (!passenger.readFromFile(_phoneNumber))
			{
				cout << passenger.id;
				cout << "Hanh khach khong ton tai trong he thong. Vui long nhap lai SDT hoac tao moi!\n";
				cout << "0. Tao hanh khach moi\n";
				cout << "1. Nhap lai SDT\n";
				cin >> retype;

				if (retype == 0)
				{
					passenger.input();
					break;
				}
			}
		} while (!passenger.readFromFile(_phoneNumber));
		cout << "Thong tin khach hang:\n";
		passenger.output();
		break;
	}
	case 2:
	{
		passenger.input();
		break;
	}
	}

	cout << "Hang chuyen bay (vietnam airlines, VietJet Air,...): ";
	getline(cin, airlinesLabel);
	//		cin.ignore();
	cout << "Tuyen bay: ";
	getline(cin, flightRoute);
	cout << "San bay xuat phat: ";
	getline(cin, startAirport);
	cout << "Ngay thang nam xuat phat: " << endl;
	cin >> startDate;
	cout << "San bay ha canh: ";
	cin.ignore();
	getline(cin, destinationAirport);
	cout << "Thoi gian bay tinh theo gio: ";
	cin >> flightLength;
	cout << "Ma ID chuyen bay: ";
	cin.ignore();
	//	cin>>flightID;
	getline(cin, flightID);
	//	cin.ignore();
	cout << "Tinh chat chuyen bay (noi dia, ngoai dia): ";
	getline(cin, flightNature);
	cout << "Cong vao: ";
	cin >> door;
	cout << "So ghe: ";
	cin.ignore();
	getline(cin, chair);
	cout << "Diem den (quoc gia nao do): ";
	getline(cin, destination);
	cout << "Thoi gian delay: ";
	cin >> timeDelay;
	cout << "Bat dau chuyen bay(tinh, thanh pho nao do): ";
	cin.ignore();
	getline(cin, from);
	cout << "Ket thuc chuyen bay(tinh, thanh pho nao do): ";
	getline(cin, to);
	cout << "Loai hanh ly (ky gui, xach tay): ";
	getline(cin, typeOfLuggage);
	cout << "Gia ban dau phai tra: ";
	cin >> initialPrice;
}

void Flight::output()
{
	passenger.output();
	cout << "========================" << endl;
	cout << "||Thong tin chuyen bay||" << endl;
	cout << "========================" << endl;
	cout << "Hang chuyen bay: " << airlinesLabel << endl;
	cout << "Tuyen bay: " << flightRoute << endl;
	cout << "San bay bat dau: " << startAirport << endl;
	cout << "Thoi gian bat dau: " << startDate << endl;
	cout << "San bay ha canh: " << destinationAirport << endl;
	cout << "Do dai thoi gian bay: " << flightLength << endl;
	cout << "ID chuyen bay: " << flightID << endl;
	cout << "Tinh chat(noi dia, ngoai dia): " << flightNature << endl;
	cout << "Cong vao: " << door << endl;
	cout << "Ghe: " << chair << endl;
	cout << "Diem den: " << destination << endl;
	cout << "Thoi gian delay: " << timeDelay << endl;
	cout << "Bat dau: " << from << endl;
	cout << "Ket thuc: " << to << endl;
	cout << "Loai hanh ly: " << typeOfLuggage << endl;
	cout << "Gia ban dau: " << (size_t)initialPrice << endl;
}

float Flight::TotalPrice()
{
	return 0;
}

void Flight::saveToFile(ofstream &fo)
{
	passenger.saveToFile(fo);
	startDate.saveToFile(fo);
	fo << airlinesLabel << "\n"
		 << flightRoute << "\n"
		 << startAirport << "\n"
		 << destinationAirport << "\n"
		 << flightID << "\n"
		 << flightNature << "\n"
		 << chair << "\n"
		 << destination << "\n"
		 << from << "\n"
		 << to << "\n"
		 << typeOfLuggage << "\n"
		 << door << " "
		 << flightLength << " " << timeDelay << " " << initialPrice << " ";
}

FlightType Flight::getType()
{
	return NIL;
}

void Flight::readFromFile(ifstream &fi)
{
	passenger.readFromFile(fi);
	startDate.readFromFile(fi);

	fi.ignore();
	getline(fi, airlinesLabel);
	getline(fi, flightRoute);
	getline(fi, startAirport);
	getline(fi, destinationAirport);
	getline(fi, flightID);
	getline(fi, flightNature);
	getline(fi, chair);
	getline(fi, destination);
	getline(fi, from);
	getline(fi, to);
	getline(fi, typeOfLuggage);
	fi >> door >> flightLength >> timeDelay >> initialPrice;
}
