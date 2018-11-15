/**********************************************************
// OOP244 Workshop 6: 	Class With Resource
// file Contact.cpp
// Version: at_home
// Date July/9/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/

// TODO: insert header files
#include <iostream>
#include <cstring>
#include <string>
#include "Contact.h"
//#define _CRT_SECURE_NO_WARNINGS

// TODO: continue the namespace
using namespace std;

namespace sict {

	// TODO: implement the default Contact constructor
	Contact::Contact() {
		_contactName[0] = '\0';
		_contactPhoneNumbers = nullptr;
		_numOfPhoneNumbers = 0;
	}

	// TODO: phone number validation
	bool Contact::isValidPhoneNumber(const long long contactPhoneNumber) {

		string phoneNumberString = to_string(contactPhoneNumber);

		bool validPhoneNumber;
		if (contactPhoneNumber <= 0
			|| phoneNumberString.length() < 11
			|| phoneNumberString.length() > 12
			|| phoneNumberString[phoneNumberString.length() - 7] == '0'
			|| phoneNumberString[phoneNumberString.length() - 10] == '0') {

			validPhoneNumber = false;
		} 
		else {
			validPhoneNumber = true;
		}
		return validPhoneNumber;
	}

	// TODO: implement the 3 argument Contact constructor
	Contact::Contact(const char* contactName, const long long* contactPhoneNumbers, int numOfPhoneNumbers) {

		if (contactName != nullptr && contactName[0] != '\0'){

			strcpy(_contactName, contactName);

			_contactPhoneNumbers = new long long[numOfPhoneNumbers];

			_numOfPhoneNumbers = 0;

			for (int i = 0; i < numOfPhoneNumbers; i++) {

				if (isValidPhoneNumber(contactPhoneNumbers[i])){
					_numOfPhoneNumbers += 1;
					_contactPhoneNumbers[_numOfPhoneNumbers - 1] = contactPhoneNumbers[i];
				}
				else{
					_contactPhoneNumbers[i] = 0;
				}
			}
		}
		else
		{
			*this = Contact();
		}
	}

	// TODO: implement the Contact destructor
	Contact::~Contact() {
		if (_contactPhoneNumbers != nullptr){

			delete[] _contactPhoneNumbers;

			_contactPhoneNumbers = nullptr;
		}
	}

	// TODO: makes a copy of an existing instance
	Contact::Contact(const Contact& copy) {

		_contactPhoneNumbers = nullptr;

		*this = copy;
	}

	// TODO: copy to current object
	Contact& Contact::operator=(const Contact& rhs){

		if (this != &rhs){

			strcpy(_contactName, rhs._contactName);

			_numOfPhoneNumbers = rhs._numOfPhoneNumbers;

			delete[] _contactPhoneNumbers;

			if (rhs._contactPhoneNumbers != nullptr) {
				_contactPhoneNumbers = new long long[_numOfPhoneNumbers];

				for (int i = 0; i < _numOfPhoneNumbers; i++) {
					_contactPhoneNumbers[i] = rhs._contactPhoneNumbers[i];
				}
			}
			else {
				_contactPhoneNumbers = nullptr;
			}
		}

		return *this;
	}

	// TODO: Add new phone number to phone numbers array if valid
	Contact& Contact::operator+=(long long newPhoneNumber){

		if (isValidPhoneNumber(newPhoneNumber)){

			_numOfPhoneNumbers++;

			long long* _newPhoneNumbers = new long long[_numOfPhoneNumbers];

			for (int i = 0; i < _numOfPhoneNumbers - 1; ++i)
			{
				_newPhoneNumbers[i] = _contactPhoneNumbers[i];
			}

			_newPhoneNumbers[_numOfPhoneNumbers - 1] = newPhoneNumber;

			delete[] _contactPhoneNumbers;

			_contactPhoneNumbers = _newPhoneNumbers;
		}

		return *this;
	}

	// TODO: implement the isEmpty query
	bool Contact::isEmpty() const {

		bool valid;

		if (_contactName[0] == '\0' && _contactPhoneNumbers == nullptr && _numOfPhoneNumbers == 0){
			valid = true;
		}
		else {
			valid = false;
		}
		return valid;
	}

	// TODO: implement the display query
	void Contact::display() const {

		int phoneNumberSize;
		int areaCodeSize = 3;
		int prefixAndLineSize = 7;
		int prefixNumSize = 3;
		int lineNumSize = 4;
		string phoneNumber;
		string countryCode;
		string areaCode;
		string prefixNumber;
		string lineNumber;

		if (!isEmpty()){

			cout << _contactName << endl;

			for (int i = 0; i < _numOfPhoneNumbers; i++) {

				phoneNumber = to_string(_contactPhoneNumbers[i]);

				phoneNumberSize = phoneNumber.length();

				countryCode = phoneNumber.substr(0, (phoneNumberSize - (areaCodeSize + prefixAndLineSize)));

				areaCode = phoneNumber.substr(phoneNumberSize - (areaCodeSize + prefixAndLineSize), areaCodeSize);

				prefixNumber = phoneNumber.substr(phoneNumberSize - prefixAndLineSize, prefixNumSize);

				lineNumber = phoneNumber.substr(phoneNumberSize - lineNumSize, lineNumSize);

				cout << "(+" + countryCode + ")" + " " + areaCode + " " + prefixNumber + "-" + lineNumber << endl;
			}
		}
		else {
			cout << "Empty contact!" << endl;
		}
	}
}