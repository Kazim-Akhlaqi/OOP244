 // Dynamic Memory Allocation
 // matrix: g++ -std=c++0x dynamic_mem2_w17.cpp
 
 #include <cstring>
 #include <iostream>
 #include <iomanip>
 using namespace std;

 struct Student{
    int number;
    float marks[2];
 };

 void show (const Student&);

 int main(void) {

     Student* students = nullptr; // 1. Declare a pointer
     int size;

     cout << "Enter the number of students : ";
     cin >> size;

     // 2. Allocate an array of structures dynamically (i.e. at run time)
     students = new Student[size]; 

     for (int i = 0; i < size; i++) {
	  cout << "Student Number: ";
	  cin  >> students[i].number;

	  cout << "Student Marks 1: ";
	  cin  >> students[i].marks[0];

	  cout << "Student Marks 2: ";
	  cin  >> students[i].marks[1];
     }

     for (int i = 0; i < size; i++) {
	  cout << students[i].number << ": "
	       << fixed << setprecision(2) 
	       << students[i].marks[0] << ", " 
	       << students[i].marks[1]
	       << endl;
     }

     // Part 2: C++ reference parameters
     show( students[size-1] );

     // 3. Deallocate memory storage (to avoid memory leaks)
     delete [] students;
     students = nullptr;

     return 0;
 }

 void show( const Student& sref ){

      //sref.number = -2222;
      cout << "Using an unmodifieable C++ reference parameter" << endl;
      cout << "student number: " << sref.number << endl;

     

      cout << "student marks #1: " << sref.marks[0] << endl;
      cout << "student marks #2: " << sref.marks[1] << endl;

      // sref.number = -1111;
      // sref.marks[0] = 0.0;
 }
				   
