#include <stdio.h>
#include <string.h>
#include "StringsHW.h"

int Check_parameters(char* _str);

int Check_parameters(char* _str){
    if (_str == NULL) {
        return -1;   
    }

    if (strlen(_str) < 1) {
        return -1;   
    }

    return 1;   
}

int ReverseStr (char* _str){
    int left=0;
    int right=strlen(_str)-1;
    int result = Check_parameters(_str);
    int temp = _str[0];
    if(result<0){
        return result;
    }
    while(left<right){
        //change it to swap function
        temp=_str[left]; 
        _str[left]=_str[right];
        _str[right] = temp;
        ++left;
        --right;
    }
    return 0;
}

int isPalindrome (char* _str){
    int result = Check_parameters(_str);
    int left = 0;
    int right = strlen(_str)-1;
    if (result < 0){
        return result;
    }
    while(left<right){
        if(_str[left]!=_str[right]){
            return 0;
        }
        ++left;
        --right;
    }
    return OK;
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

int MyIToA(int _num, char* _buffer){
    if (_buffer == NULL){ 
        return NULL_POINTER;
    }
    int curr_digit;
    int digitsNum = 0;
    int temp = _num;
    int sign = 0;

    if(_num ==0){
        _buffer[0] = '0';
        _buffer[1] = '\0';
        return OK;
    }

    if (_num < 0) {
        sign = 1;
        _num = -_num; 
        temp = _num;
        _buffer[0] = '-';
    }

    while(temp/10!=0){
        digitsNum++;
        temp = temp/10;
    }
    _buffer[digitsNum+1+sign]='\0';
    while(_num/10!=0){
        curr_digit=_num%10;
        _buffer[digitsNum+sign]=(curr_digit+'0');
        digitsNum--;
        _num = _num/10;
    }
    _buffer[digitsNum + sign] = (char)((_num % 10) + '0');

    return OK;
}

