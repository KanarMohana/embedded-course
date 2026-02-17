#include <stdio.h>
#include <string.h>

int MyStrLen(char* str);

int MyStrLen(char* str){
    int charctr=0;
    while(*str != '\0'){
        charctr++;
        str++;
    }
    return charctr;
}

char* MyStrCat(char* str1, char* str2){
    int len1 = MyStrLen(str1);
    int len2 = MyStrLen(str2);
    int i = 0;

    while(i<len2){
        str1[len1+i]=str2[i];
        ++i;
    }
    str1[len1+len2+1]='\0';
    return str1;
}

int MyStrCmp(char* str1, char* str2){
    int len1 = MyStrLen(str1);
    int len2 = MyStrLen(str2);
    int minlen = len1<len2?len1:len2;
    for(int i=0; i<minlen; ++i){
        if(str1[i]>str2[i]){
            return 1;
        }
        else if(str1[i]<str2[i]){
            return -1;
        }
    }
    if(len1==len2){
        return 0;
    }
    return 1;
}

int main(){
    char myStr[20] = "kanar";
    char myStr2[] = "mohana";
    char mystr3[] = "mohar";
    int len = MyStrLen(myStr);
    printf("the len with our func is %d\n", len);
    int len2= strlen(myStr);
    printf("the len with the original function is %d\n", len2);
    char* funcat = strcat(myStr, myStr2);
    printf("the original func cat is %s\n", funcat);
    char* mycat= MyStrCat(myStr, myStr2);
    printf("my concatenate string is %s\n", mycat);
    int mycmp = MyStrCmp(myStr2, mystr3);
    printf("the result of the comparation is %d\n", mycmp);


}