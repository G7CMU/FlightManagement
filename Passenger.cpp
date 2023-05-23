#include "Passenger.h"
Passenger::Passenger()
{
	this->id = "undefined";
}

void Passenger::input()
{
	string _id, _passengerID, _name, _phoneNumber;
	Date _dateOfBirth;
	int choice;
	
	cin.ignore();
	cout << "Nhap ID: ";
	getline(cin, _id);
	cout << "Nhap ID hanh khach: ";
	getline(cin, _passengerID);
	cout << "Nhap ten: ";
	getline(cin, _name);
	cout << "Nhap ngay, thang, nam sinh: \n";
	cin >> _dateOfBirth;
	cout << "Nhap SDT: ";
	cin.ignore();
	getline(cin, _phoneNumber);
	
	if (this->readFromFile(_phoneNumber))
	{
		cout << "Da ton tai khach hang voi SDT: " << phoneNumber << endl;
		this->output();
		cout << "Ban co muon ghi de thong tin khong\n\n";
		cout << "0. Khong\n";
		cout << "1. Co\n";
		cout << "Nhap lua chon: ";
		cin >> choice;
	}
	
	if (choice == 1)
	{
		this->id = _id;
		this->passengerID = _passengerID;
		this->name = _name;
		this->dateOfBirth = _dateOfBirth;
		this->phoneNumber = _phoneNumber;
	}
	
	this->saveToFile();
}

void Passenger::output()
{
	cout << "ID: " << id << endl;
	cout << "Passenger ID: " << passengerID << endl;
	cout << "Ten: " << name << endl;
	cout << "SDT: " << phoneNumber << endl;

	cout << "Ngay, thang, nam sinh: " << dateOfBirth << endl;
}

istream &operator>>(istream &is, Passenger &p)
{
	cout << "Nhap ID hanh khach: ";
	getline(cin, p.passengerID);
	cout << "Nhap ID: ";
	getline(cin, p.id);
	cout << "Nhap ten: ";
	getline(cin, p.name);
	cout << "Nhap ngay, thang, nam sinh: \n";
	cin >> p.dateOfBirth;
	cout << "Nhap SDT: ";
	cin.ignore();
	getline(cin, p.phoneNumber);
	return is;
}

ostream &operator<<(ostream &os, Passenger p)
{
	cout << "Passenger ID: " << p.passengerID << endl;
	cout << "ID: " << p.id << endl;
	cout << "Ten: " << p.name << endl;
	cout << "SDT: " << p.phoneNumber << endl;
	cout << "Ngay, thang, nam sinh: " << p.dateOfBirth << endl;
	return os;
}

void Passenger::saveToFile(ofstream &fo)
{
	dateOfBirth.saveToFile(fo);
	fo << id << "\n"
		 << name << "\n"
		 << phoneNumber << "\n"
		 << passengerID << "\n";
}

void Passenger::readFromFile(ifstream &fi)
{
	dateOfBirth.readFromFile(fi);
	fi.ignore();
	getline(fi, id);
	getline(fi, name);
	getline(fi, phoneNumber);
	getline(fi, passengerID);
}

void Passenger::saveToFile()
{
	string filePath = BASE_PASSENGER_PATH + phoneNumber + ".txt";
	ofstream fo(filePath.c_str());
	dateOfBirth.saveToFile(fo);
	fo << id << "\n"
		 << name << "\n"
		 << phoneNumber << "\n"
		 << passengerID << "\n";
	fo.close();
}

bool Passenger::readFromFile(string _phoneNumber)
{
	string filePath = "./passenger/" + _phoneNumber + ".txt";
	ifstream fi(filePath.c_str());
	dateOfBirth.readFromFile(fi);
	fi.ignore();
	getline(fi, id);
	getline(fi, name);
	getline(fi, phoneNumber);
	getline(fi, passengerID);

	fi.close();

	return this->id != "undefined";
}
/*int Passenger::getday()
{
	return dateOfBirth.day();
}
int Passenger::getmonth()
{
	return dateOfBirth.month();
}
int Passenger::getyear()
{
	return dateOfBirth.year();
}*/
