#include <stdio.h>
#define BITS_OPTIONS 256

int print_bits(unsigned char _x){
    int bit = 0;
    int bits_number = 0;

    if (_x == 0) {
        printf("00000000");
        return 0;
    }

    // Print bits starting from MSB by shifting left
    while(_x){
        bit = (_x & (1 << 7)) ? 1 : 0;  // Extract MSB
        printf("%d", bit);
        _x <<= 1;                       // Shift left
        bits_number++;
    }

    // Print remaining zeros to complete 8 bits
    while(bits_number != 8){
        printf("0");
        bits_number++;
    }

    printf("\n");
    return 0;
}

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

int BuildCountBitLUT(char* table){
    for (int i=0; i<BITS_OPTIONS; i++){
        table[i] = bit_count_char(i);
    }
}

int CountBit(unsigned char _num){
    static char countBitLUT[BITS_OPTIONS] ;
    static int flag ;

    if (!flag)
    {
        BuildCountBitLUT(countBitLUT) ;
        flag = 1 ;
    }
    return countBitLUT[_num] ;
}

int CountBit_int(int _num){
    int counter = 0;
    while (_num){
        counter += CountBit(_num&0xFF);
        _num = _num >> 8;
    }
    return counter;
}

unsigned char reverse_bits(unsigned char x){
    unsigned char res = 0;

    // Process all 8 bits
    for (int i = 0; i < 8; i++) {
        // Shift result left to make room for the next bit
        res <<= 1;

        // Copy the least significant bit of x into res
        res |= (x & 1);

        // Shift x right to get the next bit
        x >>= 1;
    }
    return res;
}

int BuildReverseBitLUT(char* table){
    for(int i=0; i< BITS_OPTIONS; i++){
        table[i] = reverse_bits(i);
    }
    return 0;
}

int ReverseBit(unsigned char _num){
    static char ReverseBitLUT[BITS_OPTIONS] ;
    static int flag ;

    if (!flag)
    {
        BuildReverseBitLUT(ReverseBitLUT) ;
        flag = 1 ;
    }
    return ReverseBitLUT[_num] ;
}

int main(){
    unsigned char num = 7;
    printf("%d\n", CountBit(num));
    printf("%d\n", CountBit_int(23));
    print_bits(ReverseBit(1));

}







