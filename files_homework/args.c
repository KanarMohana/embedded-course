#include <stdio.h>
#include <string.h>

int Check_parameters(char* _str){
    if (_str == NULL) {
        return -1;   
    }

    if (strlen(_str) < 1) {
        return -1;   
    }

    return 1;   
}

int MyAToI(char* _str, int* _num){
    int result = Check_parameters(_str);
    int sign = 1;
    int digitsNum = 0;
    int curr_digit;
    *_num=0;
    if (result<0 || _num == NULL){
        return -1;
    }
    
    for (int i=0; i<strlen(_str); ++i){
        curr_digit = _str[i];
        
        //skip spaces - could do it as function
        if(_str[i]==' ' && digitsNum==0){
            continue;
        }

        //check sign - could do it as function
        else if(_str[i]=='-' && digitsNum==0){
            sign = -1;
        }
        else if(_str[i]=='+' && digitsNum==0){
            continue;
        }
        else if(curr_digit>=48 && curr_digit<=57){
            *_num = *_num * 10 + (curr_digit-'0');
            digitsNum++;
        }
        //
        else {
            break;
        }
    }
    *_num*=sign;
    return 1; 
}

int main(int argc, char *argv[4]){
    if(argc != 3){
        printf("an argument is missing\n");
    }
    int a, b; 
    MyAToI(argv[1],&a);
    MyAToI(argv[2],&b);
    printf("the sum is %d\n", a+b);
}