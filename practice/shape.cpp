// A demo on inheritance (i.e. an inheritance hierarchy)
// 0. parent class (base class) and child classes (derived classes)
// 1. inherited data members
// 2. constructors: base-class and derived-class
// 3. shadowing: redefined member functions
// 4. destructors: base-class and derived-class

#include <iostream>
using namespace std;

const double PI=3.1416;

// base class
class Shape {
    protected:             // accessible to derived classes
      int side1;

   public:
      Shape(int size);     // base-class constructor
      double calcArea();
      void hello();
      ~Shape();            // base-class destructor
};


// derived class
class Circle: public Shape {
			      // one inherited data member (protected)
			      // no NEW data member
   public:
      Circle(int r);          // NEW derived-class constructor; r: radius
      double calcArea();      // shadowing: redefine the base-class calcArea()
      ~Circle();              // NEW derived-class destructor
};

// derived class
class Rectangle: public Shape {
				    // one inherited data member (protected)
    protected:
       int side2;                   // one NEW data member(protected)
  
    public:
       Rectangle(int s1, int s2);   // NEW derived-class constructor

       double calcArea();           // shadowing: redefine calcArea()
       ~Rectangle();                // NEW derived-classdestructor
};


// derived class
class Square: public Rectangle {
	   
				 // two inherited data members(protected)
    public:
       Square(int s);            // NEW constructor
       double calcArea();        // Question: Is this necessary?!
       ~Square();                // NEW destructor
};


// a driver program that uses the classes
//   - the order of invoking the constructors and destructors
int main(void)
{
   Shape kabir(1000);

   Rectangle rectangle(9,3);
   Circle    circle(6);
   Square    square(10);

   cout << "The area of the shape: " << kabir.calcArea() << endl;

   cout << "The area of the square: " << square.calcArea() << endl;
   cout << "The area of the circle: " << circle.calcArea() << endl;
   cout << "The area of the rectangle: " << rectangle.calcArea() << endl;
   return 0;
}


/* ******* Class Hierarchy Implementation ******* */
Shape::Shape(int n) { 

  side1 = n;
  cout << "\n\t a shape(" << side1 << ") is created\n"; }

Shape::~Shape() { } // an empty body

double Shape::calcArea()
{ return 0.0; }

// base-class constructor used in an initialisation list
Circle::Circle(int r) : Shape(r)
{                                      
	// side1: inherited data member has been initialized by the base-class constructor
		      
	/* cout << "\t # a circle of radius " << side1
		<< " has been created #\n";
	 */
 }

// shadowing: redefinition of  the member function CalcArea() in the base class
double Circle::calcArea()
{       // side1: inherited data member; the radius of a circle

	return (PI * static_cast<double>(side1) 
		   * static_cast<double>(side1) ); 
}
 
Circle::~Circle() { }


// initialisation list; base-class constructor: Shape(s1)
Rectangle::Rectangle(int s1, int s2) : Shape(s1)
{                                   // side1: inherited data member
	side2 = s2;                 // side2: new data member

	cout << "\t + a rectangle(" << side1 << "x" << side2
	     << ") been created +" << endl;
}

// shadowing: redefinition of  the member function CalcArea in the base class
double Rectangle::calcArea()
{
	return ( static_cast<double>(side1 * side2) );
}
  
Rectangle::~Rectangle() { }

// initialisation list; base-class constructor: Rectangle(---)
Square::Square(int size) : Rectangle(size, size)
{                                // side1, side2: two inherited data members

   cout << "\t *** a square(" << side1 << "x" << side2
	<< ") has been created ***\n" << endl;
}
	 
double Square::calcArea()
{
      return static_cast<double>(side1*side1);

      //return Rectangle::CalcArea();
}
     
Square::~Square() { }
