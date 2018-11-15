/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: at_home
// Date July/22/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double initialAccountBalance, double transactionFee, double monthEndFee) : Account(initialAccountBalance) {
		if (transactionFee > 0) {
			_transactionFee = transactionFee;
		}
		else {
			_transactionFee = 0.0;
		}

		if (monthEndFee > 0) {
			_monthEndFee = monthEndFee;
		}
		else {
			_monthEndFee = 0.0;
		}
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double creditedAmount) {
		Account::debit(_transactionFee);
		return Account::credit(creditedAmount);
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double debitedAmount) {
		return Account::debit(debitedAmount + _transactionFee);
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		Account::debit(_monthEndFee + _transactionFee);
	}

	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream& outPut) const {
		outPut << "Account type: Chequing" << std::endl;
		outPut.unsetf(std::ios::floatfield); outPut.precision(2);
		outPut.setf(std::ios::fixed, std::ios::floatfield);
		outPut << "Balance: $" << balance() << std::endl;
		outPut << "Per Transaction Fee: " << _transactionFee << std::endl;
		outPut << "Monthly Fee: " << _monthEndFee << std::endl;
	}
}