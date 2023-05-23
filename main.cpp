#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Date.h"
#include "Passenger.h"
#include "FlightList.h"

using namespace std;

void testFileInput();
void testFileOutput();
void testPassenger();

int main(int argc, char **argv)
{
	FlightList* list = new FlightList();
//	mainMenu(list);
	
//	testFileInput();

	testPassenger();

	return 0;
}

void testFileInput()
{
	ifstream efi("e_c.txt");
	ifstream bfi("b_c.txt");
	ifstream ffi("f_c.txt");
	
	EconomyClass* e = new EconomyClass();
	e->readFromFile(efi);
	e->output();
	
	BusinessClass* b = new BusinessClass();
	b->readFromFile(bfi);
	b->output();
	
	FirstClass* f = new FirstClass();
	f->readFromFile(ffi);
	f->output();
}

void testFileOutput();

void testPassenger()
{
	Passenger p;
	
	p.input();
	p.output();
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
