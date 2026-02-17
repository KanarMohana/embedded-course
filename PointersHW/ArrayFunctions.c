#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SWAP(a, b, t) \
{\
t temp = a; \
a = b; \
b = temp; \
}

int swap(int* a, int* b);
int* Bubble_Sort(int* Arr, int Size);
int shift(int* arr, int startIDX, int endIDX);
int CHECK_INPUTS(const int* arr, int size);


int* Bubble_Sort(int* Arr, int Size){
    for(int i=0; i<Size; ++i){
        int swaps = 0;
        for(int j=0; j<Size-1; ++j){
            if(Arr[j]>Arr[j+1]){
                SWAP(Arr[j], Arr[j+1],int);
                swaps++;
            }
        }
        if (swaps==0){
            return Arr;
        }
    }
}

int* Bubble_Sort_reg(int* Arr, int Size){
    for(register int i=0; i<Size; ++i){
        int swaps = 0;
        for(register int j=0; j<Size-1; ++j){
            if(Arr[j]>Arr[j+1]){
                swap(Arr[j], Arr[j+1]);
                swaps++;
            }
        }
        if (swaps==0){
            return Arr;
        }
    }
}

int Max_Occurance_Value(int* Arr, int Size){
    int result = CHECK_INPUTS(Arr, Size);
    if(result<0){
        return result;
    }
    int* sorted = Bubble_Sort(Arr, Size);
    int Max_Occur = sorted[0];
    int curr_occurs_num = 0;
    int Max_occurs_num = 0;

    for(int i=0; i<Size; ++i){
        if(sorted[i]==sorted[i-1]){
            curr_occurs_num++;
            if(curr_occurs_num>Max_occurs_num){
                Max_occurs_num = curr_occurs_num;
                Max_Occur = sorted[i];
            }
        } 
        else curr_occurs_num = 0;
    }
    return Max_Occur;
}

int even_then_odd(int* arr, int size) {
    int result = CHECK_INPUTS(arr, size);
    if(result<0){
        return result;
    }
    int temp = arr[0];
    int last_even = 0;
    for (int i=0; i<size; ++i){
        if (arr[i]%2==0){
            temp = arr[i];
            shift(arr, last_even, i);
            arr[last_even]=temp;
            last_even++;
        }
    }
    return last_even;
}

int shift(int* arr, int startIDX, int endIDX){
    for (int i=endIDX; i>startIDX; --i ){
        arr[i]=arr[i-1];
    }
    return 0;
}

int Zeroes_then_Ones(int* arr, int size){
    int result = CHECK_INPUTS(arr, size);
    if(result<0){
        return result;
    }
    int* left=arr;
    int* right=arr+size;
    while(right>left){
        while(*left==0){
            left++;
        }
        while(*right==1){
            right--;
        }
        *left=0;
        *right=1;
        left++;
        right--;
    }
    return 0;
}

int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int print_array(int* arr, int size){
    for(int i=0; i<10; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int CHECK_INPUTS(const int* arr, int size) {
    if (arr == NULL) {
        return -1;   
    }

    if (size <= 0) {
        return -1;   
    }

    return 1;   
}

int* random_arr(int *arr, int size){
    for (int i=0; i<size; i++){
        arr[i] = rand() % (size+1000);
    }
    return arr;
}


