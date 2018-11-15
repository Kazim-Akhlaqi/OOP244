// Crystal.cpp

#include <iostream>
#include "Crystal.h"

namespace gem_kingdom {

  Crystal::Crystal() {
    mass = BASE_MASS;
    purity = BASE_PURITY;
  }

  Crystal::Crystal(int m, int p) {

    mass = m > 0 ? m : BASE_MASS;
    purity = p > 0 ? p : BASE_PURITY; 
  }

  Crystal::~Crystal(){
    std::cout << "Destroying Crystal" << std::endl;
  }

  int Crystal::getMass() const {
    return mass;
  }

  void Crystal::cut(){
    int cutMass = mass - 20;

    if (cutMass > 0){
      mass = cutMass;
      purity += 5;
    }

  }

  int Crystal::getPurity() const{
    return purity;
  }

  void Crystal::display(std::ostream& os) const {

    os << "Mass: " << mass << " Purity: " << purity << std::endl;
  }
}

