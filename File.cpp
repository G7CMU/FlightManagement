#include "File.h"

void saveToFile(FlightList* list)
{
  	ofstream fo(DATA_FILE.c_str());
  	
  	if (fo.is_open()) 
	{
		for (int i = 0; i < list->list.size(); i++)
  			list->list[i]->saveToFile(fo);
  		fo.close();
	}
  	else 
  		cout << "File not found";
}
void saveToTempFile(FlightList* list)
{
	ofstream fo;
  	fo.open(TEMP_FILE.c_str());
  	
  	if (fo.is_open()) 
	{
		for (int i = 0; i < list->list.size(); i++)
  			list->list[i]->saveToFile(fo);
  		fo.close();
	}
  	else 
  		cout << "File not found";
}
void readFromFile(FlightList*& list)
{
	ifstream fi(DATA_FILE.c_str());
  	Flight* toRead;
  	if (fi.is_open()) 
	{
		for (int i = 0; i < list->list.size(); i++)
			while (!fi.eof()) {
				
			}
  				toRead->readFromFile(fi);
  		fi.close();
	}
  	else 
  		cout << "File not found";
}
void readFromTempFile(FlightList*& list)
{
	ifstream fi(TEMP_FILE.c_str());
  	
  	if (fi.is_open()) 
	{
		for (int i = 0; i < list->list.size(); i++)
			while (!fi.eof())
  				list->list[i]->readFromFile(fi);
  		fi.close();
	}
  	else 
  		cout << "File not found";
}
