
// Notes:
// 1. C++ class declaration and class implementation in ONE source file
// 2. a better design: a header file (.h) + an implmentation file (.cpp)
//    - example: student_header.h, student_impl.cpp, student_v2.cpp
// 3. matrix: g++ student_w18.cpp OR g++ -std=c++0x student_w18.cpp

/* Concepts
   1. C++ class: a data type
   2. C++ object: an instance of a C++ class; a variable
   3. C++ class = DECLARATIONS (.h) + IMPLEMENATION (.cpp)
      a) declarations of private data members
      b) declarations of public member functions
      c) declarations of constructors and a destructor
      d) implemenation of the member functions, constructros and destructor
   4. C++ object = priavate data members + public member functions

 */

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/* 1. C++ class declaration (DATA TYPE) 
      - private data members
      - public  memeber functions 
 */

class Student {
		      /* declarations of PRIVATE data members */
     int  no;
     char grades[14];

     public:        
		     /* declarations of constuctors */
	Student( );
	Student( int, const char* );        // a const pointer

		     /* declarations of PUBLIC member functions */
	void set( int n,  const char * g ); // a const pointer
	void display() const;
                   // a const member function
 };

 /* 2. C++ class implementation of member functions */

 /* two constructors (the class resolution operator ::) 
     - the objects are intialized properly
     - the default constructor: objects are initalized to be in safe empty states
       (i.e. well-defined states) at the time of creation
  */
 
 Student::Student() { set( 12345, "AAAA" ); }

 Student::Student(int m, const char * s) { set(m, s); }
 
 /* two  member functions (the class resolution operaotr ::) */ 
 void Student::set(int n, const char* g){

	  no = n; // store the value of n into the data member(no) in an object!

	  strcpy( grades, g );

	  // - assumptions
	  //   - what if g is nullptr?
	  //   - what if n is out of range?
 }
 
// a const member function
 void Student::display() const {

	cout << "student number: " 
	     << setfill('0') << setw(7) << no << " "  
	     << setfill( 'x' ) << setw(12) 
	     << " grades: " << grades << endl;
 }


/* 3. the main program/the client program */
int main(void){

    // Part 1 - What if constructors are not implemented?
    Student one;

    //one.no = -1111;   // ERROR!

    // 1. invocation of a member function - store data into the object
    one.set( 9988776, "AAAA" );

    // 2. invocatoin of a member funciotn - get the data from the object and dipslay them
    one.display();

    // Part 2
    Student a, b(9987, "FFFF");    // declarations of two C++ objects
				   // the object a is in a safe empty state 
				   // at the time of object creation

    a.display(); // what if constructors are missing?
    b.display();

    /* store new data into two objects */
    a.set( 3453, "BBFAC" );
    b.set( 1111, "CCCCCCF" );

    a.display();
    b.display();

    return 0;
}

