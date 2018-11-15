/*
--------------------
Student Full_Name: Kazim Akhlaqi
Student_ID: 103638177
Stdent Email: kakhlaqi@myseneca.ca
Section: OOP244-SAB
Assignment: Workshop 1 - in_lab - tools.cpp
-------------------
*/

#include <iostream>
using namespace std;
#include "tools.h"
// displays the user interface menu
int menu() {
	cout << "1- Number of Samples" << endl;
	cout << "2- Sample Entry" << endl;
	cout << "3- Draw Graph" << endl;
	cout << "0- Exit" << endl;
	cout << "> ";
	return getInt(0, 3);
}

// Performs a fool-proof integer entry
int getInt(int min, int max) {
	int val;
	bool done = false;
	while (!done) {
		cin >> val;
		if (cin.fail()) {
			cin.clear();
			cout << "Invalid Integer, try again: ";
		}
		else {
			if (val < min || val > max) {
				cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
			}
			else {
				done = true;
			}
		}
		cin.ignore(1000, '\n');
	}
	return val;
}
