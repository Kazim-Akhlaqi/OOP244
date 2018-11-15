
#include "student_header.h"

int main(void){

    Student a, b(9987, "AAAAA");

    a.display();  // what if constructors are missing?
    b.display();

    a.set( 3453, "BBFAC" );
    b.set( 1111, "CCCCCCF" );

    a.display();
    b.display();
    return 0;
}

