// Gem.cpp

#include <iostream>
#include "Gem.h"

namespace gem_kingdom {

  Gem::Gem() : Crystal() {
    name = "unknown";
    polished = false;
  }

  Gem::Gem(std::string str, int mass, int purity) : Crystal(mass, purity) {
    if (str.length() == 0)
      *this = Gem();
    else {
      name = str;
      polished = false;
    }
  }

  Gem::Gem(const Gem& gem){
    *this = gem;
  }

  Gem::~Gem(){
    std::cout << "Destorying Gem" << std::endl;  
  }

  std::string Gem::getName() const{
    return name;
  }

  void Gem::cut(){
    if (!polished){
      polished = true;
    }
    Crystal::cut();
  }

  void Gem::display(std::ostream& os) const{
    os << "Name: " << name << " Polished: " << (polished ? "Yes" : "No") << std::endl; 
    Crystal::display(os);
  }

  // Copy assignment operator =
  Gem& Gem::operator=(const Gem& gem){
    if (this != &gem){
      name = gem.name;
      polished = gem.polished;
      return *this; 
    }
    else
      return *this;
  }
}