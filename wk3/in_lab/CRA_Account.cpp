/**********************************************************
// OOP244 Workshop 3: Classes and Privacy
// file CRA_Account.cpp
// Version 2.1
// Date May/30/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Section: OOP244 SAB
// Description:
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: include the necessary headers

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

// TODO: the sict namespace

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		// check if sin in valid

		if ( sin >= min_sin && sin <= max_sin ) {
		
			_sin = sin;
			strncpy(_familyName, familyName,max_name_length);
			_familyName[max_name_length] = '\0';
			strncpy(_givenName, givenName, max_name_length);
			_givenName[max_name_length] = '\0';
		}
		else {
			_sin = 0;
		}
	}
	
	bool CRA_Account::isEmpty() const {

		bool valid;

		if (_sin > 0 ) {

			valid = false;
		}
		else {
			valid = true;
		}

		return valid;
	}


	void CRA_Account::display() const {

		if (_sin != 0) {
			cout << "Family Name: " <<  _familyName << endl;
			cout << "Given Name : " << _givenName << endl;
			cout << "CRA Account: " << _sin << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}
