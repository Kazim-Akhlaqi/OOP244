// Main.cpp

#include <iostream>
#include "Crystal.h"
#include "Gem.h"
using namespace std;
using namespace gem_kingdom;

int main() {

  cout << "Creating a Crystal" << endl;

  Crystal c = Crystal();
  c.display(cout);

  cout << "\nCreating a Gem" << endl;
  Gem g = Gem("Ruby", 1000, 3);
  cout << g << endl;

  cout << "\nPolishing a Gem" << endl;
  //g.cut();
  g.polish();

  g.display(cout, "Hello"); 
  //g.Crystal::display(cout, "hello");
  cout << g << endl;
}