#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "FlightList.h"

using namespace std;

const string DATA_FILE = "./data/data.txt";
const string TEMP_FILE = "./data/temp.txt";
const string CSV_FILE = "./data/export.csv";

bool saveToFile(FlightList* list);
bool saveToTempFile(FlightList* list);
bool readFromFile(FlightList*& list);
bool readFromTempFile(FlightList*& list);

#endif
