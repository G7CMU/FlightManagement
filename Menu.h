#ifndef MENU_H
#define MENU_H

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

void mainMenu();
void readFileMenu();
void writeFileMenu();
void totalPriceMenu();
void minMaxMenu();
void sortMenu();
void filterMenu();
void editMenu();
void removeMenu();
void appendMenu();
void invoiceMenu();

void groupInfo();
void continueMenu();

bool validChoice(int choice, int min, int max);

#endif
