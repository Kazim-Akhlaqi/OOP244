/**********************************************************
// OOP244 Workshop 5: Operator Overloading
// file Fraction.h
// Version: at_home
// Date Jun/19/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

// TODO: header file guard
#ifndef SICT_FRACTION_H_
#define SICT_FRACTION_H_

// TODO: create namespace
namespace sict {

// TODO: define the Fraction class
class Fraction {

private:

	// TODO: declare instance variables 
	int _numerator;
	int _denominator;

	// TODO: declare private member functions

	// private query that returns the greater of the numerator
	// and denominator
	int max() const;

	// a private query that returns the lesser of the numerator
	// and denom-inator
	int min() const;

	// a private modifier that reduces the numerator and denominator
	// by dividing each by their greatest common divisor
	void reduce();

	// a private query that returns the greatest common divisor of
	// the numerator and denominator 
	int gcd() const;

public:
	// TODO: declare public member functions

	// this constructor sets the object to a safe empty state
	Fraction();

	// receives the numerator and denominator of a fraction,
	//validates the data received and stores that data only 
	// if it is valid.  
	Fraction(int numerator, int denominator);

	// returns true if the object is in
	// a safe empty state; false otherwise
	bool isEmpty() const;

	// sends the fraction to standard output
	void display() const;

	// TODO: declare the operators overload
	Fraction operator+(const Fraction& rhs) const;
	Fraction operator*(Fraction& rhs) const;
	bool operator==(Fraction& rhs) const;
	bool operator!=(Fraction& rhs) const;
	Fraction operator+=(Fraction& rhs);
};
};
#endif