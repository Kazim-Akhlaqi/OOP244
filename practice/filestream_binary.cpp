/* Binary Access */

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5

/* Linux command line: a.out raccess.dat
   DOS command line: filestream_binary raccess.dat */

int main(int argc, char* argv[]) {


    int    num[MAX] =  { 100, 200, 300, 400, 500 };
    double v[MAX] =    { 1.11, 2.22, 3.33, 4.44, 5.55 };

    // fixed-length strings
    char   s[MAX][8] =   { "John123", "Peter12", "Mark123", 
			   "Matthew", "Joseph1" };

    ofstream outputFile;

    outputFile.open( argv[1], ios::out|ios::binary );  // file name
						       // open mode:
						       //  ios::out, ios::binary


    if ( outputFile.fail() ) {  // query the state of the file stream
				// (e.g. argv[1] is an empty string)

	 cerr << "Failure in opening a file" << endl;
	 exit(1);
    }

	for (int k=0; k<MAX; k++) {

		 outputFile.write( (char*) (&num[k]), sizeof(num[k]) ); 
				   // why &num[k]?
				   // write a block of data, byte by byte
				   //    - the address of the block of data
				   //    - total number of bytes

		 outputFile.write( (char*) (&v[k]), sizeof(v[k]) );

		 outputFile.write( (char*) (s[k]), sizeof(s[k]) );
		  //cout << "sizeof a string: " << sizeof(s[k]) << " " << s[k] << endl;
		  /* char * p = s[k];
			    outputFile.write( (char*) p, sizeof(s[k]) );
		   */
     }
	 outputFile.close();

     cout << "... output file closed\n... open an input file\n";

     // binary read
     ifstream inputFile( argv[1], ios::in|ios::binary );

     if (!inputFile){
		   cerr << "Failure in opening a file" << endl;
	       exit(1);
	 }

     bool exit = false;

	 while (!exit){
		 int q;
		 double z;
		 char str[8];

		 inputFile.read( (char*) &q, sizeof(int) );  
					     // total number of bytes
		 inputFile.read( (char*) &z, sizeof(double) );
		 inputFile.read( str, 8); 
				      // total number of bytes for a fixed-size string

		 if (!inputFile.fail())  // EOF condition; if (!inputFile)
			cout << q << "," << z << "," << str << endl;

		 else exit = true;
	 }
	 inputFile.close();

     return 0;
} // end main
