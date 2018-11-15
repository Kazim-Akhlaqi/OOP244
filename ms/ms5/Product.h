// OOP244 Final Project Milestone 3
// file Product.h
// Version: 1.0
// Date July/24/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP244 SAB
// Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "iProduct.h"
#include "ErrorState.h"

namespace AMA {

	// Pre-defined constants:

	// Maximum number of characters in a sku (stock keeping unit). 
	const int SKU_MAX_CHAR = 7;
	const int max_sku_length = SKU_MAX_CHAR;

	// Maximum number of characters in the units’ descriptor for a product.
	const int UNIT_MAX_CHAR = 10;
	const int max_unit_length = UNIT_MAX_CHAR;

	// Maximum number of characters in the user’s name descriptor for a product length.
	const int USER_NAME_MAX_CHAR = 75;
	const int max_name_length = USER_NAME_MAX_CHAR;

	// The current tax rate
	const double TAX_RATE = 0.13;

	// Product class 

	class Product : public iProduct {

		// Private data members:

	private:

		char _productType;
		char _productSku[SKU_MAX_CHAR + 1];      // Product’s sku array (stock keeping unit) 
		char _productUnit[UNIT_MAX_CHAR + 1];// Product’s unit discription array
		char* _productName;                                      // Product Name
		int _productQtyInStock;                      // Number of product in stock
		int _productQtyInNeed;                       // Number of product in need
		double _productSalePricePerUnit;     // Product Sale Price (before Tax) per unit
		bool _productTaxable;                            // This bool retruns true if the product is taxable

			// Protected member functions:

	protected:
		ErrorState _productErrorState;           // An ErrorState object that holds the error state of the Product object

												 // This function receives the address of a C-style null-terminated string that holds the name of the product
		void name(const char* productName);

		// This query returns the address of the C - style string that holds the name of the product.
		// If the product has no name, this query returns nullptr.
		const char* name() const;

		// This query returns the address of the C-style string that holds the sku of the product. 
		const char* sku() const;

		// This query returns the address of the C-style string that holds the unit of the product. 
		const char* unit() const;

		// This query returns the taxable status of the product.
		bool taxed() const;

		// This query returns the price of a single item of the product. 
		double price() const;

		// This query returns the price of a single item of the product plus any tax that applies to the product.
		double cost() const;

		// This function receives the address of a C-style null-terminated string holding an error message
		// and stores that message in the ErrorState object. 
		void message(const char*);

		// This query returns true if the ErrorState object is clear; false otherwise.
		bool isClear() const;

		// Public member functions:

	public:

		// This constructor optionally receives a character that identifies the product type. The default value is ‘N’. 
		Product(char productType = 'N');

		// This constructor receives seven parameters in following order declared here
		Product(const char* productSku, const char* productName, const char * productUnit, int productQtyInStock = 0, bool productTaxable = true, double productSalePricePerUnit = 0.0, int productQtyInNeed = 0);

		// This constructor receives an unmodifiable reference to a Product object
		// and copies the object referenced to the current object. 
		Product(const Product& object);

		// This operator receives an unmodifiable reference to a Product object
		// and replaces the current object with a copy of the object referenced. 
		Product& operator=(const Product& object);

		// This function deallocates any memory that has been dynamically allocated.
		~Product();

		// This query receives a reference to an fstream object and an optional bool
		// and returns a reference to the fstream object. 
		std::fstream& store(std::fstream& file, bool newLine = true) const;

		// This modifier receives a reference to an fstream object and
		// returns a reference to that fstream object. 
		std::fstream& load(std::fstream& file);

		// This query receives a reference to an ostream object and a bool and
		// returns a reference to the ostream object. 
		std::ostream& write(std::ostream& os, bool linear) const;

		// This modifier receives a reference to an istream object and
		// returns a reference to the istream object. 
		std::istream& read(std::istream& is);

		// This query receives the address of an unmodifiable C-style null-terminated string and
		// returns true if the string is identical to the sku of the current object; false otherwise.
		bool operator==(const char* productSku) const;

		// This query that returns the total cost of all items of the product on hand, taxes included.
		double total_cost() const;
				
		// This query returns true if the object is in a safe empty state; false otherwise.
		bool isEmpty() const;

		// This query that returns the number of units of the product that are needed.
		int qtyNeeded() const;

		// This query returns the number of units of the product that are on hand.
		int quantity() const;

		// This query receives the address of a C - style null - terminated string
		// holding a product sku and returns true if the sku of the current object
		// is greater than the string stored at the received address; false otherwise.
		bool operator>(const char* productSku) const;

		// This query receives an unmodifiable reference to a Product object and
		// returns true if the name of the current object is greater than
		// the name of the referenced Product object; false otherwise.
		bool
			
			operator>(const iProduct& productName) const;

		// This modifier receives an integer identifying the number of units
		// to be added to the Product and returns the updated number of units on hand. 
		int operator+=(int unitsAdded);

		// This modifier that receives an integer holding the number of units of the Product that are on hand.
		// This function resets the number of units that are on hand to the number received.
		// setter function

		void quantity(int productQuantity);

		void setPrice(double tempProductSalePricePerUnit);

		void setQtyNeed(int tempProductQtyInNeed);
	};

	// The following helper functions support the Product class:

	// This helper receives a reference to an ostream object and
	// an unmodifiable reference to a Product object and
	// returns a reference to the ostream object. 
	std::ostream& operator<<(std::ostream& os, const iProduct& object);

	// This helper receives a reference to an istream object and
	// a reference to a Product object and returns a reference to the istream object. 
	std::istream& operator>>(std::istream& is, iProduct& object);

	// This helper receives a reference to a double and
	// an unmodifiable reference to a Product object and returns a double.
	double operator+=(double& cost, const iProduct& object);
}
#endif

