/**********************************************************
// OOP244 Workshop 9: Function Templates 
// File: Data.h
// Version: in_lab
// Date July/26/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description:
***********************************************************/
#include <string.h>
#ifndef SICT_DATA_H_
#define SICT_DATA_H_


namespace sict {

	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	//const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	//const int SMALLEST_NUMBER = 0;
	const int DATA_FIELD_WIDTH = 15;
	const int RECORD_DESC_FIELD_WIDTH = 20;


	// max returns the largest item in data
	template<typename T>
	T max(const T* data, int n){
		T max = data[0];

		int i = 1;
		while (i < n){
			if (max < data[i]) 
				max = data[i];
			i++;
		}
		return max;
	}

	// min returns the smallest item in data
	template<typename T>
	T min(const T* data, int n){

		T min = data[0];

		int i = 1;
		while (i < n){
			if (min > data[i])
				min = data[i];
			i++;
		}
		return min;
	}

	// sum returns the sum of n items in data
	template<typename T>
	T sum(const T* data, int n){

		T sum = 0;

		int i = 0;
		while (i < n){
			sum += data[i];
			i++;
		}
		return sum;
	}

	// average returns the average of n items in data
	template<typename T>
	double average(const T* data, int n){
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template<typename T>
	bool read(std::istream& input, T* data, int n){

		int i = 0;
		while(i < n){
			input.ignore();
			input >> data[i];
			if (input.fail()){
				return false;
			}
			i++;
		}
		return true;
	}

	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char* name, const T* data, int n){

		std::cout.width(RECORD_DESC_FIELD_WIDTH);
		std::cout << std::right << name;

		int i = 0;
		while(i < n){
			std::cout.width(DATA_FIELD_WIDTH);
			std::cout << data[i];
			i++;
		}
		std::cout << "\n";
	}

	//readRow function
	template<typename T>
	T readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	//answers function
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}
#endif