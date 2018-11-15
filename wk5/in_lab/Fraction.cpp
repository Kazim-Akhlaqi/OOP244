/**********************************************************
// OOP244 Workshop 5: Operator Overloading
// file Fraction.cpp
// Version: in_lab
// Date Jun/14/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
#define _CRT_SECURE_NO_WARNINGS

	// TODO: continue the namespace
using namespace std;
namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {
		_numerator = 0;
		_denominator = -1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator){
		if (numerator >= 0 && denominator >= 0) {
			_numerator = numerator;
			_denominator = denominator;
			reduce();
		}
		else {
			_numerator = 0;
			_denominator = -1;

		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		if (_numerator > _denominator) {
			return _numerator;
		}
		else {
			return _denominator;
		}
	}

	// TODO: implement the min query
	int Fraction::min() const {
		if (_numerator > _denominator) {
			return _denominator;
		}
		else {
			return _numerator;
		}
	}

	// This function is provided by Instructor
	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int _gcd = gcd();
		_numerator = _numerator/_gcd;
		_denominator = _denominator/_gcd;
	}

	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (_denominator == 1) {
				cout << _numerator;
			}
		else {
				cout << _numerator << "/" << _denominator;
			}
		}
	

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool empty;
		if (_denominator == -1) {
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
	Fraction Result;
		if (!(isEmpty() || rhs.isEmpty())) {
			Result._numerator = _denominator * rhs._numerator + _numerator * rhs._denominator;
			Result._denominator = _denominator * rhs._denominator;
		}
		return Result;
	}
}