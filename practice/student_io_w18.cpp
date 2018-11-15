
// C++ class declaration and class implementation in ONE source file
// a better design: a header file (.h) + an implementation file (.cpp)

#include <cstring>
#include <iostream>
	 
/* C++ class declaration 
   - private data members
   - public  memeber functions 
 */

class Student {
		      /* declarations of data members */
     int no;
     char grades[14];

     public:         
		     /* declarations of constructors */
	Student( );
	Student( int, const char* );
	Student(int);
		     /* declarations of member functions */
	void set( int n,  const char * g );
	
	// std: namespace for istream and ostream classes, given by the C++ language
	std::istream& read(std::istream& is);
	std::ostream& write(std::ostream& os)const; // const member function that cannot modify the current object!
	
 };

 /* two helper functions: declared outside the class */
 
 std::ostream& operator<< (std::ostream& os, const Student& person);
 std::istream& operator>> (std::istream& is, Student& person);
	
 /* implementations of the helper functions */  
  std::ostream& operator<< (std::ostream& os, const Student& person) {
  
     person.write(os); // member function call with a Student object
	 
     return os;
  }
  
  std::istream& operator>> (std::istream& is, Student& person) {
  
     person.read(is); // member function call with a Student object
     return is;
  }
	
 /* C++ class implementation */
 
 // Note: You may omit "std::" if you have include "using namespace std;".
 std::ostream& Student::write(std::ostream& os)const { 
    os << "number: " << no << ", "
	   << "grades: " << grades << std::endl;
	return os;
 }
 
 std::istream& Student::read(std::istream& is) { 
    // data members of the current object: no, grades
	is >> no;
	is >> grades;
	return is;
 }
 
 Student::Student(int d) { set(d, "AA");  } 
 Student::Student() { set( 12345, "A+A+" ); }
 Student::Student(int m, const char * s) { set(m, s); }
 
 void Student::set(int n, const char* g){
	  no = n;
	  strcpy( grades, g );
 }


int main(void){
    Student a, b(9987, "AAAAA"), c;
	
    std::cout << a;
    std::cout << b;
	
	// Part 2
	std::cout << "Please enter a student number and the grades at separate lines:\n";
	std::cin >> c;
	
	std::cout << c;
    return 0;
}

