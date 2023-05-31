#ifndef MENU_H
#define MENU_H
#include "FlightList.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int LINE_WIDTH = 50;
const string LINE = "-";
const string START_CHAR = "+";

void waitForInput();
void clearConsole();
void printLine();
void printSpace(int length);		
void alignCenter(string text, int containerLength);
void printTableCol(string text, int containerLength);
void printHeader(string header);

void mainMenu(FlightList* list);
void readFileMenu(FlightList* list);
void writeFileMenu(FlightList* list);
void totalPriceMenu(FlightList* list);
void minMaxMenu(FlightList* list);
void sortMenu(FlightList* list);
void filterMenu(FlightList* list);
void editMenu(FlightList* list);
void removeMenu(FlightList* list);
void appendMenu(FlightList* list);
void invoiceMenu(FlightList* list);
void inputMenu(FlightList* list);
void outputMenu(FlightList* list);
void groupInfo();
void continueMenu();

bool validChoice(int choice, int min, int max);

#endif
