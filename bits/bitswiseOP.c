#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitwiseOP.h"

#define BIT 4   

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


int bit_count_int(unsigned int x){
    int count = 0;

    // Iterate over all bits in unsigned int
    // sizeof(unsigned int) * BIT is intended to represent number of bits
    for(int i = 0; i < sizeof(unsigned int) * BIT; ++i){
        if (x & (1 << i)){
            count++;
        }
    }
    return count;
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


  
// Prints the binary representation of an unsigned char. 
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


int bitwise_invert(unsigned char _x, unsigned char* _y){
    // Check for NULL pointer
    if(_y == NULL){
        return NULL_POINTER;
    }

    // Bitwise NOT operation
    *_y = ~_x;

    // Print the inverted value in binary
    print_bits(*_y);
    return OK;
}


unsigned char n_rotate(unsigned char _x, int n){
    // Reduce n to range [0..7]
    n = n % 8;
    int curr = 0;

    // Perform right rotation n times
    for (int i = 0; i < n; i++){
        curr = _x & 1;      // Save LSB
        _x >>= 1;           // Shift right
        _x |= (curr << 7);  // Move old LSB to MSB
    }

    // Print rotated value
    print_bits(_x);
    return _x;
}


unsigned char SitBits(unsigned char _x, int _p, int _n, unsigned char _y){
    unsigned char n_bits = 1;
    unsigned char temp = 255; // Unused variable (kept as-is)

    // Build mask with _n ones: (1<<_n)-1
    for(int i = 0; i < _n; i++){
        n_bits *= 2;
    }
    n_bits--;

    // Clear the target bits in _x
    _x &= ~(n_bits << (_p - _n));

    // Extract rightmost _n bits from _y
    n_bits = _y & n_bits;

    // Shift extracted bits into position
    n_bits <<= (_p - _n);

    // Insert bits into _x
    _x |= n_bits;

    // Print result
    print_bits(_x);

    return _x;
}


//Maps letters 'a'..'o' to values 1..15. 
int letter_to_new_lan(char c) {
    if (c < 'a' || c > 'o') return -1;
    return c - 'a' + 1;
}


unsigned char* compress_4bit(const char* s, size_t* out_len_bytes) {
    if (!s || !out_len_bytes) return NULL;

    size_t len = strlen(s);
    size_t bytes = (len + 1) / 2;   // Number of output bytes

    // Allocate zero-initialized buffer
    unsigned char* out = (unsigned char*)calloc(bytes, 1);
    if (!out) return NULL;

    for (size_t i = 0; i < len; i++) {
        int nib = letter_to_new_lan(s[i]);
        if (nib < 0) {
            free(out);
            return NULL;
        }

        // Even index -> store in high nibble
        if ((i & 1) == 0) {
            out[i / 2] |= (unsigned char)(nib << 4);
        }
        // Odd index -> store in low nibble
        else {
            out[i / 2] |= (unsigned char)(nib & 0x0F);
        }
    }

    *out_len_bytes = bytes;
    return out;
}


