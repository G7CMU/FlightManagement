#include "FlightList.h"

FlightList::FlightList() {}
void FlightList::input()
{
	while (true)
	{
		Flight *ds;
		int chon, choice;
		cout << "====TICKET_TYPE===="<<endl;
		cout << "|1. EconomyClass  |"<<endl;
		cout << "|2. BusinessClass |"<<endl;
		cout << "|3. FirstClass    |"<<endl;
		cout << "|4. Exit          |" << endl;
		cout << "-------------------"<<endl;
		cout << "Nhap lua chon: ";
		cin >> chon;
		if (chon < 1 || chon > 3)
			break;
		if (chon == 1)
			ds = new EconomyClass;
		if (chon == 2)
			ds = new BusinessClass;
		if (chon == 3)
			ds = new FirstClass;
		ds->input();
		list.push_back(ds);
		cout << "Nhan 1 de tiep tuc;\n";
		cin >> choice;
		if (choice != 1)
			break;
	}
}

void FlightList::output()
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "---------------------------------" << endl;
		list[i]->output();
		cout << "---------------------------------" << endl;
		cout << "Tax: " << (size_t)list[i]->tax() << endl;
		cout << "Price: " << (size_t)list[i]->TotalPrice() << endl;
		cout << "---------------------------------" << endl;
		;
	}
}

void FlightList::TotalPrice()
{
	float sum;
	for (int i = 0; i < list.size(); i++)
	{
		sum = sum + list[i]->TotalPrice();
	}
	cout << "Tong la: " << (size_t)sum << endl;
}

void FlightList::sortDateStart()
{
	int k = list.size();
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (list[i]->startDate.year > list[j]->startDate.year)
			{
				swap(list[i], list[j]);
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (list[i]->startDate.year == list[i + 1]->startDate.year)
			{
				if (list[i]->startDate.month > list[i + 1]->startDate.month)
					swap(list[i], list[j]);
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if ((list[i]->startDate.year == list[i + 1]->startDate.year) && (list[i]->startDate.year == list[i + 1]->startDate.year))
			{
				if (list[i]->startDate.day > list[i + 1]->startDate.day)
					swap(list[i], list[j]);
			}
		}
	}
}

void FlightList::sortDateStart1()
{
	int a[100];
	int b;
	int k = list.size();
	for (int i = 0; i < k; i++)
	{
		int b = (list[i]->startDate.year * 100 + list[i]->startDate.month) * 100 + list[i]->startDate.day;
		a[i] = b;
//		cout<<a[i]<<" ";
	}
//	for (int i = 0; i < k - 1; i++)
//	{
//		for (int j = i + 1; j < k; j++)
//		{
//			if (a[i] > a[j])
//			{
//				swap(list[i], list[j]);
//			}
//		}
//	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				swap(list[i], list[j]);
			}
		}
	}
}
void FlightList::sortDateStart2()
{
	int a[100];
	int b;
	int k = list.size();
	for (int i = 0; i < k; i++)
	{
		int b = (list[i]->startDate.year * 100 + list[i]->startDate.month) * 100 + list[i]->startDate.day;
		a[i] = b;
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
				swap(list[i], list[j]);
			}
		}
	}
}

void FlightList::sortByBirth1()
{
	int a[100];
	int b;
	Flight *c[100];
	int k = list.size();

	for (int i = 0; i < k; i++)
	{
		int b = (list[i]->passenger.dateOfBirth.year * 100 + list[i]->passenger.dateOfBirth.month) * 100 + list[i]->passenger.dateOfBirth.day;
		a[i] = b;
	}

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
				swap(list[i], list[j]);
			}
		}
	}
}
void FlightList::sortBybirth()
{
	int a[100];
	int b;
	Flight *c[100];
	int k = list.size();

	for (int i = 0; i < k; i++)
	{
		int b = (list[i]->passenger.dateOfBirth.year * 100 + list[i]->passenger.dateOfBirth.month) * 100 + list[i]->passenger.dateOfBirth.day;
		a[i] = b;
	}

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				swap(list[i], list[j]);
			}
		}
	}
}
void FlightList::sortByDateOfBirth()
{
	for (int i = 0; i < list.size() - 1; i++)
		for (int j = i + 1; i < list.size(); j++)
			if (list[i]->passenger.dateOfBirth > list[j]->passenger.dateOfBirth)
				swap(list[i], list[j]);
}

