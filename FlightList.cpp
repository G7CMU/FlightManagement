#include "FlightList.h"

FlightList::FlightList() {}
void FlightList::input()
{
	while (true)
	{
		Flight *ds;
		int chon, choice;
		cout << "1. EconomyClass\n2. BusinessClass\n3. FirstClass/4. Exit" << endl;
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
		// cout << "Tax: " << list[i]->tax() << endl;
		// cout << "Price: " << list[i]->TotalPrice() << endl;
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
	cout << "Tong la: " << sum << endl;
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
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
			if (a[i] > a[j])
			{
				swap(list[i], list[j]);
			}
	}
	for (int i = 0; i < k; i++)
	{
		list[i]->output();
	}
}

void FlightList::sortBybirth()
{
	int a[100];
	int b;
	int k = list.size();
	for (int i = 0; i < k; i++)
	{
		int b = list[i]->passenger.dateOfBirth.year * 100 + list[i]->passenger.dateOfBirth.month * 100 + list[i]->startDate.day;
		a[i] = b;
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
			if (a[i] > a[j])
			{
				swap(list[i], list[j]);
			}
	}
	for (int i = 0; i < k; i++)
	{
		list[i]->output();
	}
}

void FlightList::sortByPriceAsc()
{
	int k = list.size();
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (list[i]->TotalPrice() > list[j]->TotalPrice())
				swap(list[i], list[j]);
		}
	}
}

void FlightList::sortByPriceDesc()
{
	int k = list.size();
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (list[i]->TotalPrice() < list[j]->TotalPrice())
				swap(list[i], list[j]);
		}
	}
	cout << "=========SAPXEPGIAMDANTHEOGIA===========" << endl;
	for (int i = 0; i < k; i++)
	{
		list[i]->output();
	}
}

void FlightList::sortByidDesc()
{
	int k = list.size();
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; i++)
		{
			if (list[i]->passenger.id < list[j]->passenger.id)
				swap(list[i], list[j]);
		}
	}
}

void FlightList::sortByidAsc()
{
	int k = list.size();
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; i++)
		{
			if (list[i]->passenger.id < list[j]->passenger.id)
				swap(list[i], list[j]);
		}
	}
}

// void FlightList::findAll()
// {
// 	int choice;
// 	int nb = 0;
// 	int id;
// 	int k = list.size();
// 	for (int i = 0; i < k; i++)
// 	{
// 		b[nb] = list[i];
// 		nb++;
// 	}
// 	nb = nb;
// 	while (true)
// 	{
// 		cout << "1.ID" << endl;
// 		cout << "2.SDT" << endl;
// 		cout << "3.Ma chuyen bay" << endl;
// 		cout << "4.Cong vao" << endl;
// 		cout << "5.Exit" << endl;
// 		cout << "Hay nhap lua chon cua ban: ";
// 		cin >> choice;
// 		if (choice == 1)
// 		{
// 			string a;
// 			cout << "Hay nhap id ban muon nhap: ";
// 			cin >> a;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				if (b[i]->passenger.id != a)
// 				{
// 					for (int j = i; j < nb; j++)
// 					{
// 						b[j] = b[j + 1];
// 					}
// 					nb--;
// 					i--;
// 				}
// 			}
// 			cout << "Sau khi loc la: " << endl;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				b[i]->output();
// 			}
// 		}
// 		else if (choice == 2)
// 		{
// 			string a;
// 			cout << "Hay nhap sdt ban muon nhap: ";
// 			cin >> a;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				if (b[i]->passenger.phoneNumber != a)
// 				{
// 					for (int j = i; j < nb; j++)
// 					{
// 						b[j] = b[j + 1];
// 					}
// 					nb--;
// 					i--;
// 				}
// 			}
// 			cout << "Sau khi loc la: " << endl;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				b[i]->output();
// 			}
// 		}
// 		else if (choice == 3)
// 		{
// 			string a;
// 			cout << "Hay nhap ma chuyen bay ban muon nhap: ";
// 			cin >> a;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				if (b[i]->flightID != a)
// 				{
// 					for (int j = i; j < nb; j++)
// 					{
// 						b[j] = b[j + 1];
// 					}
// 					nb--;
// 					i--;
// 				}
// 			}
// 			cout << "Sau khi loc theo ma chuyen bay la : " << endl;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				b[i]->output();
// 			}
// 		}
// 		else if (choice == 4)
// 		{
// 			int a;
// 			cout << "Hay nhap cong vao ban muon nhap: ";
// 			cin >> a;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				if (b[i]->door != a)
// 				{
// 					for (int j = i; j < nb; j++)
// 					{
// 						b[j] = b[j + 1];
// 					}
// 					nb--;
// 				}
// 				nb--;
// 			}
// 			cout << "Sau khi loc cong vao cua chuyen bay la : " << endl;
// 			for (int i = 0; i < nb; i++)
// 			{
// 				b[i]->output();
// 			}
// 		}
// 		else
// 			break;
// 	}
// }

