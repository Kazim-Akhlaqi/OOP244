
/* a stack of integers */

#include <iostream>
using namespace std;

class Stack {

    int size;
    int top;

    int* data;  // a pointer to the stack of integer items

    public:

    bool isEmpty( ) const;
    bool isFull( )  const;
    Stack( int = 5 );
    bool push( const int& );
    bool pop( int& );

    ~Stack();

};

Stack::Stack(int m) {

    size = m >= 0 ? m: 5;
    top  = -1;

    data = new int [size];
}


bool Stack::isEmpty() const { return top == -1; }

bool Stack::isFull() const { return top == size-1; }

bool Stack::push( const int& item ) {

   bool val = false;

   if ( !isFull() ) {

	val = true;

	data[ ++top ] = item;
   }

   return val;
}

bool Stack::pop( int & item ) {

   bool val = false;

   if ( !isEmpty() ) {

	    val = true;

	item = data[ top--];
   }

   return val;
}

Stack::~Stack() { delete [ ] data;}

int main(){

    Stack mini;

    int x=100, y;

    cout << "... push onto the stack 4 times\n";

    mini.push(x);

    x = 200;
    mini.push(x);

    x = 300;
    mini.push(x);

    x = 400;
    mini.push(x);

    /* 100, 200, 300, 400(top) */

    cout << "... What is on the top of the stack?\n"
	 << "... pop off the stack 2 times\n";

    mini.pop(y);
    mini.pop(y);

    cout << "y: " << y << endl;
    return 0;
}
