/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.h
// Version: in_lab
// Date July/19/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {
	private :

	double _interestRate;

	public:
	// TODO: constructor initializes balance and interest rate
	SavingsAccount(double initialAccountBalance, double interestRate);

	// TODO: perform month end transactions
	void monthEnd();

	// TODO: display inserts the account information into an ostream			
	void display(std::ostream& outPut) const;
};
}
#endif