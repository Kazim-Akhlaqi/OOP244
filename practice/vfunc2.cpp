#include <iostream>
using namespace std;

// polymorphism: dynamic binding and pass by reference
// declaration of virtual functions

class B {
   protected:
      int x;
   public:
      B(int k) { x=k*k; }
      virtual void f1() { cout << "B::f1::" << x << endl; }
};

class D: public B {
      char c;
   public:
      D(int j, char z): B(j) { c = z; }
      void f1() { cout << "D::f1::" << x << "<"
			      << c << ">" << endl; }
      
};

void h(B & b)
{ cout << "inside h:\n"; b.f1();        }

void g(B * b)
{ cout << "inside g:\n"; b->f1(); }

int main()
{
   B one(5);       D two(7,'*');

   cout << "passing a base-class object by reference...\n";
   h( one );

   cout << "passing a derived-class object by reference...\n";
   h( two );

   cout << "... passing pointers into the function...\n";
   g(&one);     g(&two);

   cout << "... Mmmmmmmmmmmm...\n";
/*
   B *pb = new D(9,'!');
   g(pb);
   delete pb;
*/
   return 0;
}







