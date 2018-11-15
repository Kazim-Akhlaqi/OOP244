// a simple demo on overloading ostream << operator
// 1998 ANSI standard

#include <iostream>
//using namespace std; // design choice

class Box {
   char symbol;
   int  v, h;

   public:
      Box(char c, int a, int b) { symbol=c; v=a; h=b; }
      Box() { symbol='*'; v=h=7; }

   friend std::ostream&  operator << ( std::ostream &, const Box & );
};

std::ostream& operator <<( std::ostream &  os, const Box & rhs){
   
     os << " vertical dimension: " << rhs.v
	<< " horizontal dimension: " << rhs.h << std::endl;

    for (int i=0; i< rhs.v; i++){
       for (int j=0; j< rhs.h; j++)
	      os << rhs.symbol;

      os << std::endl;
   }

   os << std::endl;

   return os;
}

int main(){

 Box One, Two('#', 4, 10);

 std::cout << Two;

 std::cout << One  << Two;

 return 0;
}



















