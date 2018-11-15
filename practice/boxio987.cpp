
 // customize the cin extraction operator

 #include <iostream>
 using namespace std;  // remove this line for better design

 class Box {

   char symbol;
   int  v, h;

   public:

      Box(char c, int a, int b) { symbol=c; v=a; h=b; }
      Box() { symbol='*'; v=h=7; }

   friend ostream& operator << ( ostream &, const Box & );

   friend istream& operator >> ( istream & , Box & );
 };

ostream& operator <<( ostream &  os, const Box & rhs){

     os << " vertical dimension: " << rhs.v
      << " horizontal dimension: " << rhs.h << endl;

   for (int i=0; i< rhs.v; i++){

      for (int j=0; j< rhs.h; j++)

	      os << rhs.symbol;

      os << endl;
   }

   os << endl;
   return os;
}

 istream& operator >>( istream& is, Box& box ) {

     bool ok;
     int number;
     char x;

     cout << "Enter a character used for drawing the box: ";
     is  >> x;

     box.symbol = x;

     // get two integers

     for (int i=1; i<=2; i++) {

	ok = false;

	do {
		cout << "Enter an integer: ";
		is   >> number;

		if ( is.fail() ) { // invalid data format

		 is.clear();             /* clear error flags */
		 is.ignore(2000,'\n');   /* clear the input buffer */
		 cerr << "... it is not an integer" << endl;  /* error message stream */

		} else if( number <= 0 ) {

			   cerr << "... the integer must be positive" << endl;

		} else { ok = true;  // valid data

			 if( is.get() != '\n' )

			     is.ignore(2000,'\n'); // remove trailing characters
		    } // end else

	 } while (!ok);

	 if (i==1) box.v = number;
	 if (i==2) box.h = number;

     } // end for

     return is;
 }

 int main ( ) {

     Box z;

     cin >> z;

     cout << "Here is the box" << endl << z;

     return 0;
 }




