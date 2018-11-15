// Crystal.h

#ifndef _CRYSTAL_H_
#define _CRYSTAL_H_

#define BASE_MASS 500
#define BASE_PURITY 60

#include <iostream>
#include "iCrystal.h"

namespace gem_kingdom {

  class Crystal : public iCrystal {
    int mass;
    int purity;
  public:
    // Constructors
    Crystal();
    Crystal(int, int);
    virtual ~Crystal();

    // Member functions
    void display(std::ostream&) const;

    // Protected Member functions
  protected:
    void cut();
    int getMass() const;
    int getPurity() const;
  };
}

#endif 
