#include <stdio.h>
int is_little_Endean(void){
    int i=1;
    char *ptr = (char*)&i;
    return *ptr;
}

int main(){
    printf("%d\n", is_little_Endean());
}