// OOP244 Final Project Milestone 2
// file ErrorState.cpp
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

#include "ErrorState.h"

using namespace std;

namespace AMA {

	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			_message = nullptr;
		}
		else {
			_message = new char[strlen(errorMessage) + 1];
			strcpy(_message, errorMessage);
			_message[strlen(errorMessage)] = '\0';
		}
	}

	ErrorState::~ErrorState() {
		delete[] this->_message;
		_message = nullptr;
	}

	void ErrorState::clear() {
		delete[] _message;
		_message = nullptr;
	}

	bool ErrorState::isClear() const {
		if (_message == nullptr) {
			return true;
		} else
		return false;
	}

	void ErrorState::message(const char* str) {
		delete[] _message;
		_message = nullptr;
		_message = new char[strlen(str) + 1];
		strcpy(_message, str);
		_message[strlen(str)] = '\0';
	}

	const char* ErrorState::message() const {
		return _message;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& errorMessage) {
		if (!(errorMessage.isClear())) {
			os << errorMessage.message();
		}
		return os;
	}
}