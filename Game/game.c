#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int digit_exist(int dig, int num){
    while(num>0){
        if(num%10 == dig){
            return 1;
        }
        num/=10;
    }
    return 0;
}

int get_randome_number(void){
    int num=0;
    int digit;
    while (num<1000){
        digit = rand()%10;

        if(digit==0 && num==0){
            continue;
        }

        if(digit_exist(digit,num)==0){
            num = (num*10)+digit;
        }
    }
    return num;
}

int check_numbers(int _base, int _check){
    int in_place=0, deffirent_places=0;
    int tmp = _base ;
    while(_base){
        if(_base%10 == _check%10){
            in_place++;
        }
        else if(digit_exist(_check%10,tmp)){
            deffirent_places++;
        }
        _base/=10;
        _check/=10;
    }
    for(int i=0; i<in_place; i++){
        printf("*");
    }
    //printf(" ");
    for(int i=0; i<deffirent_places; i++){
        printf("x");
    }
    printf("\n");
    return in_place*10 + deffirent_places;
}

int play_game(void){
    int base = get_randome_number();
    int check;
    printf("enter a 4 digit number\n");
    scanf("%d",&check);

    while (check_numbers(base,check)!=40){
        printf("enter a 4 digit number\n");
        scanf("%d",&check);
    }
}

int main(){
    play_game();
}

