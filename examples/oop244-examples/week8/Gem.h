// Gem.h

#ifndef _GEM_H_
#define _GEM_H_


#include <string>
#include "Crystal.h"

namespace gem_kingdom {

  // Gem is a Crystal
  class Gem : public Crystal {
    std::string name;
    bool polished;
  public:
    // Constructors
    Gem();
    Gem(std::string, int mass, int purity);
    Gem(const Gem&);

    // Member functions
    std::string getName() const;
    void polish();
    void display(std::ostream&) const;
    using Crystal::display;

    // Operator overloads
    Gem& operator=(const Gem&);
    bool operator==(const Gem&) const;

  };

  // Helper
  std::ostream& operator<<(std::ostream&, const Gem&);

}

#endif