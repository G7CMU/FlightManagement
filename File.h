#ifndef FILE_H
#define FILE_H
#include <iostream>

using namespace std;

const string dataFile = "data.txt";
const string tempFile = "temp.txt";
const string csvFile = "export.csv";

void saveToFile(FlightList list);
void saveToTempFile(FlightList list);
void readFromFile(FlightList &list);
void readFromTempFile(FlightList &list);

#endif

