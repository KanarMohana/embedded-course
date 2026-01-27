#ifndef __BITWISEOP_H__
#define __BITWISEOP_H__

#define OK 0
#define NULL_POINTER -1


/*
description - Reverses the order of bits in an unsigned char.
              00000110 -> 01100000
INPUT - unsigned char x
OUTPUT - the reversed char
*/
unsigned char reverse_bits(unsigned char x);

/*
 description - Inverts all bits of _x and stores the result in *_y.
 INPUT - unsigned char x and a space in memory to store the result
 OUTPUT - OK or ERROR 
 ERROR - NULL_POINTER 
*/
int bitwise_invert(unsigned char _x, unsigned char* _y);


/*
description - Rotates an unsigned char to the right by n positions. 
INPUT - unsigned char x and a number that we want to rotate by
OUTPUT - the rotated char
*/
unsigned char n_rotate(unsigned char _x, int n);


/*
description - Sets _n bits in _x starting at position _p using the rightmost _n bits of _y
INPUT - _x : the char we want to change
        _p : the position in _x we want to start from 
        _n : number of bits we want to replace
        _y : the char that we take the replacement from
OUTPUT - updatd char
*/
unsigned char SitBits(unsigned char _x, int _p, int _n, unsigned char _y);


/*
description - Compresses a string so that each character takes only 4 bits. 
              Two characters are packed into one byte.
INPUT - s : pointer to a null-terminated string to compress
        out_len_bytes : pointer to a variable that will store the length
                        (in bytes) of the compressed output
OUTPUT - pointer to a dynamically allocated buffer containing the compressed data
*/
 unsigned char* compress_4bit(char* s, size_t* out_len_bytes);

#endif