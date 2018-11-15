/**********************************************************
// OOP244 Workshop 4: Constructors
// file Passenger.cpp
// Version: at_home
// Date Jun/11/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

// TODO: add your headers here 
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		_passengerName[0] = '\0';
		_destination[0] = '\0';
		_yearOfDeparture = 0;
		_monthOfDeparture = 0;
		_dayOfDeparture = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passengerName, const char* passengerDestination) {
		if ((passengerName == nullptr || passengerName[0] == '\0') || (passengerDestination == nullptr || passengerDestination[0] == '\0')) {
			_passengerName[0] = '\0';
			_destination[0] = '\0';
			_yearOfDeparture = 0;
			_monthOfDeparture = 0;
			_dayOfDeparture = 0;
		}
		else {
			strncpy(_passengerName, passengerName, max_length);
			strncpy(_destination, passengerDestination, max_length);
			_passengerName[max_length - 1] = '\0';
			_destination[max_length - 1] = '\0';
			_yearOfDeparture = 2017;
			_monthOfDeparture = 7;
			_dayOfDeparture = 1;
		}

	}

	// TODO: implement the constructor with 5 parameters here

	Passenger::Passenger(const char* passengerName, const char* passengerDestination, int departYear, int departMonth, int DepartDay){
		if (passengerName != nullptr && strlen(passengerName) > 0 &&
			passengerDestination != nullptr && strlen(passengerDestination) > 0 &&
			departYear >= 2017 && departYear <= 2020 && departMonth >= 1 && departMonth <= 12 && DepartDay >= 1 && DepartDay <= 31) {
			strcpy(_passengerName, passengerName);
			strcpy(_destination, passengerDestination);
			_yearOfDeparture = departYear;
			_monthOfDeparture = departMonth;
			_dayOfDeparture = DepartDay;
		}
		else {
			_passengerName[0] = '\0';
			_destination[0] = '\0';
			_yearOfDeparture = 0;
			_monthOfDeparture = 0;
			_dayOfDeparture = 0;
		}
	};

	// TODO: implement name query here

	const char* Passenger::name() const {
		return _passengerName;

	};

	// TODO: implement canTravelWith query here

	bool Passenger::canTravelWith(const Passenger& passenger) const {
		bool canTravel;
		if (strcmp(passenger._destination, _destination) == 0 && strcmp(passenger._destination, _destination) == 0 &&
			passenger._yearOfDeparture == _yearOfDeparture &&
			passenger._monthOfDeparture == _monthOfDeparture &&
			passenger._dayOfDeparture == _dayOfDeparture) {

			canTravel = true;
		}
		else {
			canTravel = false;
		}
		return canTravel ;
	};

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool empty;
		if (_passengerName[0] == '\0' || _passengerName == nullptr || _destination[0] == '\0' || _destination == nullptr) {
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}

	// TODO: implement display query here
	void Passenger::display() const {
		cout << _passengerName << " - " << _destination << " on " << _yearOfDeparture << "/";
		if (_monthOfDeparture < 10) {
			cout << "0" << _monthOfDeparture << "/";
			if (_dayOfDeparture < 10) {
				cout << "0" << _dayOfDeparture << endl;
			}
			else {
				cout << _dayOfDeparture << endl;
			}
		}
		else {
			cout << _monthOfDeparture << _dayOfDeparture << endl;
		}
	}
}