void FlightList::sortByStartDate()
{
	for (int i = 0; i < list.size() - 1; i++)
		for (int j = i + 1; i < list.size(); j++)
			if (list[i]->startDate > list[j]->startDate)
				swap(list[i], list[j]);
}

void FlightList::sortByPriceAsc()
{
	int k = list.size();

	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->TotalPrice() > list[j]->TotalPrice())
				swap(list[i], list[j]);
}
void FlightList::sortByLengthAsc()
{
	int k = list.size();

	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->flightLength > list[j]->flightLength)
				swap(list[i], list[j]);
}
void FlightList::sortByLengthDesc()
{
	int k = list.size();

	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->flightLength < list[j]->flightLength)
				swap(list[i], list[j]);
}
void FlightList::sortByTaxAsc()
{
	int k = list.size();

	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->tax() > list[j]->tax())
				swap(list[i], list[j]);
}
void FlightList::sortByTaxDesc()
{
	int k = list.size();

	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->tax() < list[j]->tax())
				swap(list[i], list[j]);
}
void FlightList::sortByPriceDesc()
{
	int k = list.size();

	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->TotalPrice() < list[j]->TotalPrice())
				swap(list[i], list[j]);
}

void FlightList::sortByidDesc()
{
	int k = list.size();

	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->passenger.id < list[j]->passenger.id)
				swap(list[i], list[j]);
}

void FlightList::sortByidAsc()
{
	int k = list.size();
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (list[i]->passenger.id > list[j]->passenger.id)
				swap(list[i], list[j]);
}

void FlightList::findAll()
{
	int choice;
	int nb = 0;
	int id;
	Flight *b[10];
	int k = list.size();
	for (int i = 0; i < k; i++)
	{
		b[nb] = list[i];
		nb++;
	}
	while (true)
	{
		cout << "-------LOC--------" <<endl;
		cout << "|1.ID            |" << endl;
		cout << "|2.Gioi tinh     |" << endl;
		cout << "|3.Ma chuyen bay |" << endl;
		cout << "|4.Cong vao      |" << endl;
		cout << "|5.Exit          |" << endl;
		cout << "------------------" <<endl;
		cout << "Hay nhap lua chon cua ban: ";
		cin >> choice;
		if (choice == 1)
		{
			string a;
			cout << "Hay nhap id ban muon nhap: ";
			cin >> a;
			for (int i = 0; i < nb; i++)
			{
				if (b[i]->passenger.id != a)
				{
					for (int j = i; j < nb; j++)
					{
						b[j] = b[j + 1];
					}
					nb--;
					i--;
				}
			}
			//			cout << "Sau khi loc la: " << endl;
			cout << "===========LOC_ID===========" << endl;
			for (int i = 0; i < nb; i++)
			{
				cout << "--------------------------" << endl;
				b[i]->output();
				cout << "--------------------------" << endl;
			}
			cout << "============================" << endl;
		}
		else if (choice == 2)
		{
			string a;
			cout << "Hay nhap gioi tinh ban muon nhap (nam/nu): ";
			cin >> a;
			for (int i = 0; i < nb; i++)
			{
				if (b[i]->passenger.sex != a)
				{
					for (int j = i; j < nb; j++)
					{
						b[j] = b[j + 1];
					}
					nb--;
					i--;
				}
			}
			//			cout << "Sau khi loc la: " << endl;
			cout << "=========LOC_GIOITINH============" << endl;
			for (int i = 0; i < nb; i++)
			{
				cout << "---------------------------------" << endl;
				b[i]->output();
				cout << "---------------------------------" << endl;
			}
			cout << "============================" << endl;
		}
		else if (choice == 3)
		{
			string a;
			cout << "Hay nhap ma chuyen bay ban muon nhap: ";
			cin >> a;
			for (int i = 0; i < nb; i++)
			{
				if (b[i]->flightID != a)
				{
					for (int j = i; j < nb; j++)
					{
						b[j] = b[j + 1];
					}
					nb--;
					i--;
				}
			}
			//			cout << "Sau khi loc theo ma chuyen bay la : " << endl;
			cout << "=============LOC_MACHUYENBAY==========" << endl;
			for (int i = 0; i < nb; i++)
			{
				cout << "--------------------------------------" << endl;
				b[i]->output();
				cout << "--------------------------------------" << endl;
			}
			cout << "=======================================" << endl;
		}
		else if (choice == 4)
		{
			int a;
			cout << "Hay nhap cong vao ban muon nhap: ";
			cin >> a;
			for (int i = 0; i < nb; i++)
			{
				if (b[i]->door != a)
				{
					for (int j = i; j < nb; j++)
					{
						b[j] = b[j + 1];
					}
					nb--;
				}
				nb--;
			}
			//			cout << "Sau khi loc cong vao cua chuyen bay la : " << endl;
			cout << "=============LOC_CONG===========" << endl;
			for (int i = 0; i < nb; i++)
			{
				cout << "----------------------------------" << endl;
				b[i]->output();
				cout << "----------------------------------" << endl;
			}
			cout << "=================================" << endl;
		}
		else
			break;
	}
}

