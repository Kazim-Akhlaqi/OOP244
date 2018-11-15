// OOP244 Final Project Milestone 5
// file Perishable.cpp
// Version: 1.0
// Date August/2/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Perishable.h"

using namespace std;

namespace AMA {

	Perishable::Perishable() : Product('P') {
		_productErrorState.clear();
	}

	std::fstream& Perishable::store(std::fstream & file, bool newLine) const {
		Product::store(file, false);
		file << ',' << _perishableExpiryDate << endl;
		return file;
	}

	std::fstream& Perishable::load(std::fstream & file) {

		Product::load(file);

		_perishableExpiryDate.read(file);

		file.ignore();

		return file;
	}


	std::ostream& Perishable::write(std::ostream & os, bool linear) const {
		Product::write(os, linear);

		if (isClear() && !isEmpty()) {
			if (linear) {
				_perishableExpiryDate.write(os);
			}
			else {
				os << "\n Expiry date: ";
				_perishableExpiryDate.write(os);
			}
		}
		return os;
	}


	std::istream& Perishable::read(std::istream & is) {
		is.clear();
		Product::read(is);

		if (_productErrorState.isClear()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			_perishableExpiryDate.read(is);
		}

		if (_perishableExpiryDate.errCode() == CIN_FAILED) {
			_productErrorState.clear();
			_productErrorState.message("Invalid Date Entry");
		}

		if (_perishableExpiryDate.errCode() == YEAR_ERROR) {
			_productErrorState.message("Invalid Year in Date Entry");
		}

		if (_perishableExpiryDate.errCode() == MON_ERROR) {
			_productErrorState.clear();
			_productErrorState.message("Invalid Month in Date Entry");
		}

		if (_perishableExpiryDate.errCode() == DAY_ERROR) {
			_productErrorState.clear();
			_productErrorState.message("Invalid Day in Date Entry");
		}

		if (_perishableExpiryDate.errCode()) {
			is.setstate(std::ios::failbit);
		}

		if (_perishableExpiryDate.errCode() != CIN_FAILED
			&& _perishableExpiryDate.errCode() != YEAR_ERROR
			&& _perishableExpiryDate.errCode() != MON_ERROR
			&& _perishableExpiryDate.errCode() != DAY_ERROR)
			_productErrorState.clear();

		return is;
	}
	const Date& Perishable::expiry() const {
		return _perishableExpiryDate;
	}
}

