/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: at_home
// Date July/22/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate, transaction Fee, monthly Fee
	const double _interestRate = 0.05;
	const double _transactionFee = 0.50;
	const double _monthlyFee = 2.00;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* accountType, double initalAccountBalance) {

		iAccount *nullPointer = nullptr;

		if (accountType[0] == 'S') {
			nullPointer = new SavingsAccount(initalAccountBalance, _interestRate);
		}
		else if (accountType[0] == 'C') {
			nullPointer = new ChequingAccount(initalAccountBalance, _transactionFee, _monthlyFee);
		}
		return nullPointer;
	}
}