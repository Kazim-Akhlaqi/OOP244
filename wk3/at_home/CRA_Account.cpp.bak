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
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// TODO: the sict namespace

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (isValid(sin) && familyName != nullptr && familyName[0] != '\0' && givenName != nullptr && givenName[0] != '\0') {

			strncpy(_familyName, familyName, max_name_length);
			strncpy(_givenName, givenName, max_name_length);
			_sin = sin;
			_taxRtnYrsNum = 0;
		}
		else {
			_familyName[max_name_length] = '\0';
			_givenName[max_name_length] = '\0';
			_sin = 0;
			_taxRtnYrsNum = 0;
		}
	}


	bool CRA_Account::isValid(int sin) const {
		int sum = 0;
		int evens[4] = { 
			(((sin / 10) % 10) * 2),
			(((sin / 1000) % 10) * 2),
			(((sin / 100000) % 10) * 2),
			(((sin / 10000000) % 10) * 2) };
		int odds[4] = { 
			(((sin / 100) % 10)),
			(((sin / 10000) % 10)),
			(((sin / 1000000) % 10)),
			(((sin / 100000000) % 10)) };

		for (int i = 0; i < 4; i++)
		{
			sum += ((((evens[i] / 1) % 10) + ((evens[i] / 10) % 10)));
			sum += odds[i];
		}

		int wholeNum = ((sum + 9) / 10) * 10;

		if (((wholeNum - sum) == (sin / 1) % 10) && sin >= min_sin && sin <= max_sin)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}

	void CRA_Account::set(int year, double balance) {
		if (isValid(_sin)) {
			_taxRtnYrs[_taxRtnYrsNum] = year;
			_taxBlnc[_taxRtnYrsNum] = balance;
			_taxRtnYrsNum++;
		}
	}

	bool CRA_Account::isEmpty() const {


		bool empty;

		if (_sin < min_sin || _sin > max_sin || _familyName[0] == '\0' || _givenName[0] == '\0') {

			empty = true;
		}
		else {
			empty = false;
		}

		return empty;
	}

	void CRA_Account::display() const {

		if (_sin >= 0) {
			cout << "Family Name: " << _familyName << endl;
			cout << "Given Name : " << _givenName << endl;
			cout << "CRA Account: " << _sin << endl;
			if (!isEmpty()) {
				for (int i = 0; i < _taxRtnYrsNum; i++) {
					if (_taxBlnc[i] > 2) {
						printf("Year (%d) balance owing: %.2lf\n", _taxRtnYrs[i], _taxBlnc[i]);
					}
					else if (_taxBlnc[i] < -2) {
						printf("Year (%d) refund due: %.2lf\n", _taxRtnYrs[i], -(_taxBlnc[i]));
					}
					else {
						cout << "Year (" << _taxRtnYrs[i] << ") No balance owing or refund due!" << endl;
					}
				}
			}
			else {
				cout << "Account object is empty!" << endl;
			}
		}
	}
}
