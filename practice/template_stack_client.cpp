
#include "template_stack.h"
#include <iostream>
using namespace std;

int main( void ) {

    Stack <double> stack_double; // a stack of double values

    Stack<char> stack_char(10); // a stack of char values

    // How about a stack of Customer objects?

    double z;
    char   y;

    stack_double.push( 1.2 );
    stack_double.push( 3.4 );
    stack_double.push( 5.6 );

    while( !stack_double.isEmpty() ) {

	    stack_double.pop( z );
	    cout << z << endl;
    }
    cout << "the stack is empty!\n";

   stack_char.push( 'z' );
   stack_char.push( 'o' );
   stack_char.push( 'O' );

   stack_char.pop(y);
   cout << "char popped: " << y << endl;

   stack_char.push( 'N' );
   stack_char.push( 'E' );

   for( int k=1; k <=4; k++) {

	stack_char.pop(y);
	cout << y << endl;
   }

   if (stack_char.isEmpty())
	cout << "... the stack is empty now\n";
   else cout << "... the stack is not empty!\n";
}
