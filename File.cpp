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
  	FlightType type;
  	int type_i;
  	if (fi.is_open()) 
	{
		for (int i = 0; i < list->list.size(); i++)
			while (!fi.eof()) {
				fi >> type_i;
				type = (FlightType)type_i;
				switch(type) 
				{
					case ECONOMY: toRead = new EconomyClass(); break;
					case BUSINESS: toRead = new BusinessClass(); break;
					case FIRST: toRead = new FirstClass(); break;
				}
				toRead->readFromFile(fi);
				list->list.push_back(toRead);
			}
  				
  		fi.close();
	}
  	else 
  		cout << "File not found";
}
void readFromTempFile(FlightList*& list)
{
	ifstream fi(TEMP_FILE.c_str());
  	Flight* toRead;
  	FlightType type;
  	int type_i;
  	if (fi.is_open()) 
	{
		for (int i = 0; i < list->list.size(); i++)
			while (!fi.eof()) {
				fi >> type_i;
				type = (FlightType)type_i;
				switch(type) 
				{
					case ECONOMY: toRead = new EconomyClass(); break;
					case BUSINESS: toRead = new BusinessClass(); break;
					case FIRST: toRead = new FirstClass(); break;
				}
				toRead->readFromFile(fi);
				list->list.push_back(toRead);
			}
  				
  		fi.close();
	}
  	else
  		cout << "File not found";
}
