#include "Menu.h"
void waitForInput()
{
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
	for (int i = 1; i < 50; i++) 
		if (i == 1 || i == 50 - 1) cout <<"+";
		else cout <<"-";
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
	alignCenter(header, 50);
	printLine();
}
void mainMenu(FlightList* list)
{
	int choice = 100;
	while (choice)
	{
		do 
		{
			clearConsole();
			printHeader("QUAN LY CHUYEN BAY");
			cout << "\t1. Doc du lieu tu File\n";
			cout << "\t2. Ghi File\n";
			cout << "\t3. Nhap\n";
			cout << "\t4. Xuat\n";
			cout << "\t5. Tinh tong gia ve trong danh sach\n";
			cout << "\t6. Tim Min/Max\n";
			cout << "\t7. Sap xep\n";
			cout << "\t8. Tim kiem\n";
			cout << "\t9. Chinh sua\n";
			cout << "\t10. Xoa khoi danh sach\n";
			cout << "\t11. Them vao danh sach\n";
			cout << "\t12. In hoa don\n";
			cout << "\t13. Thong tin nhom\n";
			cout << "\t0. Exit\n";
			printLine();
			cout << "Nhap lua chon: ";
			cin >> choice;
			if (!validChoice(choice, 0, 13))
			{
				cout << "Lua chon khong hop le. Vui long nhap lai!\n";
			}
		} while (!validChoice(choice, 0, 13));
		
		switch(choice)
		{
			case 1: readFileMenu(list); break;
			case 2: writeFileMenu(list); break;
			case 3: inputMenu(list); break;
			case 4: outputMenu(list); break;
			case 5: totalPriceMenu(list); break;
			case 6: minMaxMenu(list); break;
			case 7: sortMenu(list); break;
			case 8: filterMenu(list); break;
			case 9: editMenu(list); break;
			case 10: removeMenu(list); break;
			case 11: appendMenu(list); break;
			case 12: invoiceMenu(list); break;
			case 13: groupInfo(); break;
		};
	}
}
void readFileMenu(FlightList* list)
{
	clearConsole();
	printHeader("DOC FILE");
	
	waitForInput();	
}
void writeFileMenu(FlightList* list)
{
	clearConsole();
	printHeader("GHI FILE");

	waitForInput();	
}
void inputMenu(FlightList* list)
{
	clearConsole();
	list->input();
	waitForInput();	
}
void outputMenu(FlightList* list)
{
	clearConsole();
	list->output();
	waitForInput();	
}
void totalPriceMenu(FlightList* list)
{
	clearConsole();
	printHeader("TONG TIEN DANH SACH");

	list->totalPrice();
	waitForInput();	
}
void minMaxMenu(FlightList* list)
{
	clearConsole();
	printHeader("TIM MIN / MAX");
	
	waitForInput();
}
void sortMenu(FlightList* list)
{
	clearConsole();
	printHeader("SAP XEP");

	cout<<"1.Sap xep theo ngay xuat phat: "<<endl;
	cout<<"2.Sap xep theo ngay sinh: "<<endl;
	cout<<"3.Sap xep tong gia tang dan: "<<endl;
	int choice;
	cout<<"Hay nhap lua chon cua ban: ";
	cin>>choice;
	if (choice == 1) list->sortDateStart();
	waitForInput();
}
void filterMenu(FlightList* list)
{
	clearConsole();
	printHeader("LOC");
	
	waitForInput();
}
void editMenu(FlightList* list)
{
	clearConsole();
	printHeader("CHINH SUA");
	
	waitForInput();
}
void removeMenu(FlightList* list)
{
	clearConsole();
	printHeader("XOA KHOI DANH SACH");
	
	waitForInput();
}
void appendMenu(FlightList* list)
{
	clearConsole();
	printHeader("CHEN VAO DANH SACH");
	
	waitForInput();
}
void invoiceMenu(FlightList* list)
{
	clearConsole();
	printHeader("IN HOA DON");
	
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
	cout << "\t|" << left << setw(19) << "28211106319"
		 << "|" << left << setw(29) << "Nguyen Ba Khoa"
		 << "|" << left << setw(18) << "0943923714"
		 << "|" << left << setw(23) << "nbk2124.z@gmail.com"
		 << "|" << endl;
	cout << "\t|" << left << setw(19) << "28219005880"
		 << "|" << left << setw(29) << "Ho Thanh Tien"
		 << "|" << left << setw(18) << "0912590577"
		 << "|" << left << setw(23) << "hothanhtienqb@gmail.com"
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
		
		if(!validChoice(choice, 0, 1)) cout << "Lua chon khong hop le. Vui long nhap lai!\n";
	} while (!validChoice(choice, 0, 1));
}
bool validChoice(int choice, int min, int max)
{
	return (choice >= min && choice <= max);
}
