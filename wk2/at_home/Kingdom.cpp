/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May/24/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Section: OOP244 SAB
// Description:
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers

#include <iostream>
using namespace std;
#include "Kingdom.h"

// TODO: the sict namespace

namespace sict {

	// TODO:definition for display(...) 
	void display(const Kingdom* kingdom) {

		cout << kingdom->m_name << ", population " << kingdom->m_population << endl;
	};

	void display(const Kingdom* kingdom, int count) {

		int totalPopulation = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i=0 ; i < count; i++) {

			cout << i + 1 << ". ";
			display(&kingdom[i]);

			totalPopulation += kingdom[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalPopulation << endl;
		cout << "------------------------------" << endl;
	

	};
}
