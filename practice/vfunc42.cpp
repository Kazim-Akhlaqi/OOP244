#include <iostream>
using namespace std;

// virtual destructors

class B {
   protected:
      int x;
   public:
      B(int k) { x=k*k; }

      virtual ~B() { cout << "B::clean up " << x << endl; }

      virtual void f1() { cout << "B::f1::" << x << endl; }

      void f2() { cout << "B::f2::" << x << endl; }
};

class D: public B {
      char c;
   public:
      D(int j, char z):B(j) { c = z; }

      virtual ~D() { cout << "D::clean up " << c << endl; }

      // Is f1() virtual?
      void f1() { cout << "D::f1::" << x << "<"
				   << c << ">" << endl; }

      void f2() { cout << "D::f2::" << x << "[" << c << "]" << endl; }

};

int main()
{
   B * pointers[3];

   pointers[0] = new B(5);
   pointers[1] = new D(7, '*');
   pointers[2] = new B(10);

   for (int k=0; k<3; k++) {

	pointers[k]->f1();
	pointers[k]->f2();

	delete pointers[k];
   }

   cout << "... the end ..." << endl;
   return 0;
}







