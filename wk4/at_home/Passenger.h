/**********************************************************
// OOP244 Workshop 4: Constructors
// file Passenger.h
// Version: at_home
// Date Jun/11/2018
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
	private:

		char _passengerName[max_length];
		char _destination[max_length];
		int _yearOfDeparture;
		int _monthOfDeparture;
		int _dayOfDeparture;

	public:
		Passenger();
		Passenger(const char* passengerName, const char* passengerDestination);
		Passenger(const char* passengerName, const char* passengerDestination, int departYear, int departMonth, int departDay);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger& passenger) const;
	};
}

#endif // !SICT_PASSENGER_H_
