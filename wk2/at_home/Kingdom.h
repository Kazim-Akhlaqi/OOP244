/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace

namespace sict {

	// TODO: define the structure Kingdom in the sict namespace

	struct Kingdom {

		int m_population;

		char m_name[33];
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom*);
	void display(const Kingdom*, int count);

}

#endif
