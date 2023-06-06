#include "File.h"

bool saveToFile(FlightList *list)
{
	ofstream fo(DATA_FILE.c_str());
	if (!fo.is_open())
	{
		cout << "File not found\n";
		return false;
	}

	fo << list->list.size() << endl;
	for (int i = 0; i < list->list.size(); i++)
		list->list[i]->saveToFile(fo);
	fo.close();

	return true;
}
bool saveToTempFile(FlightList *list)
{
	ofstream fo(TEMP_FILE.c_str());

	if (!fo.is_open())
	{
		cout << "File not found\n";
		return false;
	}

	fo << list->list.size() << endl;
	for (int i = 0; i < list->list.size(); i++)
		list->list[i]->saveToFile(fo);
	fo.close();
	return true;
}
bool readFromFile(FlightList *&list)
{
	ifstream fi(DATA_FILE.c_str());
	Flight *toRead;
	FlightType type;
	int type_i, fl_number;

	if (!fi.is_open())
	{
		cout << "File not found\n";
		return false;
	}

	fi >> fl_number;
	for (int i = 0; i < fl_number; i++)
	{
		fi >> type_i;
		type = (FlightType)type_i;
		switch (type)
		{
		case ECONOMY:
			toRead = new EconomyClass();
			break;
		case BUSINESS:
			toRead = new BusinessClass();
			break;
		case FIRST:
			toRead = new FirstClass();
			break;
		}
		toRead->readFromFile(fi);
		list->list.push_back(toRead);
	}
	fi.close();

	return true;
}
bool readFromTempFile(FlightList *&list)
{
	ifstream fi(TEMP_FILE.c_str());
	Flight *toRead;
	FlightType type;
	int type_i, fl_number;

	if (!fi.is_open())
	{
		cout << "File not found\n";
		return false;
	}

	fi >> fl_number;
	for (int i = 0; i < fl_number; i++)
	{
		fi >> type_i;
		type = (FlightType)type_i;
		switch (type)
		{
		case ECONOMY:
			toRead = new EconomyClass();
			break;
		case BUSINESS:
			toRead = new BusinessClass();
			break;
		case FIRST:
			toRead = new FirstClass();
			break;
		}
		toRead->readFromFile(fi);
		list->list.push_back(toRead);
	}
	fi.close();

	return true;
}