void FlightList::maxPrice()
{
	int maxIndex = 0;
	for (int i = 1; i < list.size(); i++)
		if (list[i]->TotalPrice() > list[maxIndex]->TotalPrice())
			maxIndex = i;

	list[maxIndex]->output();
}
void FlightList::minPrice()
{
	int minIndex = 0;
	for (int i = 0; i < list.size(); i++)
		if (list[i]->TotalPrice() < list[minIndex]->TotalPrice())
			minIndex = i;

	list[minIndex]->output();
}
void FlightList::editPassengerByPhoneNumber()
{
	string _phoneNumber;
	Passenger toEdit;
 cin.ignore();
	cout << "Nhap SDT khach hang muon sua thong tin: ";
	
	getline(cin, _phoneNumber);

	if (toEdit.readFromFile(_phoneNumber))
	{
		cout << "Thong tin khach hang:\n";
		toEdit.output();
		string _id, _name, _sex, _passengerID;

		cout << "Nhap cac thong tin khach hang!\n";
		cout << "Nhap [x] de bo qua!\n";

		cout << "ID: ";
		getline(cin, _id);
		toEdit.id = _id != "x" ? _id : toEdit.id;

		cout << "Name: ";
		getline(cin, _name);
		toEdit.name = _name != "x" ? _name : toEdit.name;

		cout << "Passenger ID: ";
		getline(cin, _passengerID);
		toEdit.passengerID = _passengerID != "x" ? _passengerID : toEdit.passengerID;
		
		cout << "Gioi tinh: ";
		getline(cin, _sex);
		toEdit.sex = _sex != "x" ? _sex : toEdit.sex;

		cout << "Thong tin sau khi thay doi la: \n";
		toEdit.output();
		toEdit.saveToFile();
		
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i]->passenger.phoneNumber == _phoneNumber)
				list[i]->passenger.readFromFile(_phoneNumber);
		}
	}
	else
	{
		cout << "Khach hang khong ton tai\n";
	}
}

void FlightList::editFlight()
{
	string _flightID;
	string newId;
	int k = list.size(), change = 0;
	cout << "Hay nhap chuyen bay ban muon thay doi ten: ";
	cin >> _flightID;
	cout << "ID chuyen bay thay doi: ";
	cin >> newId;
	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == _flightID)
		{
			list[i]->flightID = newId;
			change++;
		}
	}

	cout << "Da thay doi " << change << " chuyen bay co ma: "
		 << _flightID << "\nThanh: " << newId << endl;
}

void FlightList::editTime()
{
	string _flightID;
	float newTime;
	int k = list.size(), change = 0;

	cout << "Hay nhap id chuyen bay ban muon thay doi thoi gian bay: " << endl;
	cin >> _flightID;
	cout << "Thoi gian bay moi: ";
	cin >> newTime;

	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == _flightID)
		{
			list[i]->flightLength = newTime;
			change++;
		}
	}

	cout << "Da thay doi " << change << " chuyen bay co ma: "
		 << _flightID << "\nThanh: " << newTime << endl;
}

