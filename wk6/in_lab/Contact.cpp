/**********************************************************
// OOP244 Workshop 6: 	Class With Resource
// file Contact.cpp
// Version: in_lab
// Date July/7/2018
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
		bool invalid = contactPhoneNumber <= 0
			|| phoneNumberString.length() < 11
			|| phoneNumberString.length() > 12
			|| phoneNumberString[phoneNumberString.length() - 7] == '0'
			|| phoneNumberString[phoneNumberString.length() - 10] == '0';
		return !invalid;
	}

	// TODO: implement the 3 argument Contact constructor
	Contact::Contact(const char* contactName, const long long* contactPhoneNumbers, int numOfPhoneNumbers) {
		if (contactName != nullptr && contactName[0] != '\0')
		{
			int sizeOf_m_name = (sizeof(_contactName) - 1);
			int parameter_name_length = strlen(contactName);
			int m_name_length = (parameter_name_length > sizeOf_m_name) ? sizeOf_m_name : parameter_name_length;
			for (int i = 0; i < m_name_length; i++)
			{
				_contactName[i] = contactName[i];
			}
			_contactName[m_name_length] = '\0';
		}
		else
		{
			_contactName[0] = '\0';
		}
		if (contactPhoneNumbers != nullptr && numOfPhoneNumbers > 0)
		{
			if (contactPhoneNumbers != nullptr)
			{
				_contactPhoneNumbers = new long long[numOfPhoneNumbers];
				_numOfPhoneNumbers = 0;
				for (int phone = 0; phone < numOfPhoneNumbers; phone++)
				{
					if (isValidPhoneNumber(contactPhoneNumbers[phone]))
					{
						_numOfPhoneNumbers += 1;
						_contactPhoneNumbers[_numOfPhoneNumbers - 1] = contactPhoneNumbers[phone];
					}
				}
			}
		}
		else
		{
			_contactPhoneNumbers = nullptr;
			_numOfPhoneNumbers = 0;
		}
	}

	// TODO: implement the Contact destructor
	Contact::~Contact() {
		delete[] _contactPhoneNumbers;
		_contactPhoneNumbers = nullptr;
	}


	// TODO: implement the isEmpty query
	bool Contact::isEmpty() const
	{
		return (_contactName[0] == '\0' && _contactPhoneNumbers == nullptr && _numOfPhoneNumbers == 0) ? true : false;
	}

	// TODO: implement the display query
	void Contact::display() const
	{
		string countryCode;
		string areaCode;
		string numberCode1;
		string numberCode2;
		string phoneNumberString;
		int phoneNumberStringLength;
		if (!isEmpty())
		{

			cout << _contactName << endl;
			for (int phone = 0; phone < _numOfPhoneNumbers; phone++)
			{
				phoneNumberString = to_string(_contactPhoneNumbers[phone]);
				phoneNumberStringLength = phoneNumberString.length();
				countryCode = phoneNumberString.substr(0, (phoneNumberStringLength - (areaCodeLength + numberLength)));
				areaCode = phoneNumberString.substr(phoneNumberStringLength - (areaCodeLength + numberLength), areaCodeLength);
				numberCode1 = phoneNumberString.substr(phoneNumberStringLength - numberLength, numberCode1Length);
				numberCode2 = phoneNumberString.substr(phoneNumberStringLength - numberCode2Length, numberCode2Length);

				cout << "(+" + countryCode + ")" + " " + areaCode + " " + numberCode1 + "-" + numberCode2 << endl;
			}
		}
		else
		{
			cout << "Empty contact!" << endl;
		}
	}
}