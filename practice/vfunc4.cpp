#include <iostream>
using namespace std;

// polymorphism: dynamic binding and pass by reference
// declaration of virtual functions
// an array of pointers

class B {
   protected:
      int x;
   public:
      B(int k) { x=k*k; }

      ~B() { cout << "B::clean up " << x << endl; }

      virtual void f1() { cout << "B::f1::" << x << endl; }
};

class D: public B {
      char c;
   public:
      D(int j, char z): B(j) { c = z; }

      ~D() { cout << "D::clean up " << c << endl; }

      void f1() { cout << "D::f1::" << x << "<"
				   << c << ">" << endl; }

};

int main()
{
   B* pointers[3];  // an array of base-class pointers!

   pointers[0] = new B(5);
   pointers[1] = new D(7, '*');
   pointers[2] = new B(10);

   for (int k=0; k<3; k++) {

	pointers[k]->f1();

	delete pointers[k]; // destructor is called; how many?
   }

   cout << "... the end ..." << endl;
   return 0;
}







