#include <stdio.h>
#include <stdlib.h>
#include "DynamicAllocation.h"
#define NULL_ERROR 0
#define OVER_FLOW -1
#define realloc_FAIL -2
#define UNDER_FLOW -3
#define OK 1


struct DynamicArray{
    int *dArray;
    int dArraySize;
    int dArrayBlockSize;
    int NumOfElements;
} ;


DynamicArray* DynamicArrayCreate( int size, int blockSize) {
    DynamicArray *dynamicStruct;

    if(size<0){
        return NULL;
    }
    if(size==0 && blockSize==0){
        return NULL;
    }

    if((dynamicStruct = (DynamicArray*)malloc(sizeof(DynamicArray)))==NULL){
        return NULL;
    }
    dynamicStruct->dArraySize=size;
    dynamicStruct->dArrayBlockSize=blockSize;
    dynamicStruct->NumOfElements=0;

    if((dynamicStruct->dArray = (int*)malloc(size * sizeof(int)))==NULL){
        free(dynamicStruct);
        return NULL;
    }
    return dynamicStruct;
}

void DynamicArrayDestroy( DynamicArray *DynaminArrayPtr) {
    if(DynaminArrayPtr == NULL){ return; }

    free(DynaminArrayPtr->dArray);
    free(DynaminArrayPtr);
}

int DynamicArrayInsert(DynamicArray *DynamicArrayPtr, int data) {
    if(DynamicArrayPtr == NULL){return NULL_ERROR; }
    if(DynamicArrayPtr->NumOfElements == DynamicArrayPtr->dArraySize){
        if(DynamicArrayPtr->dArrayBlockSize == 0){
            return OVER_FLOW;
        }
        int *temp;
        int newSize = DynamicArrayPtr->dArraySize + DynamicArrayPtr->dArrayBlockSize;
        temp = (int*)realloc(DynamicArrayPtr->dArray, newSize * sizeof(int));

        if (temp != NULL)
        {
            DynamicArrayPtr->dArray = temp;
            DynamicArrayPtr->dArraySize = newSize;
        } else {return realloc_FAIL; }
    } 
    DynamicArrayPtr->dArray[DynamicArrayPtr->NumOfElements] = data;
    DynamicArrayPtr->NumOfElements++;
    return OK;
}

int DynamicArrayDelete(DynamicArray *DynamicArrayPtr, int* data) {
    if(DynamicArrayPtr == NULL){return NULL_ERROR; }
    if(data == NULL){return NULL_ERROR; }
    if(DynamicArrayPtr->NumOfElements == 0){return UNDER_FLOW; }

    *data = DynamicArrayPtr->dArray[DynamicArrayPtr->NumOfElements-1];
    DynamicArrayPtr->NumOfElements--; 
    return OK;
}

