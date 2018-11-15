
/* generic class templates */
/* parameterized types */

#ifndef _STACK_TEMPLATE_H
#define _STACK_TEMPLATE_H

#include <iostream>
using namespace std;

template <class T>

class Stack {

    int size;
    int top;

    T * data;  // a pointer to the stack of data items 
	       // whose data type is T (e.g. int, char, double, Person)

    public:

    Stack(int=5);
    bool isEmpty( ) const;
    bool isFull( )  const;
    bool push( const T & );
    bool pop( T & );

    ~Stack();

};

/* implemenation */
template<class T>
Stack<T>::Stack(int m) {

    size = m >= 0 ? m: 5;
    top  = -1;

    data = new T [size];
}

template<class T>
bool Stack<T>::isEmpty() const { return top == -1; }

template<class T>
bool Stack<T>::isFull() const { return top == size-1; }

template<class T>
bool Stack<T>::push( const T & item ) {

   bool val = false;

   if ( !isFull() ) {

	val = true;

	data[ ++top ] = item;
   }

   return val;

}

template<class T>
bool Stack<T>::pop( T & item ) {

   bool val = false;

   if ( !isEmpty() ) {

	    val = true;

	item = data[ top--];
   }

   return val;
}

template<class T>
Stack<T>::~Stack() { delete [ ] data;}


#endif
