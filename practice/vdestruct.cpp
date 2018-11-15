
// virtual destructor in the base class

#include <iostream>
using namespace std;

#include <string.h>

class Employee {

   protected:
      char * name;
      char payroll_id[8];

   public:
      Employee();
      Employee(const char*, const char*);

      virtual ~Employee(); // virtual destructor
      //~Employee();

      Employee( const Employee& );
      Employee& operator =( const Employee& );

      const char* get_name();
      const char* get_id();
      virtual double pay();
};

class Manager: public Employee {

      double salary;

      char * style;

   public:
      Manager();
      Manager(const char*, const char*, double s, const char *);

      ~Manager();

      Manager ( const Manager & );
      Manager& operator= ( const Manager& );

      double pay();
};


int main(void) {

   Manager m("Evan2", "ABC", 111, "attack");

   Employee * emp[2];

   emp[0] = new Manager( "Evan Weaver", "290356W", 3500, "collaboration" );

   emp[1] = new Employee( "John Mar", "1234XYZ" );

   for (int i=0; i<2; i++) {

	 cout << emp[i]->get_name() << "," << emp[i]->pay() << endl;
	 delete emp[i];
   }
   cout << "... bye bye" << endl;
   return 0;
}

// ***** Implementation of the class Employee
Employee::Employee()
{ name = new char [strlen("unknown") +1];
  strcpy(name, "");
  strcpy(payroll_id, "9000"); }

Employee::Employee(const char *sn, const char *sid)
{ name = new char [strlen(sn)+1];
  strcpy(name, sn);
  strcpy(payroll_id, sid); }

Employee::~Employee() { if (name){
			    cout << "... Employee: clean up: " << name << endl;
			    delete [] name; }
		      }

Employee::Employee( const Employee& source) {

	name = new char [strlen(source.name) + 1];
	strcpy(name, source.name);
	strcpy(payroll_id, source.payroll_id);
}

Employee& Employee::operator =( const Employee& rhs) {

	if (&rhs != this) {

	 delete [] name;
	 name = new char [strlen(rhs.name)+1];
	 strcpy(name, rhs.name);
	 strcpy(payroll_id, rhs.payroll_id);
    }
	return *this;
}

const char* Employee::get_name()
{ return name; }

const char* Employee::get_id()
{ return payroll_id; }

double Employee::pay()
{ return 0.00; }

// ***** Implementation of the class Manager

Manager::Manager() { salary = 0.0;
		     style = new char [6];
		     strcpy( style, "bossy" );
}

Manager::Manager(const char *sn, const char*sid, double sal, 
		 const char * style): Employee(sn, sid)
{ salary = sal;

  Manager::style = new char [strlen(style)+1];  // allocate storage
  strcpy( Manager::style, style);
}

double Manager::pay()
{       return salary; }

Manager::~Manager() { if (style){
			    cout << "... Manager: clean up: " << style << endl;
			    delete [] style; }
}

// copy constructor in the derived class
Manager::Manager( const Manager & source): Employee( source ) {

	salary = source.salary;
}

// operator = in the derrived class
Manager& Manager::operator = (const Manager & rhs ) {

	if (this != &rhs) {

       Employee::operator=( rhs );

	salary = rhs.salary;
    }
    return *this;
}













