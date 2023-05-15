#include "FlightList.h"

FlightList::FlightList()
{
	this->k=0;
}
void FlightList::input()
{

	while (true)
		{
			Flight* ds;
			int chon, choice;
			cout << "EconomyClass/BusinessClass/FirstClass/exit" << endl;
			cout << "Vui long nhap lua chon che do ve theo bang sau: ";
			cin >> chon;
			if (chon == 1) ds = new EconomyClass;
			if (chon == 2) ds = new BusinessClass;
			if (chon == 3) ds = new FirstClass;
			if (chon == 4) break;
			ds->input();
			list[k] = ds;
			k++;
			cout << "Ban co muon tiep tuc khong: ";
			cout << "Neu co hay nhap 1: ";
			cin >> choice;
			if (choice == 1)
				continue;
			else break;
		}
}
void FlightList::output()
{
	for(int i=0; i < k; i++)
	{
		cout<<"---------------------------------"<<endl;;
		list[i]->output();
		cout<<"Tax: "<<list[i]->tax()<<endl;
		cout<<"Price: "<<list[i]->price()<<endl;
		cout<<"---------------------------------"<<endl;;
	}
}
void FlightList::sortBirth()
{
	for(int i=0; i<k; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if (list[i].startDate->year>list[j].startDate->year)
			{
				swap(list[i],list[j]);
			}
		}
	}
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if (list[i].startDate->year==list[i+1].startDate->year)
			{
				if (list[i].startDate->month>list[i+1].startDate->month)
				swap(list[i],list[j]);
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if (list[i].startDate->year!==list[i+1].startDate->year) && (list[i].startDate->year==list[i+1].startDate->year)
			{
				if (list[i].startDate->day>list[i+1].startDate->day)
				swap(list[i],list[j]);
			}
		}
	}
}*/
