#include <stdio.h>

typedef struct a{
    short int s;
    int c;
    int* i;
} a;

typedef struct b{
    char c;
    double d;
    int s;
} b;

#pragma pack(push,1)

typedef struct c{
    double d;
    int s;
    char c;
} c;

#pragma pack(pop)

int main(){
    printf ("%ld\n", sizeof(a));
    printf ("%ld\n", sizeof(b));
    printf ("%ld\n", sizeof(c));
}