#define OK 1
#define NULL_POINTER -1
#define YES 2
#define NO 0

/*
Description - this function takes a string and reverses it
             "abcd" -> "dcba"
Input - a string
Output - OK or ERROR
ERROR - NULL_POINTER
*/
int ReverseStr (char* _str);

/*
Description - this function checks if a string is palindrome 
Input - a string
Output - YES or NO or ERROR
ERROR - NULL_POINTER
*/
int isPalindrome (char* _str);

/*
Description - this function converts from string to int
              "123" -> 123, "  3.14" -> 3, "-44" -> -44, " 123a56" -> 123 ...
Input - a string and a pointer to store the result number
Output - OK or ERROR
ERROR - NULL_POINTER  
*/
int MyAToI(char* _str, int* _num);

/*
Description - this function converts from int to string
              123 -> "123", -345 -> "-345"
Input - an integer and a buffer to store the result string
Output - OK or ERROR
ERROR - NULL_POINTER  
*/
int MyIToA(int _num, char* _buffer);
