// OOP244 Final Project Milestone 5
// file Perishable.h
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
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include "Date.h"
#include "Product.h"
#include <iostream>

namespace AMA {

	class Perishable : public Product {

		Date _perishableExpiryDate;

	public:

		// No argument Constructor 
		Perishable();

		// This query receives a reference to an fstream object and an optional bool
		// and returns a reference to the modified fstream object.
		// This function stores a single file record for the current object.
		std::fstream& store(std::fstream& file, bool newLine = true) const;

		// This modifier receives a reference to an fstream object and returns
		// a reference to that fstream object.This function extracts the
		// data fields for a single file record from the fstream object.
		std::fstream& load(std::fstream& file);

		// This query receives a reference to an ostream object and a bool flag
		// and returns a reference to the modified ostream object.
		// The flag identifies the output format. 
		std::ostream& write(std::ostream& os, bool linear) const;

		// This modifier receives a reference to an istream object and returns
		// a reference to the modified istream object.This function populates
		// the current object with the data extracted from the istream object.
		std::istream& read(std::istream& is);

		// This query returns the expiry date for the perishable product.
		const Date& expiry() const;
	};
}
#endif 