void FlightList::maxPrice()
{
	int maxIndex = 0;
	for (int i = 1; i < list.size(); i++)
		if (list[i]->TotalPrice() > list[maxIndex]->TotalPrice())
			maxIndex = i;
	cout << "Nguoi phai tra tien cao nhat la: " << endl;
	list[maxIndex]->output();
}
void FlightList::minPrice()
{
	int minIndex = 0;
	for (int i = 0; i < list.size(); i++)
		if (list[i]->TotalPrice() < list[minIndex]->TotalPrice())
			minIndex = i;
	cout << "Nguoi phai tra tien cao nhat la: " << endl;
	list[minIndex]->output();
}
void FlightList::editPassengerByPhoneNumber()
{
	string _phoneNumber;
	Passenger toEdit;

	cout << "Nhap SDT khach hang muon sua thoing tin: ";
	cin.ignore();
	getline(cin, _phoneNumber);

	if (toEdit.readFromFile(_phoneNumber))
	{
		cout << "Thong tin khach hang:\n";
		toEdit.output();
		string _id, _name, __phoneNumber, _passengerID;

		cout << "Nhap cac thong tin khach hang!\n";
		cout << "Nhap [x] de bo qua!";

		cout << "ID: ";
		getline(cin, _id);
		toEdit.id = _id != "x" ? _id : toEdit.id;

		cout << "Name: ";
		getline(cin, _name);
		toEdit.name = _name != "x" ? _name : toEdit.name;

		cout << "Phone number: ";
		getline(cin, __phoneNumber);
		toEdit.phoneNumber = __phoneNumber != "x" ? __phoneNumber : toEdit.phoneNumber;

		cout << "Passenger ID: ";
		getline(cin, _passengerID);
		toEdit.passengerID = _passengerID != "x" ? _passengerID : toEdit.passengerID;

		cout << "Thong tin sau khi thay doi la: \n";
		toEdit.output();
		toEdit.saveToFile();
	}
	else
	{
		cout << "Khach hang khong ton tai";
	}
}

void FlightList::editFlight()
{
	string a;
	string b;
	int k = list.size();
	cout << "Hay nhap chuyen bay ban muon thay doi ten" << endl;
	cin >> a;
	cout << "ID chuyen bay thay doi: ";
	cin >> b;
	int id;
	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == a)
		{
			list[i]->flightID = b;
		}
	}
	cout << "Thong tin sau khi doi id chuyen bay la: " << endl;
	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == b)
			list[i]->output();
	}
}

void FlightList::editTime()
{
	string a;
	float b;
	int k = list.size();
	cout << "Hay nhap id chuyen bay ban muon thay doi thoi gian" << endl;
	cin >> a;
	cout << "thoi gian ban thay doi: ";
	cin >> b;
	int id;
	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == a)
		{
			list[i]->flightLength = b;
		}
	}
	cout << "Thong tin sau khi doi id chuyen bay la: " << endl;
	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == a && list[i]->flightLength == b)
			list[i]->output();
	}
}

void FlightList::editDestination()
{
	string a;
	string b;
	int k = list.size();
	cout << "Hay nhap id chuyen bay ban muon thay doi thoi gian" << endl;
	cin >> a;
	cin.ignore();
	cout << "Diem den ban thay doi: ";
	getline(cin, b);
	int id;
	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == a)
		{
			list[i]->destinationAirport = b;
		}
	}
	cout << "Thong tin sau khi doi diem den chuyen bay la: " << endl;
	for (int i = 0; i < k; i++)
	{
		if (list[i]->flightID == a && list[i]->destinationAirport == b)
			list[i]->output();
	}
}

