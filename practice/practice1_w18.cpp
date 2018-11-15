// walkthrough - inline coding

#include <iostream>
#include <cstring>
using namespace std;

class Foo {
	char title[41];
	int  num;

    public:

	Foo() { set( "*Thanksgiving*", 100);
		cout << "1." << title << "," << num << " created\n";
	      }

	Foo( const char s[] ) {  set(s, 200);
				 cout << "2." << title << "," 
						<< num << " created\n";
			    }

	void set( const char * s, int k ) { strcpy(title, s); 
					num = k;
					cout << "2B.\n";        }

	void show() { cout << "+object: " << title 
				   << "," << num << "\n"; }

	void operator+ ( int b ) {

	     cout << "3.+: " << title << "," << num << endl;
	      num += b;
	}

};  // end class

int main(void) {

	Foo y, m("Monday?");

	y.show();
	m.show();
	
	m + 2000; // m.operator+(2000);
	m.show();

	//y + 23456;
       
	return 0;
}
