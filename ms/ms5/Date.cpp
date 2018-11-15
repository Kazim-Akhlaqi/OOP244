// OOP244 Final Project Milestone 1
// file Date.cpp
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

#include "Date.h"

using namespace std;

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	// This function sets the _errorState variable to one of the values defined above
	void Date::errCode(int errorCode) {
		_errorState = errorCode;
	}

	// This Default Constructor sets the private members to safe empty state
	Date::Date() {
		_year = 0;
		_month = 0;
		_day = 0;
		_comparator = 0;
		errCode(NO_ERROR);
	}

	// This Constructor recieves and stores the data
	// in private members variables if it is valid
	Date::Date(int year, int month, int day) {
		if (year > min_year || year > max_year) {
			errCode(YEAR_ERROR);
		} else if (month < 1 || month > 12) {
			errCode(MON_ERROR);
		} else if (day < 1 || day > mdays(month, year)) {
			errCode(DAY_ERROR);
		}
		if ((year > min_year && year < max_year)
			&& (month > 1 && month < 12)
			&& (day > 1 && day < mdays(month, year))) {
			_year = year;
			_month = month;
			_day = day;
			_comparator = year * 372 + month * 13 + day;
			errCode(NO_ERROR);
		}
		else {
			*this = Date();
			_comparator = 0;
		}
	}

	// Comparison Operators
	// ==
	bool Date::operator==(const Date& rhs) const {
		if (_year != 0 && rhs._year != 0)
			return _comparator == rhs._comparator;
		else
			return false;
	}
	// !=
	bool Date::operator!=(const Date& rhs) const {
		if (_year != 0 && rhs._year != 0)
			return _comparator != rhs._comparator;
		else
			return false;
	}
	// <
	bool Date::operator<(const Date& rhs) const {
		if (_year != 0 && rhs._year != 0)
			return _comparator < rhs._comparator;
		else
			return false;
	}

	// >
	bool Date::operator>(const Date& rhs) const {
		if (_year != 0 && rhs._year != 0)
			return _comparator > rhs._comparator;
		else
			return false;
	}
	// <=
	bool Date::operator<=(const Date& rhs) const {
		if (_year != 0 && rhs._year != 0)
			return _comparator <= rhs._comparator;
		else
			return false;
	}
	// >=
	bool Date::operator>=(const Date& rhs) const {
		if (_year != 0 && rhs._year != 0)
			return _comparator >= rhs._comparator;
		else
			return false;
	}

	//This query returns the error state as an error code 
	int Date::errCode() const
	{
		return _errorState;
	}

	// This query returns true if the error state is not NO_ERROR
	bool Date::bad() const {
		if (_errorState != NO_ERROR) {
			return true;
		} else
			return false;
	}

	// This query reads the date from the console in the following format: YYYY?MM?DD
	std::istream& Date::read(std::istream& istr) {
		int day;
		int month;
		int year;
		char delimeter;
		istr.clear();
		istr >> year >> delimeter >> month >> delimeter >> day;

		if (istr.fail()) {
			errCode(CIN_FAILED);
			return istr;
		}
		else if (year < min_year || year > max_year) {
			errCode(YEAR_ERROR);
		}
		else if (month < 1 || month > 12) {
			errCode(MON_ERROR);
		}
		else if (day < 1 || day > mdays(month, year)) {
			errCode(DAY_ERROR);
		}
		else {
			_year = year;
			_month = month;
			_day = day;
			errCode(NO_ERROR);
		}
		return istr;
	}

	// This query writes the date to an std::ostream object in the following format: YYYY/MM/DD
	std::ostream& Date::write(std::ostream& ostr) const {

		ostr << _year << '/';
		ostr.width(2);
		ostr.fill('0');
		ostr << _month << '/';
		ostr.width(2);
		ostr << _day;

		return ostr;
	}

	// This operator works with an std::ostream object to print a date to the console
	std::ostream& operator<<(std::ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

	// This operator works with an std::istream object to read a date from the console
	std::istream& operator>>(std::istream& istr, Date& date) {
		return date.read(istr);
	}

	
}