void FlightList::removeById()
{
	Flight *c[100];
	string a;
	int k = list.size();
	cout << "Ban hay nhap id can xoa: ";
	cin >> a;
	int choice;
	int nc = 0;
	int id;
	for (int i = 0; i < k; i++)
	{
		c[nc] = list[i];
		nc++;
	}
	for (int i = 0; i < nc; i++)
	{
		if (c[i]->passenger.id == a)
		{
			for (int j = i; j < nc; j++)
			{
				c[j] = c[j++];
			}
			i--;
			nc--;
		}
	}
	cout << "Sau khi xoa id ban muon la: " << endl;
	for (int i = 0; i < nc; i++)
	{
		c[i]->output();
	}
}

void FlightList::removeByName()
{
	Flight *c[100];
	string a;
	int k = list.size();
	cout << "Ban hay nhap id can xoa: ";
	getline(cin, a);
	int choice;
	int nc = 0;
	int id;
	for (int i = 0; i < k; i++)
	{
		c[nc] = list[i];
		nc++;
	}
	for (int i = 0; i < nc; i++)
	{
		if (c[i]->passenger.id == a)
		{
			for (int j = i; j < nc; j++)
			{
				c[j] = c[j++];
			}
			i--;
			nc--;
		}
	}
	cout << "Sau khi xoa id ban muon la: " << endl;
	for (int i = 0; i < nc; i++)
	{
		c[i]->output();
	}
}

void FlightList::removeByDoor()
{
	Flight *c[100];
	int a;
	int k = list.size();
	cout << "Ban hay nhap cong can xoa danh sach: ";
	cin >> a;
	int choice;
	int nc = 0;
	int id;
	for (int i = 0; i < k; i++)
	{
		c[nc] = list[i];
		nc++;
	}
	for (int i = 0; i < nc; i++)
	{
		if (c[i]->door == a)
		{
			for (int j = i; j < nc; j++)
			{
				c[j] = c[j++];
			}
			i--;
			nc--;
		}
	}
	cout << "Sau khi xoa cong ban muon la: " << endl;
	for (int i = 0; i < nc; i++)
	{
		c[i]->output();
	}
}

void FlightList::removeByDestination()
{
	Flight *c[100];
	string a;
	int k = list.size();
	cout << "Ban hay nhap noi den can xoa danh sach: ";
	getline(cin, a);
	int nc = 0;
	int id;
	for (int i = 0; i < k; i++)
	{
		c[nc] = list[i];
		nc++;
	}
	for (int i = 0; i < nc; i++)
	{
		if (c[i]->destinationAirport == a)
		{
			for (int j = i; j < nc; j++)
			{
				c[j] = c[j++];
			}
			i--;
			nc--;
		}
	}
	cout << "Sau khi xoa noi muon den la: " << endl;
	for (int i = 0; i < nc; i++)
	{
		c[i]->output();
	}
}

void FlightList::appendPassenger()
{
	Flight *c[100];
	Flight *b;
	int choice;
	int nc = 0;
	int k = list.size();
	for (int i = 0; i < k; i++)
	{
		c[nc] = list[i];
		nc++;
	}
	cout << "Hay nhap vi tri ban muon chen!!!";
	cin >> choice;
	cout << "Hay nhap thong tin: " << endl;
	Flight *d;
	int chon;
	cout << "EconomyClass/BusinessClass/FirstClass" << endl;
	cout << "Vui long nhap lua chon che do ve theo bang sau: ";
	cin >> chon;
	if (chon == 1)
		d = new EconomyClass;
	if (chon == 2)
		d = new BusinessClass;
	if (chon == 3)
		d = new FirstClass;
	d->input();
	for (int i = nc; i > choice; i--)
	{
		c[i] = c[i - 1];
	}
	nc++;
	c[choice] = d;
	cout << "============Danh sach sau khi them la: =============" << endl;
	for (int i = 0; i < nc; i++)
	{
		c[i]->output();
	}
}
