
#include <iostream>
#include <cstring>
using namespace std;

int main(void){

    char s1[] = "1234567890ABCDE";
    char word[] = "abc";

    char s2[6]; // 6 = 5 +1
	
	strncpy(s2, s1, 6-1);  // copy the first 5 characters from s1
	s2[6-1] = '\0';
	
	cout << "1. s2:" << s2 << endl;

	strncpy(s2, word, 6-1);  // copy the first 5 charactes from word
	s2[6-1] = '\0';

	cout << "2. s2:" << s2 << endl;
	return 0;
}
