#include <stdio.h>
#include "funcPtr.h"

int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int* Bubble_Sort(int* Arr, int Size, SortCriteria crt){
    for(int i=0; i<Size; ++i){
        int swaps = 0;
        for(int j=0; j<Size-1; ++j){
            if(crt(Arr[j],Arr[j+1])){
                swap(&Arr[j], &Arr[j+1]);
                swaps++;
            }
        }
        if (swaps==0){
            return Arr;
        }
    }
}

