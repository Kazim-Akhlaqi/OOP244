#include <iostream>
#include <cstring>
using namespace std;

// an inheritance hierarchy
// static (i.e. compile-time) binding of a function
// polymorphism: dynamic (i.e. run-time) binding of a function
//               as determined by the type of the object

class Employee {
   protected:
      char name[30];
      char payroll_id[8];

   public:
      Employee();
      Employee(const char*, const char*);

      const char* get_name() const;
      const char* get_id()const;
      double pay() const;
};

class Manager: public Employee {
   protected:
      double salary;                 // monthly salary
   public:
      Manager();
      Manager(const char*, const char*, double s);

      double pay() const;           // shadowing, redefined, overriden!
};

class Staff: public Employee {
   protected:
      double hourly_rate;
      int    weekly_hours;
   public:
      Staff();
      Staff(const char*, const char*, double r, int h);

      double get_rate() const;
      int get_hours() const;
      double pay() const;          // shadowing,redefined, overriden!
};

int main(void){

   Manager   manager( "Mona Lisa", "29035ML", 3500);
   Staff     staff( "John Doe",  "11117JD", 65, 7);

   Employee  employee( "Daniel Price", "12345DP" );

   cout.setf(ios::fixed);  // control format
   cout.precision(2);      // precision control
  
   Employee* eList[3];    // a static array of 3 pointers;
                          // each pointer could point at a base-class object
						  // OR a derived class object

   eList[0] = &manager;   // at run time: e1 points at an object whose type is Manager
   eList[1] = &staff;
   eList[2] = &employee;
   
   for (int k=0; k < 3; k++) {
        cout << k << ": "
	         << eList[k]->get_name() << ", " 
		     << eList[k]->get_id() << endl;

       cout << "... the pay: $" << eList[k]->pay() << endl << endl;
   }
   
   
   // Part 2 - Dynamic Memory Allocation
   cout << "... allocate resources at run-time" << endl;
   
   eList[0] = new Employee( "John Doe", "J12345" );
   eList[1] = new Staff( "Anne Heath",  "A56789", 35, 14 );  
   eList[2] = new Manager( "Mona Lisa", "M29038", 4500 );   

   for (int k=0; k < 3; k++) {
        cout << k << ": "
	         << eList[k]->get_name() << ", " 
		     << eList[k]->get_id() << endl;

        cout << "... the pay: $" << eList[k]->pay() << endl << endl;
   }
   
   // release the resources
   for (int k=0; k < 3; k++)
        delete eList[k];
		
   return 0;
}


// ***** Implementation of the class Employee
Employee::Employee()
{ strcpy(name, ""); strcpy(payroll_id, ""); }

Employee::Employee(const char *sn, const char *sid)
{ strcpy(name, sn); strcpy(payroll_id, sid); }

const char* Employee::get_name() const
{ return name; }

const char* Employee::get_id() const
{ return payroll_id; }

double Employee::pay() const
{ return 0.00; }

// ***** Implementation of the class Manager
Manager::Manager(const char *sn, const char*sid, double sal): Employee(sn, sid)
{ salary = sal; }


double Manager::pay() const {
       return salary; 
}

// ***** Implementation of the class Staff
Staff::Staff(const char * sn, const char *sid, double r, int h): 
       Employee(sn, sid)
{ hourly_rate = r; weekly_hours = h;  }

double Staff::pay() const
{ return hourly_rate * weekly_hours; }













