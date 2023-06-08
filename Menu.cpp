#include "Menu.h"
void waitForInput()
{
	printLine();
	string dumpInput;
	cout << "Nhan Enter de tiep tuc!";
	cin.ignore();
	getline(cin, dumpInput);
}
void clearConsole()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
}
void printLine()
{
	for (int i = 1; i < LINE_WIDTH; i++)
		if (i == 1 || i == LINE_WIDTH - 1)
			cout << "+";
		else
			cout << "-";
	cout << "\n";
}
void printSpace(int length)
{
	cout << setw(length) << "";
}
void alignCenter(string text, int containerLength)
{
	int space = (containerLength - text.length()) / 2 - 2;
	cout << "|";
	printSpace(space);
	cout << text;
	printSpace(space + 1);
	cout << (text.length() % 2 == 0 ? "|" : " |") << endl;
}
void printTableCol(string text, int containerLength)
{
	int space = (containerLength - text.length()) / 2;
	printSpace(space);
	cout << text;
	printSpace(space - 1);
	cout << "|";
}
void printHeader(string header)
{
	printLine();
	alignCenter(header, LINE_WIDTH);
	printLine();
}
void mainMenu(FlightList *list)
{
	int choice = 100;
	while (choice)
	{
		do
		{
			clearConsole();
			cout<<"*"<<endl; 
			cout<<" **                                                               "<<endl;
			cout<<" ***                                                                  "<<endl;
			cout<<"  ****						                     ***" <<endl;
			cout<<"   *****     *                                                     ****"<<endl;
			cout<<"    *****  ****  			                     *********"<<endl;
			cout<<"     *************		      	                  ***********"<<endl;		
			cout<<"      ********************                          ****************"<<endl;
			cout<<"     *********************************************************************************"<<endl;
			cout<<"    *****      **************************   *****   *****   *****   *****   *****    *******"<<endl;
			cout<<"   **               *********************   *****   *****   *****   *****   *****    **************"<<endl;
			cout<<"  *                                 *********************************************************"<<endl;
			cout<<"                                         *************************"<<endl;
			cout<<"                                        ************************"<<endl;
			cout<<"                                       ********************* ****"<<endl;
			cout<<"                                    ********************     ****"<<endl;
			cout<<"                                  ****************           ****"<<endl;
			cout<<"                                ************	****"<<endl;
			cout<<"                              *********         ****"<<endl;
			cout<<"                           ******		****"<<endl;
			cout<<"                         **"<<endl;
			printHeader("QUAN LY CHUYEN BAY");
			cout << "|| 1.  Doc du lieu tu File                     ||\n";
			cout << "|| 2.  Ghi File                                ||\n";
			cout << "|| 3.  Nhap   				       ||\n";
			cout << "|| 4.  Xuat			 	       ||\n";	
			cout << "|| 5.  Tinh tong gia ve trong danh sach        ||\n";
			cout << "|| 6.  Tim Min/Max			       ||\n";
			cout << "|| 7.  Sap xep				       ||\n";
			cout << "|| 8.  Tim kiem				       ||\n";
			cout << "|| 9.  Chinh sua	 		       ||\n";
			cout << "|| 10. Xoa khoi danh sach		       ||\n";
			cout << "|| 11. Them vao danh sach	               ||\n";
			cout << "|| 12. In hoa don			       ||\n";
			cout << "|| 13. Thong tin nhom			       ||\n";
			cout << "|| 0.  Exit				       ||\n";
			printLine();
			cout << "Nhap lua chon: ";
			cin >> choice;
			if (!validChoice(choice, 0, 13))
			{
				cout << "Lua chon khong hop le. Vui long nhap lai!\n";
			}
		} while (!validChoice(choice, 0, 13));

		switch (choice)
		{
		case 1:
			readFileMenu(list);
			break;
		case 2:
			writeFileMenu(list);
			break;
		case 3:
			inputMenu(list);
			break;
		case 4:
			outputMenu(list);
			break;
		case 5:
			totalPriceMenu(list);
			break;
		case 6:
			minMaxMenu(list);
			break;
		case 7:
			sortMenu(list);
			break;
		case 8:
			filterMenu(list);
			break;
		case 9:
			editMenu(list);
			break;
		case 10:
			removeMenu(list);
			break;
		case 11:
			appendMenu(list);
			break;
		case 12:
			invoiceMenu(list);
			break;
		case 13:
			groupInfo();
			break;
		};
	}
}

