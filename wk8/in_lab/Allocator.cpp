/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: in_lab
// Date July/19/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	 double _interestRate = 0.05;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* accountType, double initalAccountBalance) {
		
		iAccount *nullPointer = nullptr;

		if (accountType[0] == 'S') {
			nullPointer = new SavingsAccount(initalAccountBalance, _interestRate);
		}
		return nullPointer;
	}
}