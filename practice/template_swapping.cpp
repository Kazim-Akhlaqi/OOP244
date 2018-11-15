
#include <iostream>
using namespace std;

/* How does the compiler process the function template? */

// function template
template<typename T>
void swapping(T& t1, T& t2){

   T temp;

   temp = t1;
   t1 = t2;
   t2 = temp;
}

int main(void){

    int    a=100, b=-999;
    double x=1.1, y=-9.9;
    char   c1='A', c2='z';
    
    swapping(a, b);
    cout << "a: " << a << " b: " << b << endl;
    
    //swapping(a, y);   // ????

    swapping(x, y);
    cout << "x: " << x << " y: " << y << endl;
    
    swapping(c1, c2);
    cout << "c1: " << c1 << " c2: " << c2 << endl;
}











