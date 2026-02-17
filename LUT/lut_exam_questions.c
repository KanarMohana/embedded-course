#include <stdio.h>
#define BITS_OPTIONS 256

int bit_count_char(unsigned char x){
    int count = 0;

    for(int i = 0; i < 8; ++i){
        // Check if bit i is set
        if (x & (1 << i)){
            count++;
        }
    }
    return count;
}

int BuildCountBitLUT(unsigned int* table){
    for (int i=0; i<BITS_OPTIONS; i++){
        table[i] = bit_count_char(i);
    }
    return 0;
}

int CountBit(unsigned char _num){
    static unsigned int countBitLUT[BITS_OPTIONS] ;
    static int flag = 0;

    if (!flag)
    {
        BuildCountBitLUT(countBitLUT) ;
        flag = 1 ;
    }
    return countBitLUT[_num] ;
}

int CountBit_uint(unsigned int x)
{
    int counter = 0;

    for (int i = 0; i < sizeof(unsigned int); ++i)
    {
        counter += CountBit(x & 0xFF);
        x >>= 8;
    }

    return counter;
}
