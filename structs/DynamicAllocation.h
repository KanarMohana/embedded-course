#ifndef DYNAMIC_ALLOCATION_H
#define DYNAMIC_ALLOCATION_H

#define NULL_ERROR 0
#define OVER_FLOW -1
#define realloc_FAIL -2
#define UNDER_FLOW -3
#define OK 1


typedef struct DynamicArray DynamicArray;


/*
description - creates opject of DynamicArray type with an initial size and a growth factor
INPUT - the size of the dynamic array and the block size (number of elements to grow by when full) 
OUTPUT - pointer to the allocated opject of dynamic array or NULL on failure
*/
DynamicArray* DynamicArrayCreate( int size, int blockSize);


/*
description - Frees all memory associated with the dynamic array:
              first frees the internal buffer, then frees the struct itself.

INPUT - pointer to a dynamic array
*/
void DynamicArrayDestroy( DynamicArray *DynaminArrayPtr);


/*
description - Inserts an element at the end of the dynamic array
              if the array is full, it attempts to grow by dArrayBlockSize
Input - pointer to a dynamic array and a value to insert
OUTPUT - OK or ERROR
ERROR - NULL_ERROR if dArray is NULL 
        OVERFLOW if no growth is allowed and array is full
        realloc_FAIL if the resize failed

*/
int DynamicArrayInsert(DynamicArray *DynamicArrayPtr, int data);


/*
description - removes the last element from the dynamic array and stores it in *data
INPUT- a pointer to a dynamic array and a pointer to int to store the removed value
OUTPUT - OK or ERROR 
ERROR - NULL_ERROR if dArray is NULL 
        UNDERFLOW if no elements in the darray
*/
int DynamicArrayDelete(DynamicArray *DynamicArrayPtr, int* data);


#endif