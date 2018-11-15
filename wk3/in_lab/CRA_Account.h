/***********************************************************
// OOP244 Workshop 3: Classes and Privacy
// File CRA_Account.h
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

// TODO: header safeguards

#ifndef SICT_CRA_Account_H
#define SICT_CRA_Account_H

// TODO: sict namespace

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {

		char _familyName[max_name_length + 1];
		char _givenName[max_name_length + 1];
		int _sin;
		
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}

#endif
