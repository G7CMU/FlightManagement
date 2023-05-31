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

	cout << "AirlinesLabel: ";
	getline(cin, airlinesLabel);
	//		cin.ignore();
	cout << "FlightRoute: ";
	getline(cin, flightRoute);
	cout << "StartAirport: ";
	getline(cin, startAirport);
	cout << "StartDate: " << endl;
	cin >> startDate;
	cout << "destinationAirport: ";
	cin.ignore();
	getline(cin, destinationAirport);
	cout << "flightLength: ";
	cin >> flightLength;
	cout << "flightID: ";
	cin.ignore();
	//	cin>>flightID;
	getline(cin, flightID);
	//	cin.ignore();
	cout << "flightNature(noi dia, ngoai dia): ";
	getline(cin, flightNature);
	cout << "Door: ";
	cin >> door;
	cout << "Chair: ";
	cin.ignore();
	getline(cin, chair);
	cout << "Destination: ";
	getline(cin, destination);
	cout << "TimeDelay: ";
	cin >> timeDelay;
	cout << "From: ";
	cin.ignore();
	getline(cin, from);
	cout << "To: ";
	getline(cin, to);
	cout << "typeOfLuggage: ";
	getline(cin, typeOfLuggage);
	cout << "initialPrice: ";
	cin >> initialPrice;
}

void Flight::output()
{
	passenger.output();
	cout << "\n\nThong tin chuyen bay:\n\n";
	cout << "AirlinesLabel: " << airlinesLabel << endl;
	cout << "FlightRoute: " << flightRoute << endl;
	cout << "StartAirport: " << startAirport << endl;
	cout << "StartDate: " << startDate << endl;
	cout << "destinationAirport: " << destinationAirport << endl;
	cout << "flightLength: " << flightLength << endl;
	cout << "flightID: " << flightID << endl;
	cout << "flightNature(noi dia, ngoai dia): " << flightNature << endl;
	cout << "Door: " << door << endl;
	cout << "Chair: " << chair << endl;
	cout << "Destination: " << destination << endl;
	cout << "TimeDelay: " << timeDelay << endl;
	cout << "From: " << from << endl;
	cout << "To: " << to << endl;
	cout << "TypeOfLuggage: " << typeOfLuggage << endl;
	cout << "InitialPrice: " << initialPrice << endl;
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
