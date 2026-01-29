#include <stdio.h>
#include "basicQuestions.h"

long int factorial(int _n){
    if (_n < 0) return -1;

    int fact = 1;
    for(int i=1; i<=_n; i++){
        fact *= i;
    }
    return fact;
}

int reverse_num (int _num){
    int rev = 0;
    while(_num!=0){
        rev = rev * 10 + (_num % 10);
        _num/=10;
    }
    return rev;
}

int is_palindrome(int _num){
    int rev = reverse_num(_num);
    if(_num == rev){
        return 1;
    }
    return 0;
}

int is_ordered (int _num){
    int sec, first;
    while(_num){
        sec = _num%10;
        _num/=10;
        first = _num%10;
        if ((first+1)!=sec){
            return 0;
        }
    }
    return 1;
}

int is_prime(int _num){
    for(int i=2; i<_num/2; i++){
        if (_num%i == 0){
            return 0;
        }
    }
    return 1;
}

int digit_exist(int _num, int digit){
    while(_num){
        if(_num%10 == digit){
            return 1;
        }
        _num/=10;
    }
    return 0;
}

int check_numbers(int _base, int _check){
    int in_place=0, deffirent_places=0;
    int tmp = _base ;
    while(_base){
        if(_base%10 == _check%10){
            in_place++;
        }
        else if(digit_exist(tmp,_check%10)){
            deffirent_places++;
        }
        _base/=10;
        _check/=10;
    }
    return in_place*10 + deffirent_places;
}