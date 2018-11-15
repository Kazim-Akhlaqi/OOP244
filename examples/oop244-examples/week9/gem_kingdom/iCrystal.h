// iCrystal.h - Abstract Base Class
#ifndef _HELLO_HAPPY_CAT_
#define _HELLO_HAPPY_CAT_
//#ifndef _I_CRYSTAL_H_
//#define _I_CRYSTAL_H_

#include <iostream>

namespace gem_kingdom {

  class iCrystal {
    public:
      ~iCrystal() { std:: cout << "Destroying iCrystal" << std::endl; }
      virtual void display(std::ostream &) const = 0;
      virtual void cut() = 0;
      virtual int getMass() const = 0;
      virtual int getPurity() const = 0;
  };

} // namespace

#endif