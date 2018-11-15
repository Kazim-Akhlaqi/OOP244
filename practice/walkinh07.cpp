
#include <iostream>
using namespace std;

class B {

   protected:
	  int  x, y;
   public:
      B() { cout << "B.1." << endl;
	    x=-20; y=-30; }

      B(int b1, int b2) { cout << "B.2\n";
			  x=b1; y=b2; }

      ~B() { cout << "B:: clean up" << endl; }

      int add() { return x+y; }

      void display() { cout << "..." << x << "..." << y << endl; }
};

class D: public B {

	char z;

    public:
	   D() { cout << "D.1." << endl; 
		 z = '?'; }

	   D(int i, int j, char t);

	   D(char t) { cout << "D.3.\n";
		       z = t; }

	   ~D() { cout << "D:: clean up" << endl; }

	   int minus() { return x-y; }

	   void display() { B::display();  // call a shadowed function
			    cout << "..." << z << endl; }
};


class E: public D {

       double t;

       public:

       E( int, int , char, double );

       ~E() { cout << "E:: clean up" << endl; }

       void display() { cout << minus() << ',' << add() << endl; }
};

D::D(int i, int j, char t): B(i,j) {

     cout << "D.2.\n";
     z = t; }

E::E(int a, int b, char c, double d): D(c) { t = a+b+d;
					     cout << "E.1." << endl; }

int main(void)
{
   D d( 1, 2, '$');

   //E e( 3, 5, '@', 9.9 );

   d.display();
   //e.display();

   return 0;
}
