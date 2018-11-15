// Main.cpp

#include <iostream>
#include "Crystal.h"
#include "Gem.h"
using namespace std;
using namespace gem_kingdom;

int main() {

  cout << "Creating a Crystal" << endl;

  iCrystal* c = new Crystal();
  c->display(cout);
  c->cut();
  cout << "\nCutting a Gem" << endl;
  c->display(cout);

  cout << "Delete c" << endl;
  delete c;

  cout << "\nCreating a Gem" << endl;
  c = new Gem("Ruby", 1000, 50);
  c->display(cout);

  cout << "\nCutting a Gem" << endl;
  c->cut();
  c->display(cout);

  cout << "Delete c" << endl;
  delete c;
}