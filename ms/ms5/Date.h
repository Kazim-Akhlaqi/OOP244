// OOP244 Final Project Milestone 1
// file Date.h
// Version: 1.0
// Date July/10/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

namespace AMA {

	// Pre-define the limits on the years 
	const int min_year = 2000;
	const int max_year = 2030;

	// Define date error state
#define NO_ERROR   0  // No error - the date is valid
#define CIN_FAILED 1  // istream failed on information entry
#define YEAR_ERROR 2  // Year value is invalid
#define MON_ERROR  3  // Month value is invalid
#define DAY_ERROR  4  // Day value is invalid

	class Date {

		// Private members:
	private:


		int _year; // The year – a four digit integer between min_year and max_year
		int _month; // The month of the year – a value between 1 and 12 inclusive
		int _day; // The day of the month – a value between 1 and the number of days in the 
		int _comparator; // The comparator compares the date stored in the current object with the date stored in another Date object
		int _errorState; // The error state determine if the object holds a valid date, and if not, which part of the date is in error

						 // Member functions

						 // This query returns the number of days in month of year
		int mdays(int month, int year)const;

		// This function sets the error state variable to one of the values defined above.
		void errCode(int errorCode);

		// Public members
	public:

		// Default Constructors
		Date();

		// Data Validator Constructor
		Date(int year, int month, int day);

		// Comparison Operators
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		// Queries and modifiers

		//This query returns the error state as an error code value.
		int errCode() const;

		// This query returns true if the error state is not NO_ERROR.
		bool bad() const;

		// This query reads the date from the console in the following format: YYYY?MM?DD
		std::istream& read(std::istream& istr);

		// This query writes the date to an std::ostream object in the following format: YYYY/MM/DD
		std::ostream& write(std::ostream& ostr) const;
	};

	// Helper functions

	// This operator works with an std::ostream object to print a date to the console
	std::ostream& operator<<(std::ostream&, const Date&);

	// This operator works with an std::istream object to read a date from the console
	std::istream& operator>>(std::istream&, Date&);
}
#endif