void readFileMenu(FlightList *list)
{
	clearConsole();
	printHeader("DOC FILE");
	if(readFromFile(list))
	{
		cout << "Doc file thanh cong!\n";
	}
	else
	{
		cout << "Co loi xay ra\n";
	}
	waitForInput();
}

void writeFileMenu(FlightList *list)
{
	clearConsole();
	printHeader("GHI FILE");
	if(saveToFile(list))
	{
		cout << "Ghi file thanh cong!\n";
	}
	else
	{
		cout << "Co loi xay ra\n";
	}
	waitForInput();
}

void inputMenu(FlightList *list)
{
	clearConsole();
	list->input();
	waitForInput();
}

void outputMenu(FlightList *list)
{
	clearConsole();
	list->output();
	waitForInput();
}

void totalPriceMenu(FlightList *list)
{
	clearConsole();
	printHeader("TONG TIEN DANH SACH");
	list->TotalPrice();
	waitForInput();
}

void minMaxMenu(FlightList *list)
{
	clearConsole();
	int choice;
	printHeader("TIM MIN / MAX");
	cout << "1. Tim min gia ve phai tra.       " << endl;
	cout << "2. Tim max gia ve phai tra.         " << endl;
	cout << "3. Exit. " << endl;
	cout << "================================================="<<endl;
	cout << "Hay nhap su lua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
		list->minPrice();
	if (choice == 2)
		list->maxPrice();
	waitForInput();
}

void sortMenu(FlightList *list)
{
	clearConsole();
	printHeader("SAP XEP");

	cout << "|1.  Sap xep tang dan theo ngay xuat phat:      |" << endl;
	cout << "|2.  Sap xep giam dan theo ngay xuat phat:      |" << endl;
	cout << "|3.  Sap xep tang dan theo ngay sinh:           |" << endl;
	cout << "|4.  Sap xep giam dan theo ngay sinh:           |" << endl;
	cout << "|5.  Sap xep tong gia tang dan:                 |" << endl;
	cout << "|6.  Sap xep tong gia giam dan:                 |" << endl;
	cout << "|7.  Sap xep ID hanh khach tang dan:            |" << endl;
	cout << "|8.  Sap xep ID hanh khach giam dan:            |" << endl;
	cout << "|9.  Sap xep tang dan theo thoi gian bay:       |" << endl;
	cout << "|10. Sap xep giam dan theo thoi gian bay:	|" << endl;
	cout << "|11. Sap xep tang dan theo gia thue:		|" << endl;
	cout << "|12. Sap xep giam dan theo gia thue:            |" << endl;
	cout << "================================================="<<endl;
	int choice;
	cout << "Hay nhap lua chon cua ban: ";
	cin >> choice;
	if (choice == 1)
		list->sortDateStart1();
	if (choice == 2)
		list->sortDateStart2();
	if (choice == 3)
		list->sortBybirth();
	if (choice == 4)
		list->sortByBirth1();
	if (choice == 5)
		list->sortByPriceAsc();
	if (choice == 6)
		list->sortByPriceDesc();
	if (choice == 7)
		list->sortByidAsc();
	if (choice == 8)
		list->sortByidDesc();
	if (choice == 9)
		list->sortByLengthAsc();
	if (choice == 10)
		list->sortByLengthDesc();
	if (choice == 11)
		list->sortByTaxAsc();
	if (choice == 12)
		list->sortByTaxDesc();
	cout<<"Hay dung chuc nang xuat de xem duoc ket qua ban nhe !!!"<<endl;
	waitForInput();
}

void filterMenu(FlightList *list)
{
	clearConsole();
//	printHeader("LOC");
	list->findAll();
	waitForInput();
}

void editMenu(FlightList *list)
{
	int choice;
	clearConsole();
	printHeader("CHINH SUA");

	while (true)
	{
		cout << "-------------------------------------------------"<<endl;
		cout << "|1. Chinh sua id hanh khach.                    |" << endl;
		cout << "|2. Chinh sua ma chuyen bay.                    |" << endl;
		cout << "|3. Chinh sua do dai thoi gian bay.             |" << endl;
		cout << "|4. Chinh sua noi den.                          |" << endl;
		cout << "|5. Chinh sua tuyen duong bay.                  |"<<endl;
		cout << "|6. Chinh sua hang may bay.                     |"<<endl;
		cout << "|7. Chinh sua cong vao.                         |"<<endl;
		cout << "|8. Chinh sua ghe ngoi.                         |"<<endl;
		cout << "|9. Chinh sua loai hanh ly.                     |"<<endl;
		cout << "|0. Exit                                        |" << endl;
		cout << "================================================="<<endl;
		cout << "Hay nhap lua chon cua minh: ";
		cin >> choice;
		if (choice == 1)
			list->editPassengerByPhoneNumber();
		if (choice == 2)
			list->editFlight();
		if (choice == 3)
			list->editTime();
		if (choice == 4)
			list->editDestination();
		if (choice == 5)
			list->editflightRoute();
		if (choice == 6)
			list->editairlinesLabel();
		if (choice == 7)
			list->editDoor();
		if (choice == 8)
			list->editChair();
		if (choice == 9)
			list->edittypeOfLuggage();
		if (choice == 0)
			break;
		cout<<"Hay dung chuc nang xuat de xem duoc ket qua ban nhe !!!"<<endl;
	}
	waitForInput();
}

