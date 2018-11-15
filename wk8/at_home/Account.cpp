/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: at_home
// Date July/22/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {

	// TODO: constructor initializes account balance, defaults to 0.0 
	Account::Account(double initialAccountBalance) {
		if (initialAccountBalance > 0) {
			_currentBalance = initialAccountBalance;
		}
		else if (initialAccountBalance >= 0) {
			_currentBalance = 0.0;
		}
	}

	// TODO: credit adds +ve amount to the balance 
	bool Account::credit(double creditedAmount) {
		if (creditedAmount > 0) {
			_currentBalance += creditedAmount;
			return true;
		}
		else {
			return _currentBalance;
		}
	}

	// TODO: debit subtracts a +ve amount from the balance
	bool Account::debit(double debitedAmount) {
		if (debitedAmount > 0) {
			_currentBalance -= debitedAmount;
			return true;
		}
		else {
			return _currentBalance;
		}
	}

	//returns the current balance of the account
	double Account::balance() const {
		return _currentBalance;
	}
}
