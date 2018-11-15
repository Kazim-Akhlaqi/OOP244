// OOP244 Final Project Milestone 3
// file Product.cpp
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

#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"
#include "Product.h"
//#include "ErrorState.h"

using namespace std;
using namespace AMA;

namespace AMA {

	// Protected member functions definition:

	void Product::name(const char *productName) {
		if (productName != nullptr) {
			int productNameLength = strlen(productName);
			_productName = new char[productNameLength + 1];
			for (int i = 0; i < productNameLength; i++) {
				_productName[i] = productName[i];
			}
			_productName[productNameLength] = '\0';
		}
		else
			_productName = nullptr;
	}

	void Product::quantity(int productQuantity) {
		_productQtyInStock = productQuantity;
	}

	const char *Product::name() const {
		if (_productName[0] == '\0')
			return nullptr;
		else
			return _productName;
	}

	const char *Product::sku() const {
		return _productSku;
	}

	const char *Product::unit() const {
		return _productUnit;
	}

	bool Product::taxed() const {
		return _productTaxable;
	}

	double Product::price() const {
		return _productSalePricePerUnit;
	}
	void Product::setQtyNeed(int tempProductQtyInNeed) {

		_productQtyInNeed = tempProductQtyInNeed;

	}

	void Product::setPrice(double tempProductSalePricePerUnit) {

		_productSalePricePerUnit = tempProductSalePricePerUnit;

	}

	double Product::cost() const {
		if (_productTaxable == true) 
			return price() * (TAX_RATE + 1);
		else
			return price();
	}

	void Product::message(const char *errorMessage) {
		_productErrorState.message(errorMessage);
	}

	bool Product::isClear() const {
		return _productErrorState.isClear();
	}

	// Public member functions definition:

	Product::Product(char productType) {
		_productType = productType;
		_productSku[0] = '\0';
		_productUnit[0] = '\0';
		_productName = nullptr;
		_productQtyInStock = 0;
		_productQtyInNeed = 0;
		_productSalePricePerUnit = 0.0;
		_productTaxable = false;
	}

	Product::Product(const char* productSku, const char* productName, const char * productUnit, int productQtyInStock, bool productTaxable, double productSalePricePerUnit, int productQtyInNeed) {
		name(productName);

		strncpy(_productSku, productSku, SKU_MAX_CHAR);
		_productSku[SKU_MAX_CHAR] = '\0';

		strncpy(_productUnit, productUnit, UNIT_MAX_CHAR);
		_productUnit[UNIT_MAX_CHAR] = '\0';

		_productQtyInStock = productQtyInStock;
		_productQtyInNeed = productQtyInNeed;
		_productSalePricePerUnit = productSalePricePerUnit;
		_productTaxable = productTaxable;
	}

	Product::Product(const Product& object) {

		_productType = object._productType;

		strncpy(_productSku, object._productSku, SKU_MAX_CHAR);
		_productSku[SKU_MAX_CHAR] = '\0';

		strncpy(_productUnit, object._productUnit, UNIT_MAX_CHAR);
		_productUnit[UNIT_MAX_CHAR] = '\0';

		_productQtyInStock = object._productQtyInStock;
		_productQtyInNeed = object._productQtyInNeed;
		_productTaxable = object._productTaxable;
		_productSalePricePerUnit = object._productSalePricePerUnit;

		int productNameLength = strlen(object._productName);

		if (object._productName != nullptr) {
			_productName = nullptr;
			_productName = new char[productNameLength];

			for (int i = 0; i < productNameLength; i++) {
				_productName[i] = object._productName[i];
			}
			_productName[productNameLength] = '\0';
		}
		else
			_productName = nullptr;
	}

	Product &Product::operator=(const Product &object) {
		if (this != &object) {
			_productType = object._productType;

			name(object._productName);
			strncpy(_productSku, object._productSku, strlen(object._productSku));
			_productSku[strlen(object._productSku)] = '\0';

			strncpy(_productUnit, object._productUnit, strlen(object._productUnit));
			_productUnit[strlen(object._productUnit)] = '\0';

			_productQtyInStock = object._productQtyInStock;
			_productQtyInNeed = object._productQtyInNeed;
			_productTaxable = object._productTaxable;
			_productSalePricePerUnit = object._productSalePricePerUnit;
		}
		return *this;
	}

	Product::~Product() {
		delete[] _productName;
	}

	std::fstream &Product::store(std::fstream &file, bool newLine) const {
		file << _productType << ',' 
			<< _productSku << ',' 
			<< _productName << ','
			<< _productUnit << ',' 
			<< _productTaxable << ","
			<< _productSalePricePerUnit << ","
			<< _productQtyInStock << ','
			<< _productQtyInNeed;

		if (newLine == true) {
			file << endl;
		}
		return file;
	}


	std::fstream& Product::load(std::fstream& file) {

		Product tempObject;
		char tempTax;
		char tempProductSku[SKU_MAX_CHAR];
		char tempProductUnit[UNIT_MAX_CHAR];
		char tempProductName[USER_NAME_MAX_CHAR];
		int tempProductQtyInStock = 0;
		int	tempProductQtyInNeed = 0;
		double tempProductSalePricePerUnit = 0.0;
		bool tempProductTaxable = false;

		if (file.is_open()) {

			file.getline(tempProductSku, max_sku_length, ',');
			tempProductSku[strlen(tempProductSku)] = '\0';

			file.getline(tempProductName, max_name_length, ',');
			tempProductName[strlen(tempProductName)] = '\0';

			file.getline(tempProductUnit, max_unit_length, ',');
			tempProductUnit[strlen(tempProductUnit)] = '\0';

			file >> tempTax;
			if (tempTax == '1')
				tempProductTaxable = true;
			else if (tempTax == '0')
				tempProductTaxable = false;
			file.ignore();

			file >> tempProductSalePricePerUnit;
			file.ignore();
			file >> tempProductQtyInStock;
			file.ignore();
			file >> tempProductQtyInNeed;
			file.ignore();

			tempObject = Product(tempProductSku, tempProductName, tempProductUnit, tempProductQtyInStock, tempProductTaxable, tempProductSalePricePerUnit, tempProductQtyInNeed);

			*this = tempObject;
		}
		return file;
	}

