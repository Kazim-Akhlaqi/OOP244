/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Version: at_home
// Date July/22/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
	
	private:

		double _transactionFee;
		double _monthEndFee;

	public:
		// TODO: constructor initializes account balance and transaction fee
		ChequingAccount(double initialAccountBalance, double transactionFee, double monthEndFee);

		// TODDO: credit adds +ve amount to the balance
		bool credit(double creditedAmount);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double debitedAmount);

		// TODO: month end
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream& outPut) const;
	};
}
#endif