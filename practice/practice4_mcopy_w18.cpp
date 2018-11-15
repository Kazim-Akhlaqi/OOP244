#include <iostream>
#include <cstring>
using namespace std;

class foo {
     int  number;
     char string[20];

     public:
     foo( ) { set(3, 5);
	      cout << "1." << endl; }

     ~foo( ) { cout << "2. bye-bye: " << number << ','
		    << string << endl;              }

     // copy constructor

     foo( const foo & src ) {
			      cout << "3. copy constructor...\n";
			      src.output();
			      number = src.number * 2;
			      strcpy( string, src.string );
			      strcat( string, "+COPY" );
			      cout << "... copying done...\n";
     }

     // assignment operator (member function!)

     foo& operator= ( const foo & z ) {

	     cout << "4. assignment operator...\n";
	     z.output();
	     strcpy( string, z.string );
	     strcat( string, "$" );
	     number = z.number * 3;
	     this->output();
	     cout << "... operator = done...\n";
	     return *this;
     }

     void set(int a, int b){  number = a * b;
			      strcpy( string, "Winter" ); }

     void messagain( foo );
     void output() const { cout << number << ',' << string << endl;     }
};

void foo::messagain( foo x ) {
     
	 cout << "5. messagain..." << endl;
	 x.output();
	 (*this).output();
	 cout << "... done with messagain" << endl;
}

int main(void) {

     foo a, b;

     a.messagain(b); // copy constructor is called!
	 
     //a = b;
	 
     a.output();
     b.output();

     // Part 2
     cout << "Part 2" << endl;

     foo c = a; // copy constructor is called! NOT operator ==

     c.output();

     return 0;
}
























