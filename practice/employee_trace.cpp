
// TRACE THE CODE

// C++ Classes with (Dynamically Allocated) Resources
// - an object uses resources outside its own memory space
// - a pointer, constructors, and destructor (new, delete [])

// - command line on matrix: g++ -std=c++0x employee.cpp

#include <cstring>
#include <iostream>
using namespace std;

class Employee {

   char*  name;      // a pointer: NO MEMORY HAS BEEN ALLOCATED!
   int    idnum;
   double salary;

   public:
      Employee(const char*, int, double);
      Employee();

      ~Employee();   // destructor
      void display() const;
};


int main(void)
{
   Employee e1( "Bill Gates", 12345, 9999.99),
	    e2;
  
   e1.display();  
   e2.display(); 
  
   // 2 objects will go out scope; in what order?
   return 0;
}



// constructor: allocate memory storage (i.e. dynamic memory allocation)
Employee::Employee(const char * s, int m, double t) {
   // data members of the current object: name, idnum, salary
  
   name = new (nothrow) char[ strlen(s)+1 ]; // name could be set to nullptr

   if ( name != nullptr ) { // C++11 standard
       strcpy(name, s);
       idnum = m;
       salary = t;
   }

   // TRACE
   cout << "... constructor: allocate memory for the data member: ["
	<< name << "]" << endl;
    
}


// initialize an object to a SAFE EMPTY STATE
Employee:: Employee() { name = nullptr;
			idnum = 0;
			salary = 0.0;

			// TRACE
			cout << "... constructor: the object is at a safe empty state"
			     << endl;
}

// clean-up: deallocate the memory storage!
Employee::~Employee() {

    // TRACE
    cout << "### destructor: clean up before the C++ object goes out of scope ###\n"
	 << "### idnum: " << idnum << endl;

    if (name != nullptr){  // C++11 standard

       // TRACE
       cout << "... destructor: release the memory allocated for the data member: ["
	    << name << "]" << endl;
       

       delete [] name;
       name = nullptr;
   }
}

void Employee::display() const
{
   if (name == nullptr)
	cout << "*** the object is in a safe empty state" << endl;

   else cout << "*** employee name: " << name << ", id:" << idnum
	     << ", salary:$ " << salary << endl;
}












