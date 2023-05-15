#include "Flight.h"

void Flight::input()
{
	int choice;
	cin.ignore();
	cout << "Passenger ID: ";
	getline(cin, passengerID);
	cout<<"Hanh khach nay da ton tai chua(1.Da ton tai/2.Chua ton tai): ";
	cin>>choice;
	if (choice==1)
	{
		cin.ignore();
		cout<<"Vi hanh khach da ton tai vui long nhap tiep!!!"<<endl;
		cout<<"AirlinesLabel: ";
		getline(cin, airlinesLabel);
		cout<<"FlightRoute: ";
		getline(cin, flightRoute);
		cout<<"StartAirport: ";
		getline(cin, startAirport);
		cout<<"StartDate: ";
		cin>>startDate;
		cout<<"destinationAirport: ";
		getline(cin, destinationAirport)
		cout<<"flightLength: ";
		cin>>flightLength;
		cin.ignore();
		cout<<"flightID: ";
		getline(cin, flightID);
		cout<<"flightNature(noi dia, ngoai dia): ";
		getline(cin, flightNature);
		cout<<"Door: ";
		cin>>door;
		cout<<"Chair: ";
		getline(cin, chair);
		cout<<"Destination: ";
		getline(cin, destination);
		cout<<"TimeDelay: ";
		cin>>timeDelay;
		cout<<"From: ";
		cin>>from;
		cout<<"To";
		cin>>to;
		cout<<"typeOfLuggage: ";
		cin>>typeOfLuggage;
		cout<<"initialPrice: ";
		cin>>initialPrice;
	//	cin>>a;
		a.input();
	}
	else 
	{
		cout<<"Vi hanh khach chua ton tai nen vui long khai bao danh tinh: ";
		a.input();
		cout<<"AirlinesLabel: ";
		getline(cin, airlinesLabel);
		cout<<"FlightRoute: ";
		getline(cin, flightRoute);
		cout<<"StartAirport: ";
		getline(cin, startAirport);
		cout<<"StartDate: ";
		cin>>startDate;
		cout<<"destinationAirport: ";
		getline(cin, destinationAirport)
		cout<<"flightLength: ";
		cin>>flightLength;
		cin.ignore();
		cout<<"flightID: ";
		getline(cin, flightID);
		cout<<"flightNature(noi dia, ngoai dia): ";
		getline(cin, flightNature);
		cout<<"Door: ";
		cin>>door;
		cout<<"Chair: ";
		getline(cin, chair);
		cout<<"Destination: ";
		getline(cin, destination);
		cout<<"TimeDelay: ";
		cin>>timeDelay;
		cout<<"From: ";
		cin>>from;
		cout<<"To";
		cin>>to;
		cout<<"typeOfLuggage: ";
		cin>>typeOfLuggage;
		cout<<"initialPrice: ";
		cin>>initialPrice;
	}
}
void Flight::output()
{
	a.output();
	cout<<"AirlinesLabel: "<<airlinesLabel<<endl;
	cout<<"FlightRoute: "<<flightRoute<<endl;
	cout<<"StartAirport: "<<startAirport<<endl;
	cout<<"StartDate: "<<startDate<<endl;
	cout<<"destinationAirport: "<<destinationAirport<<endl;
	cout<<"flightLength: "<<flightLength<<endl;
	cout<<"flightID: "<<flightID<<endl<<endl;
	cout<<"flightNature(noi dia, ngoai dia): "<<flightNature<<endl;
	cout<<"Door: "<<door<<endl;
	cout<<"Chair: "<<chair<<endl;
	cout<<"Destination: "<<destination<<endl;
	cout<<"TimeDelay: "<<timeDelay<<endl;
	cout<<"From: "<<from<<endl;
	cout<<"To: "<<to<<endl;
	cout<<"typeOfLuggage: "<<typeOfLuggage<<endl;
	cout<<"initialPrice: "<<initialPrice<<endl;
}
FlightType Flight::classType()
{
	return 0;
}
float Flight::TotalPrice()
{
	return 0;
}
