#include "Menu.h"

void waitForInput()
{
	string dumpInput;
	cout << "Nhan phim bat ki de quay lai!";
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
		if (i == 1 || i == LINE_WIDTH - 1) cout << START_CHAR;
		else cout << LINE;
	cout << "\n";
}

void printSpace(int length)
{
	cout << left << setw(length) << "";
}

void alignCenter(string text, int containerLength)
{
	int space = (containerLength - text.length()) / 2 - 2;
	cout << "|";
	printSpace(space);
	cout << text;
	printSpace(space + 1);
	cout << "|" << endl;
}

void printTableCol(string text, int containerLength)
{
	int sub = 0;
	int space = (containerLength - text.length()) / 2;
	if (text.length() % 2 == 1) sub = 1;
	printSpace(space);
	cout << text;
	printSpace(space - sub);
	cout << "|";
}

void printHeader(string header)
{
	printLine();
	alignCenter(header, LINE_WIDTH);
	printLine();
}

void mainMenu()
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
			cout << "\t3. Tinh tong gia ve trong danh sach\n";
			cout << "\t4. Tim Min/Max\n";
			cout << "\t5. Sap xep\n";
			cout << "\t6. Tim kiem\n";
			cout << "\t7. Chinh sua\n";
			cout << "\t8. Xoa khoi danh sach\n";
			cout << "\t9. Them vao danh sach\n";
			cout << "\t10. In hoa don\n";
			cout << "\t11. Thong tin nhom\n";
			cout << "\t0. Exit\n";
			printLine();
			cout << "Nhap lua chon: ";
			cin >> choice;
			if (!validChoice(choice, 0, 11))
			{
				cout << "Lua chon khong hop le. Vui long nhap lai!\n";
			}
		} while (!validChoice(choice, 0, 11));
		
		switch(choice)
		{
			case 1: readFileMenu(); break;
			case 2: writeFileMenu(); break;
			case 3: totalPriceMenu(); break;
			case 4: minMaxMenu(); break;
			case 5: sortMenu(); break;
			case 6: filterMenu(); break;
			case 7: editMenu(); break;
			case 8: removeMenu(); break;
			case 9: appendMenu(); break;
			case 10: invoiceMenu(); break;
			case 11: groupInfo(); break;
		};
	}
}

void readFileMenu()
{
	clearConsole();
	printHeader("DOC FILE");
	
	waitForInput();	
}
void writeFileMenu()
{
	clearConsole();
	printHeader("GHI FILE");
	
	waitForInput();	
}
void totalPriceMenu()
{
	clearConsole();
	printHeader("TONG TIEN DANH SACH");
	
	waitForInput();	
}
void minMaxMenu()
{
	clearConsole();
	printHeader("TIM MIN / MAX");
	
	waitForInput();
}
void sortMenu()
{
	clearConsole();
	printHeader("SAP XEP");
	
	waitForInput();
}
void filterMenu()
{
	clearConsole();
	printHeader("LOC");
	
	waitForInput();
}
void editMenu()
{
	clearConsole();
	printHeader("CHINH SUA");
	
	waitForInput();
}
void removeMenu()
{
	clearConsole();
	printHeader("XOA KHOI DANH SACH");
	
	waitForInput();
}
void appendMenu()
{
	clearConsole();
	printHeader("CHEN VAO DANH SACH");
	
	waitForInput();
}
void invoiceMenu()
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
