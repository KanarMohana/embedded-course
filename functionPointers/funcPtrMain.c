#include <stdio.h>
#include "funcPtr.h"

int up (int first, int sec){
    if(first>sec){
        return 1;
    }
    return 0;
}

int down (int first, int sec){
    if(first<sec){
        return 1;
    }
    return 0;
}

int sum_dig (int first, int sec){
    int sum1=0, sum2=0;
    while(first){
        sum1 += first%10;
        first /= 10;
    }
    while(sec){
        sum2 += sec%10;
        sec /= 10;
    }
    return sum1>sum2?1:0;
}

int ones_digit(int first, int sec){
    if(first%10 > sec%10){
        return 1;
    }
    return 0;
}

int print_array(int* arr, int size){
    for(int i=0; i<10; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {10,22,54,16,87,45,13,99,17,33};
    int *sorted_arr = Bubble_Sort(arr, sizeof(arr)/sizeof(arr[0]), up);
    print_array(sorted_arr, sizeof(arr)/sizeof(arr[0]));
    int *sorted_arr2 = Bubble_Sort(arr, sizeof(arr)/sizeof(arr[0]), down);
    print_array(sorted_arr2, sizeof(arr)/sizeof(arr[0]));
    int *sorted_arr3 = Bubble_Sort(arr, sizeof(arr)/sizeof(arr[0]), sum_dig);
    print_array(sorted_arr3, sizeof(arr)/sizeof(arr[0]));
    int *sorted_arr4 = Bubble_Sort(arr, sizeof(arr)/sizeof(arr[0]), ones_digit);
    print_array(sorted_arr4, sizeof(arr)/sizeof(arr[0]));
}

