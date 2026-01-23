#include <stdio.h>
#include "triangles.h"

int main(){
    printf("output of function 1:\n");
    print_left_aligned_triangle(4, '*');
    printf("\noutput of function 2:\n");
    Print_backward_lift_triangle(4, '*');
    printf("\noutput of function 3:\n");
    Print_half_diamond(4, '*');
    printf("\noutput of function 4:\n");
    print_triangle(4, '*');
    printf("\noutput of function 5:\n");
    func5(4, '*');
    printf("\noutput of function 6:\n");
    func6(4,'*');
    return 0;
}