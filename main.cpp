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
	FlightList* list = new FlightList();
	readFromFile(list);
	mainMenu(list);
	saveToFile(list);
	saveToTempFile(list);
	return 0;
}


/**
3
1
1
0943923714
vietname airline
VN - Thai
Tan son nhat
21
5
2023
thai
6
vn557
noi dia
78
A98
Thai
2
VN
THAI
vali
10000
1
1112233
5
16
32
*/
