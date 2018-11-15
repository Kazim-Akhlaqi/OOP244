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

#include <iostream>
#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	// This function sets the _errorState variable to one of the values defined above
	void Date::errCode(int errorCode){
		_errorState = errorCode;
	}

	// This Default Constructor sets the private members to safe empty state
	Date::Date(){
		_year = 0000;
		_month = 00;
		_day = 00;
		_comparator = 0;
		_errorState = NO_ERROR;
	}

	// This Constructor recieves and stores the data
	// in private members variables if it is valid
	Date::Date(int year, int month, int day){
		if ((year >= min_year || year <= max_year) && year > 0 
			&& (mdays(month, year) != 13 && day <= mdays(month, year))){
			_year = year;
			_month = month;
			_day = day;
			_comparator = year * 372 + month * 13 + day;
		} else {
			*this = Date();
		}
	}

	// Comparison Operators
	// ==
	bool Date::operator==(const Date& rhs) const {
		bool TF;
		if (this->_year == rhs._year
			&& this->_month == rhs._month
			&& this->_day == rhs._day){
			TF = true;
		}
		else {
			TF = false;
		}
		return TF;
	}
	// !=
	bool Date::operator!=(const Date& rhs) const {
		bool TF;
		if (this->_year == rhs._year
			&& this->_month == rhs._month
			&& this->_day == rhs._day) {
			TF = false;
		}
		else {
			TF = true;
		}
		return TF;
	}
	// <
	bool Date::operator<(const Date& rhs) const {
		bool TF;
		if (this->_year < rhs._year
			&& this->_month < rhs._month
			&& this->_day < rhs._day){
			TF = false;
		}
		else {
			TF = true;
		}
		return TF;
	}
	
	// >
	bool Date::operator>(const Date& rhs) const {
		bool TF;
		if (this->_year > rhs._year
			&& this->_month > rhs._month
			&& this->_day > rhs._day) {
			TF = false;
		}
		else {
			TF = true;
		}
			return TF;
	}
	// <=
	bool Date::operator<=(const Date& rhs) const {
		bool TF;
		if (this->_year <= rhs._year
			&& this->_month <= rhs._month
			&& this->_day <= rhs._day) {
			TF = true;
		}
		else {
			TF = false;
		}
			return TF;
	}
	// >=
	bool Date::operator>=(const Date& rhs) const {
		bool TF;
		if (this->_year >= rhs._year
			&& this->_month >= rhs._month
			&& this->_day >= rhs._day) {
			TF = true;
		}
		else {
			TF = false;
		}
			return TF;
	}

	//This query returns the error state as an error code value
	int Date::errCode() const
	{
		return _errorState;
	}

	// This query returns true if the error state is not NO_ERROR
	bool Date::bad() const {
		bool TF;
		if (_errorState != NO_ERROR) {
			TF = true;
		}
		else {
			TF = false;
		}
		return TF;
	}

	// This query reads the date from the console in the following format: YYYY?MM?DD
	std::istream& Date::read(std::istream& istr){
		char date;
		istr.clear();
		istr >> _year >> date >> _month >> date >> _day;

		if (istr.fail()){
			*this = Date();
			errCode(CIN_FAILED);
		} else if (min_year > _year || _year > max_year){
			*this = Date();
			errCode(YEAR_ERROR);
		} else if (1 > _month || _month > 12){
			*this = Date();
			errCode(MON_ERROR);
		} else if (_day > mdays(_month, _year)){
			*this = Date();
			errCode(DAY_ERROR);
		}
		istr.clear();

		return istr;
	}

	// This query writes the date to an std::ostream object in the following format: YYYY/MM/DD
	std::ostream& Date::write(std::ostream& ostr) const {

		char slash = '/';
		char leadingZero = '0';
		ostr << _year << slash;
		if (_month < 10){
			ostr << leadingZero << _month << slash;
			if (_day < 10){
				ostr << leadingZero << _day;
			} else {
				ostr << _day;
			}
		} else {
			ostr << _month << slash;
			if (_day < 10){
				ostr << leadingZero << _day;
			} else {
				ostr << _day;
			}
		}
		return ostr;
	}

	// This operator works with an std::istream object to read a date from the console
	std::istream& operator>>(std::istream& istr, Date& date){
		return date.read(istr);
	}

	// This operator works with an std::ostream object to print a date to the console
	std::ostream& operator<<(std::ostream& ostr, Date& date){
		return date.write(ostr);
	}
}