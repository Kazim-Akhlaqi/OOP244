/* an abstract base class
   - cannot be used to create objects
   - a common abstraction/interface for all the concrete classes
     in the inheritance hierarchy
   - a design approach
   - PURE VIRTUAL FUNCTIONS (not implemented)
   - DATA MEMBERS ARE ALLOWED
 */

/* a C++  interface: an abstract base class without data members */

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

 // an abstract base class (ABS)
 class Shape {

    public:

	// virtual funtions - implemented
	virtual double area() const { return 0.0; }
	virtual double volume() const { return 0.0; }

	// PURE VIRTUAL FUNCTIONS - NOT IMPLEMENTED!
	// - the keyword "virtual" + "= 0"

	virtual const char * description() const = 0;
	virtual void  draw() const = 0;

	// constructors - NOT IMPLEMENTED!
	// destructor - NOT IMPLEMENTED!
 };

// a concrete class derived from the ABS
class Point: public Shape {

	int   x, y; // coordinates
	char  information[21];

	public:

	// constructor
	Point(int a=1, int b=1): x(a), y(b) 
	{ strcpy( information, "a point (x,y)"); }

	// implementation of two PURE VIRTUAL FUNCTIONS 
	const char * description() const { return information; }

	void draw() const { 
		cout << "  |   x( " << x << "," << y << ")" << endl
		     << "  |      " << endl
		     << "  +--------+ " << endl; 
	}

	// two virtual functions (area, volume) are inherited!

}; // end Point

const double PI=3.1415; // a constant

class Circle: public Shape {

	int  radius;
	char information[21];

	public:

	// constructor
	Circle( int m=5 ): radius(m) 
	{ strcpy( information, "a circle with a radius" ); }

	// shadowing: redefinition of the virtual function area() 
	double area() const { return PI * radius * radius; }

	// implementation of two PURE VIRTUAL FUNCTIONS 
	const char * description() const { return information; }

	void draw() const { 
		cout << "    *---> (radius: " 
		     << radius << " )" << endl; }

}; // end Circle

class RectBlock: public Shape {

    int  x, y, z; 
    char information[21];

    public:

    RectBlock( int a, int b, int c): x(a), y(b), z(c) 
    { strcpy( information, "a rectangular block" ); }

    // redefinitions of 2 virtual functions: area(), volume()
    double area() const { return (2*(x*y)+2*(y*z)+2*(x*z)); }

    double volume() const { return (x*y*z); }

    // implementation of 2 PURE VIRTUAL FUNCTIONS
    const char * description() const { return information; }

    void draw() const { 
	    cout << "NOTE: UNABLE TO DRAW A 3-D DIAGRAM!\n"
		 << "solid: width= " << x
		 << " length= " << y << " height= " << z; }

}; // end RectBlock

int main( void ) {

	Point s1(30,45); Point ari;

	Circle s2(10);

	RectBlock s3(11, 22, 33);

	cout << s1.area() << endl;
	cout << s2.area() << endl;
	s1.draw();
	s2.draw();


	// Part 2
	Shape * norbert;  // Shape: ABS
	
	norbert = &s2;
	cout << norbert->area() << endl;

	// Part 3 - POLYMORPHISM IN ACTION

	Shape * ptrs[3];  // an array of 3 abstract base-class pointers

	ptrs[0] = &s1;
	ptrs[1] = &s2;
	ptrs[2] = &s3;

	cout.setf(ios::fixed);
	cout << setprecision(2);

	for (int k=0; k < 3; k++) {  // polymorphism in action!

		cout << ptrs[k]->description() << endl;
		cout << "area: " << ptrs[k]->area() << endl;
		cout << "volume: " << ptrs[k]->volume() << endl;

		cout << "diagram: " << endl;
		ptrs[k]->draw();

		cout << endl;
	}
	return 0;
} // end main
