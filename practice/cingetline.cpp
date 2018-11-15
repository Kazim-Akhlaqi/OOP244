// use of cin.getline() to avoid
// skipping whitespace

// The user could enter a) less than 1-10 characters and b) more than 10 characters.


#include <iostream>
using namespace std;

int main(void)
{
 char name[11];

 for ( int i=0; i < 2; i++ ) {
      cout << "Enter a line of characters(max:10):" << endl;

      cin.getline(name, 11, '\n');   // '\n' is NOT left in the input stream
				     // default delimiter

      cout << "\tYou have entered:" << name << endl;

      /* clear the buffer if it is not empty */
      if (cin.fail() == 1){
	  cin.clear();
	  cin.ignore(2000, '\n');
      }
 }
 return 0;
}
