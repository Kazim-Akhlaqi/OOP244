// Based on shape.cpp
// 1. Question: Is it necessary to redefine calcArea() in the class Square?
// 2. Base-Calss::function-name()

#include <iostream>
using namespace std;

const double pi=3.1416;

// base class
class FunnyShape {
   protected:              // data member accessible to derived classes
      int side1;

   public:
      FunnyShape(int size);                // constructor
      int calcArea();
      ~FunnyShape();                       // destructor
};

// derived class
class FunnyCircle: public FunnyShape {
				      // one inherited data member(protected)
				      // no NEW data member
   public:
      FunnyCircle(int r);          // NEW constructor; r: radius
      int calcArea();              // shadowing: redefine the base-class calcArea()
      ~FunnyCircle();              // NEW destructor
};

// derived class
class Rectangle: public FunnyShape {
					 // one inherited data member(protected)
    protected:
       int side2;                        // one NEW data member(protected)
    public:
       Rectangle(int s1, int s2);        // NEW constructor
       int calcArea();
       ~Rectangle();                     // NEW destructor
};

class Square: public Rectangle {
					// two inherited data members(protected)
    public:
       Square(int s);                   // NEW constructor
       // int calcArea();               // Is this necessary???
       ~Square();                       // NEW destructor
};


// a driver program that uses the classes
int main(void)
{
   
   Square square(10);

   // Which calcArea() is used?
   cout << "The area of the square: " << square.calcArea() << endl;

   FunnyShape fs(500);
   cout << "... the area of the funny shape: " << fs.calcArea() << endl;

   FunnyCircle fc(500);

   // Which calcArea() is/are used?
   cout << "The area of the funny circle: " << fc.calcArea() << endl;
   return 0;
}

//******* Class Hierarchy Implementation *******
FunnyShape::FunnyShape(int n)
{ side1 = n;
  //cout << "\n\t a shape(" << side1 << ") is created\n"; 
}

FunnyShape::~FunnyShape() {}

int FunnyShape::calcArea()
{ return side1 * 2; }

// base-class constructor in an initialisation list
FunnyCircle::FunnyCircle(int r) : FunnyShape(r)
{                                 // side1: inherited data member
	//cout << "\t # a circle of radius " << side1
	//     << " has been created #\n"; 
}

// Redefine the member function CalcArea
int FunnyCircle::calcArea()
{                                    // side1: inherited data member
	double area;

	area =  FunnyShape::calcArea();  // use of class scope resolution operator (::)
	return (area * 2);           
}
 
FunnyCircle::~FunnyCircle() { }

// initialisation list; base-class constructor: Shape(s1)
Rectangle::Rectangle(int s1, int s2): FunnyShape(s1)
{                                  // side1: inherited data member
	side2 = s2;                // side2: new data member
	//cout << "\t + a rectangle(" << side1 << "x" << side2
	  //   << ") been created +" << endl;
}

// Redefine the member function CalcArea
int Rectangle::calcArea()
{
	return (side1 * side2);
}
  
Rectangle::~Rectangle() { }

// initialisation list; base-class constructor: Rectangle(---)
Square::Square(int size):Rectangle(size, size)
{                                    // side1, side2: two inherited data members

   //cout << "\t *** a square(" << side1 << "x" << side2
     //   << ") has been created ***\n" << endl;
}

Square::~Square() { }