void removeMenu(FlightList *list)
{
	int choice;
	clearConsole();
	printHeader("XOA KHOI DANH SACH");
	while (true)
	{
		cout << "-------------------------------------------------"<<endl;
		cout << "|1. Xoa danh sach theo ID may bay.              |" << endl;
		cout << "|2. Xoa danh sach theo cong vao.                |" << endl;
		cout << "|3. Xoa danh sach theo noi den.                 |" << endl;
		cout << "|4. Xoa hanh khach theo so dien thoai.          |" <<endl;
		cout << "|0. Exit.                                       |" << endl;
		cout << "================================================="<<endl;
		cout << "Hay nhap lua chon cua ban: ";
		cin >> choice;
		if (choice == 1)
			list->removeFlightById();
		if (choice == 2)
			list->removeFlightByDoor();
		if (choice == 3)
			list->removeFlightByDestination();
		if (choice ==4)
			list->removepassengerID();
		if (choice == 0)
			break;
		cout<<"Hay dung chuc nang xuat de xem duoc ket qua ban nhe !!!"<<endl;
	}
	waitForInput();
}

void appendMenu(FlightList *list)
{
	clearConsole();
	printHeader("CHEN VAO DANH SACH");
	list->appendFlight();
	cout<<"Hay dung chuc nang xuat de xem duoc ket qua ban nhe !!!"<<endl;
	waitForInput();
	
}

void invoiceMenu(FlightList *list)
{
	clearConsole();
	printHeader("IN HOA DON");
	list->printinvoice();
	waitForInput();
}

void groupInfo()
{
	clearConsole();
	printHeader("THONG TIN NHOM");
	cout << "TEN DE TAI: QUAN LY CHUYEN BAY\n";
	cout << "BANG THONG TIN NHOM: \n";
	cout << "\t|";
	printTableCol("MSSV", 20);
	printTableCol("Ho Ten", 30);
	printTableCol("SDT", 20);
	printTableCol("Mail", 25);
	cout << endl;
	cout << "\t|" << left << setw(19) << "28219005880"
		 << "|" << left << setw(29) << "Ho Thanh Tien"
		 << "|" << left << setw(18) << "0912590577"
		 << "|" << left << setw(23) << "hothanhtienqb@gmail.com"
		 << "|" << endl;
	cout << "\t|" << left << setw(19) << "28211106319"
		 << "|" << left << setw(29) << "Nguyen Ba Khoa"
		 << "|" << left << setw(18) << "0943923714"
		 << "|" << left << setw(23) << "nbk2124.z@gmail.com"
		 << "|" << endl;
	cout << "\t|" << left << setw(19) << "28219001381"
		 << "|" << left << setw(29) << "Tran Dinh Quan"
		 << "|" << left << setw(18) << "0943923714"
		 << "|" << left << setw(23) << ""
		 << "|" << endl;
	cout << "\t|" << left << setw(19) << "28211103250"
		 << "|" << left << setw(29) << "Ho Tan Phong"
		 << "|" << left << setw(18) << "0943923714"
		 << "|" << left << setw(23) << "phongho763@gmail.com"
		 << "|" << endl;
	waitForInput();
}

void continueMenu()
{
	int choice;
	do
	{
		printLine();
		cout << "0. Thoat\n";
		cout << "1. Tiep tuc\n";
		cout << "Nhap lua chon: ";
		cin >> choice;
		if (!validChoice(choice, 0, 1))
			cout << "Lua chon khong hop le. Vui long nhap lai!\n";
	} while (!validChoice(choice, 0, 1));
}
bool validChoice(int choice, int min, int max)
{
	return (choice >= min && choice <= max);
}
