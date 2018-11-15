// Input/Output File 
// File Objects - writing and reading
// fstream.cpp

 #include <iostream>
 #include <fstream>
 using namespace std;

 /* fstream object
    - read AND write
  */

 int main(int argc, char* argv[]) {

     fstream f(argv[1], ios::in|ios::out|ios::trunc);
			      // bitwise OR operator
			      // ios::trunc - If the file already exists,
			      // its content is destroyed.

			      // 1. writing to a file

     f << "Line 1" << endl;   // line 1
     f << "Line 2" << endl;   // line 2
     f << "Line 3" << endl;   // line 3

     f.seekp(0, ios::beg);    // to the start of the file
     f << "****";             // overwrite four characters

     f.seekp(4, ios::cur);    // 4 bytes beyond current
     f << "#";                // overwrite one character

     streampos p = f.tellp(); // remember current position

     f.seekp(0, ios::end);    // to end of the file
     f << "The last line\n";  // add a line

     f.seekp(p);              // jump back to p
     f << "^";                // overwrite one character

			      // 2. reading from the same file
     char c;
     f.seekg(0, ios::beg);    // to the start of the file

     while ( f.get(c) )       // read 1 character at a time
	 cout << c;           // display the character

     f.clear();               // clear the failed (eof) state

     f.seekg(-8, ios::end);   // move 8 bytes from end

     while (f.get(c))         // read 1 character at a time
	 cout << c;           // display the character read
     f.clear();               // clear failed (eof) state

     return 0;
 }



























