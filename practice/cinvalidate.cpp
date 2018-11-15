// data type validation

#include <iostream>
using namespace std;

int main(void) {

    double x;
    int    ok;

    do {
	ok = 1;

	cin >> x;

	/* data type validation */
	if ( cin.fail() != 0 ) {
	   ok = 0;   // NOT ok

	   cout << "invalid data format!\n";

	   cin.clear();              // reset cin from the failure state
	   cin.ignore(2000, '\n');   // remove the data left in the
				     // input stream
	}

    } while ( !ok );

    cout << "x: " << x << endl;

}
