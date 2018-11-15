/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: at_home
// Date July/22/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

#include <iostream>
#include "SavingsAccount.h"

namespace sict {

	// TODO: constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double initialAccountBalance, double interestRate) : Account(initialAccountBalance) {
		if (interestRate > 0) {
			_interestRate = interestRate;
		}
		else {
			_interestRate = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {
		double Earnedinterest = (balance() * _interestRate);
		credit(Earnedinterest);
	}

	void SavingsAccount::display(std::ostream& outPut) const {

		outPut << "Account type: Savings" << std::endl;
		outPut.unsetf(std::ios::floatfield); outPut.precision(2);
		outPut.setf(std::ios::fixed, std::ios::floatfield);
		outPut << "Balance: $" << balance() << std::endl;
		outPut << "Interest Rate (%): " << _interestRate * 100 << std::endl;
	}

}