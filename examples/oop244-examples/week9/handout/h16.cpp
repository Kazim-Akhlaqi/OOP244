// Virtual functions - Polymorphic
// h16.cpp

#include "Animal.h"

void foo(Animal a){
  a.display();
}

void goo(Animal& a){
  a.display();
}

void foogoo(Animal& a){
  a.Animal::display();
}

int main(){

  Animal* a; // Static typing
  a = new Animal(); // Dynamic typing

  a->display();
  foo(*a);
  goo(*a);
  delete a;

  a = new Horse(); // Dynamic typing

  a->display();
  foo(*a);
  goo(*a);
  foogoo(*a);
  delete a;
}