	std::ostream &Product::write(std::ostream& os, bool linear) const {

		if (!(_productErrorState.isClear())) {
			os << _productErrorState.message();
		}
		else if (linear) {

			os << setw(SKU_MAX_CHAR) << left << setfill(' ') 
				<< _productSku << '|'
				<< setw(20) << left << _productName << '|'
				<< setw(7) << right << fixed << setprecision(2) << cost() << '|'
				<< setw(4) << right << _productQtyInStock << '|'
				<< setw(10) << left << _productUnit << '|'
				<< setw(4) << right << _productQtyInNeed << '|';
		}
		else {
			os << " Sku: " << _productSku << endl
				<< " Name (no spaces): " << _productName << endl
				<< " Price: " << _productSalePricePerUnit << endl;
			if (_productTaxable == true) {
				os << " Price after tax: " << cost() << endl;
			}
			else {
				os << " Price after tax: N/A" << endl;
			}
			os << " Quantity on Hand: " << _productQtyInStock << " " << _productUnit << endl
				<< " Quantity needed: " << _productQtyInNeed;
		}
		return os;
	}

	std::istream &Product::read(std::istream& is) {
		char tempTax;
		char *tempProductName = new char[USER_NAME_MAX_CHAR + 1];
		int tempProductQtyInStock;
		int tempProductQtyInNeed;
		double tempProductSalePricePerUnit;

		if (!is.fail()) {
			cout << " Sku: "; is >> _productSku;
			cout << " Name (no spaces): "; is >> tempProductName;
			name(tempProductName);
			cout << " Unit: "; is >> _productUnit;
			cout << " Taxed? (y/n): "; is >> tempTax;

			if (!is.fail()) {

				_productErrorState.clear();

				if (tempTax) {

					bool productTaxableYes = tempTax == 'Y' || tempTax == 'y';
					bool productTaxableNo = tempTax == 'N' || tempTax == 'n';

					if (productTaxableYes) _productTaxable = true;

					if (productTaxableNo) _productTaxable = false;

					if (!(productTaxableYes || productTaxableNo)) {
						is.setstate(std::ios::failbit);
						_productErrorState.message("Only (Y)es or (N)o are acceptable");
						return is;
					}
				}
			}
			else {
				is.setstate(std::ios::failbit);
				_productErrorState.message("Only (Y)es or (N)o are acceptable");
				return is;
			}
			cout << " Price: ";
			is >> tempProductSalePricePerUnit;
			cin.ignore();
			if (is.fail()) {
				_productErrorState.clear();
				is.setstate(std::ios::failbit);
				_productErrorState.message("Invalid Price Entry");
				return is;
			}
			else setPrice(tempProductSalePricePerUnit);

			cout << " Quantity on hand: ";
			is >> tempProductQtyInStock;

			if (is.fail()) {
				_productErrorState.clear();
				_productErrorState.message("Invalid Quantity Entry");
				is.setstate(std::ios::failbit);
				return is;
			}
			else quantity(tempProductQtyInStock);

			cout << " Quantity needed: ";
			is >> tempProductQtyInNeed;

			cin.ignore();

			if (is.fail()) {
				_productErrorState.clear();
				_productErrorState.message("Invalid Quantity Needed Entry");
				is.setstate(std::ios::failbit);
				return is;
			}
			else setQtyNeed(tempProductQtyInNeed);

			if (is.fail()) {
				_productErrorState.clear();
			}
		}
		return is;
	}

	bool Product::operator==(const char *productSku) const {
		bool isIdentical;
		if (strcmp(productSku, this->_productSku) == 0) {
			isIdentical = true;
		}
		else
			isIdentical = false;

		return isIdentical;
	}

	double Product::total_cost() const {
		double productSalePricePerUnitTax = _productSalePricePerUnit * TAX_RATE;
		double productSalePricePerUnitPlusTax = _productSalePricePerUnit + productSalePricePerUnitTax;
		double productSalePriceTotal = static_cast<double>(_productQtyInStock * productSalePricePerUnitPlusTax);
		return productSalePriceTotal;
	}

	bool Product::isEmpty() const {
		return (_productName == nullptr) ? true : false;
	}

	int Product::qtyNeeded() const {
		return _productQtyInNeed;
	}

	int Product::quantity() const {
		return _productQtyInStock;
	}

	bool Product::operator>(const char *productSku) const {
		if (strcmp(_productSku, productSku) > 0)
			return true;
		else
			return false;
	}

	bool Product::operator>(const iProduct& productName) const {
		if (strcmp(_productName, productName.name()) > 0)
			return true;
		else
			return false;
	}

	int Product::operator+=(int unitsAdded) {
		if (unitsAdded > 0) 

			_productQtyInStock += unitsAdded;

			return _productQtyInStock;
	}

	// helper functions definition

	std::ostream &operator<<(std::ostream& os, const iProduct& object) {
		return object.write(os, true);
	}

	std::istream &operator>>(std::istream& is, iProduct& object) {
		return object.read(is);
	}

	double operator+=(double& cost, const iProduct& object) {
		double totalCost = cost + object.total_cost();
		return totalCost;
	}
}
