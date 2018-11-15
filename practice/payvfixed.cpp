#include <iostream>
using namespace std;

#include <string.h>

// polymorphism and virtual functions: dynamic(run-time) function binding

class Employee {
   protected:
      char name[30];
      char payroll_id[8];
   public:
      Employee();
      Employee(char*, char*);
      const char* get_name();
      const char* get_id();
      virtual double pay();      // a virtual function
};

class Manager: public Employee {
   protected:
      double salary;             // monthly salary
   public:
      Manager();
      Manager(char*, char*, double s);
      virtual double pay();     //optional: the keyword virtual!
};

class Staff: public Employee {
   protected:
      double hourly_rate;
      int    weekly_hours;
   public:
      Staff();
      Staff(char*, char*, double r, int h);
      double get_rate();
      int get_hours();
      virtual double pay();     //optional: the keyword virtual
};

int main()
{
    Employee *e1;
    Manager b("Evan Weaver", "290356W", 3500.73657);
    Staff   s("Steve Vezino", "111222V", 65.39, 7.2);

    cout.setf(ios::fixed);         // control format
    
    double temp =123456789;
    cout << "testing:"  << temp << "***" << endl;

   cout.precision(2);             // control precision
   e1 = &b;
   cout << e1->get_name() << " " << e1->get_id() << endl;
   cout << "Monthly pay: " << e1->pay() << endl;

   e1 = &s;
   cout << e1->get_name() << " " << e1->get_id() << endl;
   cout << "Weekly pay***" ;

   cout.width(20);                 // control the field width
   cout << e1->pay() << "***" << endl;
   return 0;
}

// ***** Implementation of the class Employee
Employee::Employee()
{ strcpy(name, ""); strcpy(payroll_id, ""); }

Employee::Employee(char *sn, char *sid)
{ strcpy(name, sn); strcpy(payroll_id, sid); }

const char* Employee::get_name()
{ return name; }

const char* Employee::get_id()
{ return payroll_id; }

double Employee::pay()
{ return 0; }

// ***** Implementation of the class Manager
Manager::Manager(char *sn, char*sid, double sal): Employee(sn, sid)
{ salary = sal; }

double Manager::pay()
{       return salary; }

// ***** Implementation of the class Staff
Staff::Staff(char *sn, char *sid, double r, int h): Employee(sn, sid)
{ hourly_rate = r; weekly_hours = h;  }

double Staff::pay()
{ return hourly_rate * weekly_hours; }


