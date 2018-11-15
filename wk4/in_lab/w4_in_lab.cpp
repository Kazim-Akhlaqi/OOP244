/**********************************************************
// OOP244 Workshop 4: Constructors
// file w4_in_lab.cpp
// Version: in_lab
// Date Jun/7/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description: Code for this file is porvided by Instructor
***********************************************************/

#include <iostream>
#include "Passenger.h"
#include "Passenger.h" // this is intentional

using namespace std;
using namespace sict;

int main() {
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto"),
		Passenger("", "Toronto"),
		Passenger("John Smith", nullptr),
		Passenger("John Smith", ""),
		Passenger("John Smith", "Toronto"), // valid
		Passenger(nullptr, nullptr),
		Passenger()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only passenger 5 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << "Passenger " << i + 1 << ": " << (travellers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	Passenger vanessa("Vanessa", "Paris"),
		mike("Mike", "Tokyo"),
		alice("Alice", "Paris");

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	travellers[0].display();
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
