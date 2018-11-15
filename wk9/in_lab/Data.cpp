/**********************************************************
// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: in_lab
// Date July/26/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/
#include <iostream>
#include <cstring>
#include "Data.h"

using namespace std;

namespace sict {
	// answers outputs statistics for visual validation of data
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int populationChange = population[n - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.precision(2);
		cout.setf(ios::fixed);
		double currentPopulation = static_cast<double>(populationChange) / 1000000;
		cout << currentPopulation << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		auto violentCrimeStart = violentCrime[0];
		auto violentCrimeFinish = violentCrime[n - 1];
		const char* violentCrimeStatus = "\0";
		if (violentCrimeStart < violentCrimeFinish) {
			violentCrimeStatus = "up";
		}
		else {
			violentCrimeStatus = "down";
		}
		cout << "Violent Crime trend is " << violentCrimeStatus << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		double gta = average(grandTheftAuto, n);
		cout.precision(2);
		cout << "There are " << fixed << gta / 1.0E6 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
	}
}