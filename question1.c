#include <stdio.h>

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

int main(){
    int a, b, number = 23432, number2 = 1324;
    printf ("please enter two numbers:\n");
    scanf("%d%d", &a, &b);
    int game = check_numbers(1234,1324);
    printf("the result of the game is %d\n", game);

    printf("The sum of the 2 numbers %d\n", a+b);
    printf("The difference between the 2 numbers %d\n", a-b);
    printf("The multiply of the 2 numbers %d\n", a*b);
    printf("The factorial of %d is %ld\n", a, factorial(a));
    is_palindrome(number)?printf("the number %d is palindrome\n", number):printf("the number %d is not palindrome\n", number);
    is_ordered(number2)?printf("the number %d is in ascending order\n", number2):printf("the number %d is not in ascending order\n", number2);
    is_prime(a)?printf("the number %d is prime\n", a):printf("the number %d is not prime\n", a);

}