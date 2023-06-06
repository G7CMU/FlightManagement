#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Date.h"
#include "Passenger.h"
#include "FlightList.h"
#include "File.h"

using namespace std;

int main(int argc, char **argv)
{
	FlightList *list = new FlightList();
	readFromFile(list);
	mainMenu(list);
	saveToFile(list);
	saveToTempFile(list);
	return 0;
}

/**
3
1
2
123
1
khoa
nam
21
1
2004
0943923714
Vietnam Airline
VN - TH
Tan Son Nhat
6
6
2023
Thai
9
VN223
ngoai dia
21
A45
Thai
0
VN
TH
vali
2000
1
20000
20
45
60
*/
