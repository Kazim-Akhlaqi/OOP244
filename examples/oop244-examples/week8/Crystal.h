// Crystal.h

#ifndef _CRYSTAL_H_
#define _CRYSTAL_H_

#define BASE_MASS 500
#define BASE_PURITY 60

#include <iostream>

namespace gem_kingdom {

  class Crystal {
    int mass;
    int purity;
  public:
    // Constructors
    Crystal();
    Crystal(int, int);

    // Member functions
    void display(std::ostream&) const;
    void display(std::ostream&, const char* c) const;

    // Protected Member functions
  protected:
    void cut();
    int getMass();
    int getPurity() const;
  };
}

#endif 
