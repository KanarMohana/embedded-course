#include <stdio.h>


void func1(int num, char c){
    int i,j;
    for(i=1; i<=num; ++i){
        for(j=0; j<i; ++j){
            printf("%c", c);
        }
        printf("\n");
    }
}

void func2(int num, char c){
    int i,j;
    for(i=num; i>=0; --i){
        for(j=0; j<i; ++j){
            printf("%c", c);
        }
        printf("\n");
    }
    return ;
}

void func3(int num, char c){
    int i,j;
    for(i=0; i<=num; ++i){
        for(j=0; j<i; ++j){
            printf("%c", c);
        }
        printf("\n");
    }
    for(i=num; i>=0; --i){
        for(j=0; j<i; ++j){
            printf("%c", c);
        }
        printf("\n");
    }
    return ;
}

void func4(int num, char c){
    int i,j,k;

    for(i=1; i<=num; ++i){
        for(k=num-i; k>=0; --k){
            printf(" ");
        }
        for(j=0; j<i; ++j){
            
            printf(" %c ", c);
        }
        printf("\n");
    }
    return ;
}

void func5(int num, char c){
    int i,j,k;

    for(i=num; i>=0; --i){
        for(k=0; k<num-i; ++k){
            printf(" ");
        }
        for(j=0; j<i; ++j){
            
            printf(" %c ", c);
        }
        printf("\n");
    }
    return ;
}

void func6(int num, char c){
    int i,j,k;
    for(i=1; i<=num; ++i){
        for(k=num-1-i; k>=0; --k){
            printf(" ");
        }
        for(j=0; j<i; ++j){
            
            printf(" %c ", c);
        }
        printf("\n");
    }

    for(i=num-1; i>=0; --i){
        for(k=0; k<num-i; ++k){
            printf(" ");
        }
        for(j=0; j<i; ++j){
            
            printf(" %c ", c);
        }
        printf("\n");
    }
    return ;
}


