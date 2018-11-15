#include <iostream>
using namespace std;

#include <cstring>
using namespace std;

// polymorphism and virtual functions: dynamic(run-time) function binding

class Employee {
      //protected:
      char name[30];
      char payroll_id[8];
   public:
      Employee();
      Employee(const char*, const char*);
      const char* get_name() const;
      const char* get_id() const;

      virtual double pay() const;      // a virtual function!
};

class Manager: public Employee {
   protected:
      double salary;             // monthly salary
   public:
      Manager();
      Manager(const char*, const char*, double s);

      virtual double pay() const;     //optional: the keyword virtual!
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

      double pay() const;     //optional: the keyword virtual
};

double calculate_pay( const Employee& );
// double cal_pay2( const Employee* );

int main(void)
{
    Employee *e1; // a base-class pointer used to do polymorphism
   
    Manager b("Mona Lisa", "29035ML", 3500.73657);
    Staff   s("John Doe",  "11122JD", 65.39, 7.2);

    cout.setf(ios::fixed);         // control format
    cout.precision(2);             // control precision

    e1 = &b;
    cout << "Manager object: "
	 << e1->get_name() << ", " << e1->get_id() << endl;

    cout << "*** Monthly pay: $" << e1->pay() << endl << endl;

    e1 = &s;
    cout << "Staff object: "
	 << e1->get_name() << ", " << e1->get_id() << endl;

    cout << "*** Weekly pay: $"
	 << e1->pay() << endl;

    // Part 2: C++ reference parameter
    cout << "\n... polymorphism in action" << endl;

    cout << "passing object s: " << calculate_pay( s ) << endl;
    cout << "passing object b: " << calculate_pay( b ) << endl;
    return 0;
}

double calculate_pay(const Employee& baseref){

   return baseref.pay();   // polymorphism in action!!!
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
{ return 0; }

// ***** Implementation of the class Manager
Manager::Manager(const char *sn, const char*sid, double sal): 
	 Employee(sn, sid)
{ salary = sal; }

double Manager::pay() const
{      return salary; }

// ***** Implementation of the class Staff
Staff::Staff(const char *sn, const char *sid, double r, int h): 
       Employee(sn, sid) {
   hourly_rate = r; 
   weekly_hours = h;  
}

double Staff::pay() const
{ return hourly_rate * weekly_hours; }


