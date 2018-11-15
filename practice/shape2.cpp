// A demo on inheritance
// How are the destructors invoked?

#include <iostream>
using namespace std;

const double PI=3.1416;

// base class
class Shape {
   protected:              // data member accessible to derived classes
      int side1;

   public:
      Shape(int size);         // constructor
      int calcArea();
      ~Shape();                // destructor
      void show();
};

// derived class
class Circle: public Shape {
   public:
      Circle(int r);                  // r: radius
      int calcArea();
      ~Circle();
      void show();
};

// derived class
class Rectangle: public Shape {
   protected:
      int side2;                                // protected NEW data member
   public:
      Rectangle(int s1, int s2);        // NEW constructor
      int calcArea();
      ~Rectangle();                     // NEW destructor
};

class Square: public Rectangle {
   public:
      Square(int s);                   // NEW constructor
      int calcArea();
      ~Square();                       // NEW destructor
};


// a driver program that uses the classes
int main(void)
{

   Rectangle rectangle(9,3);
   Circle circle(6);
   Square square(10);

   /*
   cout << "The area of the square: " << square.calcArea()
	<< endl;
   cout << "The area of the circle: " << circle.calcArea()
	<< endl;
   cout << "The area of the rectangle: " << rectangle.calcArea()
	<< endl;
   */
   cout << "\n\n... the C++ objects go out of scope " << endl;
   return 0;
}

//******* Class Hierarchy Implementation *******
Shape::Shape(int n)
{ side1 = n;
  cout << "\n\t * a shape(" << side1 << ") is created *\n";}

Shape::~Shape()
{ cout << "\t call the  Shape destructor..." << endl << endl;}

int Shape::calcArea()
{ return 0; }

// base-class constructor in an initialisation list
Circle::Circle(int r) : Shape(r)
{ cout << "\t # a circle of radius " << side1
       << "has been created #\n"; }

// Redefine the member function CalcArea
int Circle::calcArea()
{
	return (PI * side1 * side1); // side1 is the radius of a circle!
}

Circle::~Circle()
{ cout << "\t call the  Circle destructor..." << endl; }

// initialisation list; base-class constructor: Shape(s1)
Rectangle::Rectangle(int s1, int s2):Shape(s1)
{
 side2 = s2;
 cout << "\t + a rectangle(" << side1 << "x" << side2
		<< ") has been created +" << endl;
}

// Redefine the member function CalcArea
int Rectangle::calcArea()
{
	return (side1 * side2);
}

Rectangle::~Rectangle()
{ cout << "\t call the  Rectangle destructor..." << endl;}

// initialisation list; base-class constructor: Rectangle(---)
Square::Square(int size):Rectangle(size, size)
{
   cout << "\t *** a square(" << side1 << "x" << side2
	  << ") has been created ***" << endl;
}

int Square::calcArea()
{
	return (side1 * side2);
}

Square::~Square()
{ cout << "\t call the Square destructor..." << endl; }