void FlightList::editDestination()
{
	string _flightID;
	string newDestination;
	int k = list.size(), change = 0;

	cout << "Hay nhap id chuyen bay ban muon thay doi diem den: ";
	cin >> _flightID;
	cin.ignore();
	cout << "Diem den moi: ";
	getline(cin, newDestination);

	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == _flightID)
		{
			list[i]->destination = newDestination;
		}
	}
}
void FlightList::editflightRoute()
{
	string _flightID;
	string a;
	int k = list.size(), change = 0;

	cout << "Hay nhap id chuyen bay ban muon thay doi tuyen duong: ";
	cin >> _flightID;
	cin.ignore();
	cout << "Tuyen duong moi la: ";
	getline(cin, a);

	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == _flightID)
		{
			list[i]->flightRoute = a;
		}
	}
}
void FlightList::editairlinesLabel()
{
	string _flightID;
	string a;
	int k = list.size(), change = 0;

	cout << "Hay nhap id chuyen bay ban muon thay doi hang may bay: ";
	cin >> _flightID;
	cin.ignore();
	cout << "Hang may bay moi la: ";
	getline(cin, a);

	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == _flightID)
		{
			list[i]->airlinesLabel = a;
		}
	}
}
void FlightList::editDoor()
{
	string b;
	int a;
	int k = list.size(), change = 0;

	cout << "Hay nhap sdt hanh khach ban muon thay doi cong vao may bay: ";
	cin >> b;
	cin.ignore();
	cout << "cong vao may bay moi la: ";
	cin>>a;

	for (int i = 0; i < k; i++)
	{
		if (list[i]->passenger.phoneNumber == b)
		{
			list[i]->door = a;
		}
	}
}
void FlightList::editChair()
{
	string b;
	string a;
	int k = list.size(), change = 0;

	cout << "Hay nhap sdt hanh khach ban muon thay doi ghe ngoi: ";
	cin >> b;
	cin.ignore();
	cout << "Ghe ngoi moi la: ";
	getline(cin, a);

	for (int i = 0; i < k; i++)
	{
		if (list[i]->passenger.phoneNumber == b)
		{
			list[i]->chair = a;
		}
	}
}
void FlightList::edittypeOfLuggage()
{
	string b;
	string a;
	int k = list.size(), change = 0;

	cout << "Hay nhap sdt cua hanh khach ban muon thay doi hanh ly: ";
	cin >> b;
	cin.ignore();
	cout << "loai hanh ly moi la: ";
	getline(cin, a);

	for (int i = 0; i < k; i++)
	{
		if (list[i]->passenger.phoneNumber == b)
		{
			list[i]->typeOfLuggage = a;
		}
	}
}
void FlightList::removepassengerID()
{
	string a;

	cout << "Ban hay nhap so dien thoai hanh khach can xoa: ";
	cin >> a;

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->passenger.phoneNumber == a)
		{
			list.erase(list.begin() + i);
			i--;
		}
	}
}
void FlightList::removeFlightById()
{
	string _flightID;

	cout << "Ban hay nhap id can xoa: ";
	cin >> _flightID;

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->flightID == _flightID)
		{
			list.erase(list.begin() + i);
			i--;
		}
	}
}

void FlightList::removeFlightByDoor()
{
	int _door;
	cout << "Ban hay nhap cong vao: ";
	cin >> _door;

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->door == _door)
		{
			list.erase(list.begin() + i);
			i--;
		}
	}
}

void FlightList::removeFlightByDestination()
{
	string _destination;
	int k = list.size();
	cin.ignore();
	cout << "Ban hay nhap diem den: ";
	getline(cin, _destination);

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->destination == _destination)
		{
			list.erase(list.begin() + i);
			i--;
		}
	}
}

void FlightList::appendFlight()
{
	Flight *toAppend;
	int choice, appendPos;
	int k = list.size();

	cout << "Hay nhap vi tri ban muon chen: ";
	cin >> appendPos;
	cout << "Hay nhap thong tin: " << endl;

	cout << "1. EconomyClass\n2. BusinessClass\n3. FirstClass" << endl;
	cout << "Nhap lua chon: ";
	cin >> choice;

	if (choice == 1)
		toAppend = new EconomyClass;
	if (choice == 2)
		toAppend = new BusinessClass;
	if (choice == 3)
		toAppend = new FirstClass;
	toAppend->input();

	list.insert(list.begin() + appendPos, toAppend);
	cout << "Thong tin chuyen bay vua chen: \n\n";
	list[appendPos]->output();
}
void FlightList::printinvoice()
{
	int k = list.size();
	for (int i = 0; i < k; i++)
	{
		cout << "==================================================="<<endl;
		cout << "|Ngay " << list[i]->startDate.day << " Thang " << list[i]->startDate.month << " Nam " << list[i]->startDate.day << "  " << endl;
		cout << "|NAME: " << list[i]->passenger.name << "     |Hang may bay: " << list[i]->airlinesLabel << "                                        " << endl;
		cout << "|ID: " << list[i]->flightID << "  |Thoi gian bay: " << list[i]->flightLength << "                                  " << endl;
		cout << "|From: " << list[i]->from << " |To: " << list[i]->to << " " << endl;
		cout << "|Door: " << list[i]->door << "   |So ghe: " << list[i]->chair;
		cout << "|Price: " << list[i]->TotalPrice() << endl;
		cout << "===================================================="<<endl;
	}
}
