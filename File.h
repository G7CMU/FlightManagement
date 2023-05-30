#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "FlightList.h"

using namespace std;

const string DATA_FILE = "./data/data.txt";
const string TEMP_FILE = "./data/temp.txt";
const string CSV_FILE = "./data/export.csv";

void saveToFile(FlightList* list);
void saveToTempFile(FlightList* list);
void readFromFile(FlightList*& list);
void readFromTempFile(FlightList*& list);

#endif
