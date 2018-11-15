// Virtual Functions - Monomorphic
// h16.m.cpp

#include "Animal.h"

void foo(const Animal a){
  a.display();
}
void goo(const Animal& a){
  a.display();
}

int main(){
  Animal a;
  Horse h;
  
  a.display();
  foo(a);
  goo(a);

  h.display();
  foo(h);
  goo(h);
}