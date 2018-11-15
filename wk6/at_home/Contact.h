/**********************************************************
// OOP244 Workshop 6: Class With Resource
// file Contact.h
// Version: at_home
// Date July/9/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/
// TODO: header file guard
#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_

// TODO: add namespace here
namespace sict {
	const int areaCodeLength = 3;
	const int numberLength = 7;
	const int numberCode1Length = 3;
	const int numberCode2Length = 4;

	// TODO: define the Contact class
	class Contact {

	private:
		char _contactName[20];
		long long* _contactPhoneNumbers;
		int _numOfPhoneNumbers;

		// TODO: phone number validation
		bool isValidPhoneNumber(const long long contactPhoneNumbers);

	public:
		// TODO: add the default constructor here
		// this constructor sets the current object to a safe empty state
		Contact();

		// TODO: add the constructor with 3 parameters here
		// This constructor receives the address of
		// an unmodifiable C-style string that holds
		// the name of the contact, the address of
		// an unmodifiable array of phone numbers and
		// the number of phone numbers stored in the array
		Contact(const char* contactName, const long long* contactPhoneNumbers, int numOfPhoneNumbers);

		// TODO: add the destructor here
		// the destructor deallocates any memory
		// that has been allocated dynamically; 
		~Contact();

		//this constructor makes a copy of an existing instance
		Contact(const Contact& copy);

		//this operator receives an unmodifiable reference
		//to a Contact object and copies the content of 
		//that object into the current object and returns
		//a reference to the current object, as updated
		Contact& operator=(const Contact& rhs);

		//this operator receives a new phone number
		//as its parameter, validates the number received
		//and, if valid, resizes the phone number array
		//to hold all of the existing numbers plus the
		//received one and finally adds this new number
		//to the array
		Contact& operator+=(long long newPhoneNumber);


		// TODO: add the display function here
		// This query returns false if 
		// the current object has valid data;
		// true if the object is in a safe empty state
		bool isEmpty() const;

		// TODO: add the isEmpty function here
		// This query prints the data stored by the object 
		void display() const;
	};
}
#endif
