#ifndef BASIC_QUESTIONS_H
#define BASIC_QUESTIONS_H
#define INVALID_INPUT -1

/*
description - Calculates factorial of a number.
input - _n: integer number.
output - factorial of _n, or ERROR.
error - INVALID_INPUT.
*/
long int factorial(int _n);

/*
description - Reverses the digits of a given integer.
input - _num: integer number.
output - reversed integer.
*/
int reverse_num(int _num);

/*
description - Checks whether a number is a palindrome.
input - _num: integer number.
output - 1 if palindrome, 0 otherwise.
*/
int is_palindrome(int _num);

/*
description - Checks if digits of a number are ordered consecutively (ascending by 1).
input - _num: integer number.
output - 1 if digits are ordered, 0 otherwise.
*/
int is_ordered(int _num);

/*
description - Checks whether a number is a prime number.
input - _num: integer number.
output - 1 if prime, 0 otherwise.
*/
int is_prime(int _num);


/*
description - Compares two numbers digit by digit and counts matching digits.
input - _base: base number, _check: number to compare.
output - two-digit number: tens = digits in same place, ones = digits in different place.
error - assumes both numbers have same number of digits.
*/
int check_numbers(int _base, int _check);
