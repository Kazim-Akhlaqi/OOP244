/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: at_home
// Date July/22/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account : public iAccount {

	private:
		// holds current balance of the account
		double _currentBalance;

	protected:

		//returns the current balance of the account
		double balance() const;

	public:

		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double initialAccountBalance);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double creditedAmount);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double debitedAmount);
	};
}
#endif