
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

class abc {
		    
     int no;
     char grade[14];

     public:         
	 
	 abc();
	 abc( int, const char* );

	 void set( int n,  const char * g );
	 void display() const;
	 int hello(abc&, abc);
	 ~abc();
 };

 abc::abc() { cout << "1." << endl;
	      set( 1000, "ABCD" ); }

 abc::abc(int m, const char * s) { cout << "2." << endl;
				   set(m, s); }

 void abc::set(int n, const char* g){
	  no = n;
	  strcpy( grade, g );
 }
 
 void abc::display() const {

	cout << setfill('0') << setw(7) << no
	     << setfill( '#' ) << setw(7) << grade << endl;
 }
 
 abc::~abc() { 
    cout << "3. bye bye: " << no << "," << grade << endl;
 }
 
 int abc::hello( abc& x, abc y ){

	 cout << "5." << endl;

	 *this = y;
	 x.set( -1111, "FFFF" );
	 y.set( -3333, "DDDD" );
	 
	 return x.no + y.no;
 }

int main(void){

    // Part 1
    abc a, b( 9000, "AABB" ), f(8000, "CCCC");

    cout << f.hello(a, b) << endl;;

    a.display();
    b.display();
    f.display();

    // Part 2
    cout << "...Part 2 " << endl;
	
/*
	abc c[5]; // an array of C++ objects
	   
	c[0].set( 123, "AAA" );
	c[2].set( 456, "BBB" );
	c[4].set( 789, "CCC" );
	   
	for (int k=0; k<5; k++)
		 c[k].display();
 */
    return 0;
}
