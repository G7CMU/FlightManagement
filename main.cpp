#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Date.h"
#include "Passenger.h"

using namespace std;

int main(int argc, char** argv) {
//	mainMenu();
	ifstream fi("data.txt");
//	ofstream fo("data.txt");
	Passenger* p = new Passenger();
//	p->input();
//	p->saveToFile(fo);
	p->readFromFile(fi);
	p->output();
	
//	fo.close();
	fi.close();
	return 0;
}
