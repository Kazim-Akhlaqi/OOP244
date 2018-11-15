/**********************************************************
// OOP244 Workshop 4: Constructors
// file Passenger.cpp
// Version: in_lab
// Date Jun/7/2018
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
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passengerName, const char* passengerDestination) {
		if ((passengerName == nullptr || passengerName[0] == '\0') || (passengerDestination == nullptr || passengerDestination[0] == '\0')) {
			_passengerName[0] = '\0';
			_destination[0] = '\0';
		}
		else {
			strncpy(_passengerName, passengerName, max_length);
			strncpy(_destination, passengerDestination, max_length);
			_passengerName[max_length-1] = '\0';
			_destination[max_length-1] = '\0';
		}
		
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool empty;
		if (_passengerName[0] == '\0' || _passengerName == nullptr || _destination[0] == '\0' || _destination == nullptr ) {
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (isEmpty()) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << _passengerName << " - " << _destination << endl;
		}
	}
}





