#include <stdio.h>

float avgFunc(int arr[], int size);

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    printf("The average of the array's values is %f", avgFunc(arr, 10));
}

float avgFunc(int arr[], int size){
    int sum=0;
    for(int i=0; i<size; ++i){
        sum+=arr[i];
    }
    return sum/size;
}