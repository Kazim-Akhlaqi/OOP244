/**********************************************************
// OOP244 Workshop 4: Constructors
// file Passenger.h
// Version: in_lab
// Date Jun/7/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

// TODO: add header file guard here 

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here

namespace sict {

// TODO: define the Passenger class here
	const int max_length = 32;
	class Passenger {
		char _passengerName[max_length];
		char _destination[max_length];
	public:
		Passenger();
		Passenger(const char *passengerName, const char* passengerDestination);
		bool isEmpty() const;
		void display() const;
	};
}

#endif // !SICT_PASSENGER_H_
