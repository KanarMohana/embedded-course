#include <stdio.h>
#include "StringsHW.h"

int main(){
    char myStr[] = "abcdef";
    char myStr2[] = "abcba";
    char myNum[] = "abc22";
    int numtoAToI ;
    int restoAToI = MyAToI(myNum, &numtoAToI);
    int int2str = -128;
    char store_buffer[30];
    int restoIToA = MyIToA(int2str, store_buffer);
    int checkpali = isPalindrome(myStr);
    int checkpali2 = isPalindrome(myStr2);
    int reversed = ReverseStr(myStr);
    printf ("the reversed version of my string is : %s\n", myStr);
    printf ("checking if %s is palindrome : %d\n", myStr, checkpali);
    printf ("checking if %s is palindrome : %d\n", myStr2, checkpali2);
    printf("my string to int is %d\n",myStr[0]);
    printf("the int of str %s is %d\n", myNum, numtoAToI);
    printf("the string of %d is '%s'\n", int2str, store_buffer);
}