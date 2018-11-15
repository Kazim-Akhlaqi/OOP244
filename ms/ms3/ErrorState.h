// OOP244 Final Project Milestone 2
// file ErrorState.h
// Version: 1.0
// Date July/21/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
#ifndef AMA_ERROR_STATE_H
#define AMA_ERROR_STATE_H
using namespace std;

namespace AMA {

	class ErrorState {

		// Private members:
	private:

		//A pointer that holds the address of the message,
		//if any, stored in the current object
		char* _message;

	public:

		//This function receives the address of a C-style
		//null terminated string that holds an error message. 
		explicit ErrorState(const char* errorMessage = nullptr);

		//A deleted copy constructor prevents
		//copying of any ErrorState object.
		ErrorState(const ErrorState& em) = delete;

		//A deleted assignment operator prevents assignment
		//of any ErrorState object to the current object. 
		ErrorState& operator=(const ErrorState& em) = delete;

		//This function de-allocates any memory that
		//has been dynamically allocated by the current object.
		virtual ~ErrorState();

		//This function clears any message stored by the current object
		//and initializes the object to a safe empty state.
		void clear();

		//This query reports returns true if the
		//current object is in a safe empty state.
		bool isClear() const;

		//This function stores a copy of the
		//C-style string pointed to by str.
		void message(const char* str);

		//This query returns the address of the
		//message stored in the current object. 
		const char* message() const;
	};

	//This operator sends an ErrorState message,
	//if one exists, to an std::ostream object and
	//returns a reference to the std::ostream object. 
	//If no message exists, this operator does not send
	//anything to the std::ostream object and returns
	//a reference to the std::ostream object.
	std::ostream& operator<<(std::ostream& os, const ErrorState& errorMessage);
}
#endif 