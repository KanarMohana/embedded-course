#include <stdio.h>
#include "bitwiseOP.h"

int main(){
    unsigned char y;

    // Bit counting examples
    printf("unsigned char - %d\n", bit_count_char(2));
    printf("unsigned bit - %d\n", bit_count_int(7));

    // Print binary representation
    print_bits(255);

    // Bitwise inversion
    bitwise_invert(75, &y);

    // Rotate right
    y = n_rotate(75, 3);

    // Set selected bits
    SitBits(170, 6, 3, 167);

    // 4-bit compression example
    const char* input = "abocde";

    size_t packed_len = 0;
    unsigned char* packed = compress_4bit(input, &packed_len);

    printf("Input: %s (len=%zu)\n", input, strlen(input));
    printf("Packed bytes (%zu):\n", packed_len);

    for (size_t i = 0; i < packed_len; i++) {
        printf("  byte[%zu] = ", i);
        print_bits(packed[i]);
        printf("  (0x%02X)\n", packed[i]);
    }
}