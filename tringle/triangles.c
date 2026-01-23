#include <stdio.h>
#include "triangles.h"
#define MAX_SIZE 100
#define MIN_SIZE 1
#define MAX_CHAR '~'
#define MIN_CHAR '!'


int Check_parameters(int lines ,char char2print)
{
	if (lines > MAX_SIZE || lines < MIN_SIZE )
	{
		return SIZE_ERROR;
	}
	if (char2print < MIN_CHAR || char2print > MAX_CHAR)
	{
		return	CHAR_TO_PRINT_ERROR;
	}
	return OK; 
}

int Print_line(int length ,char char2print)
{
	  for (int j = 0 ; j < length ;j++ )
	  {
            printf("%c",char2print);
	  }
      printf("\n");
      return 0;
}



int print_left_aligned_triangle(int lines_num, char char2print){
    int i;
    for(i=1; i<=lines_num; ++i){
        Print_line(i, char2print);
        printf("\n");
    }
    return OK;
}

int Print_backward_lift_triangle(int lines_num, char char2print){
    int i;
    for(i=lines_num; i>=0; --i){
        Print_line(i, char2print);
        printf("\n");
    }
    return OK;
}

int Print_half_diamond(int lines_num, char char2print){
    print_left_aligned_triangle(lines_num , char2print);
    Print_backward_lift_triangle(lines_num-1, char2print);
}

//TODO: make sure that after " " its not gitting into a new line
int print_triangle(int lines_num, char char2print){
    int i;

    for(i=1; i<=lines_num; ++i){
        Print_line(lines_num-i, ' ');
        Print_line(i, char2print);
        printf("\n");
    }
    return OK;
}

void func5(int num, char c){
    int i,j,k;

    for(i=num; i>=0; --i){
        for(k=0; k<num-i; ++k){
            printf(" ");
        }
        for(j=0; j<i; ++j){
            
            printf(" %c ", c);
        }
        printf("\n");
    }
    return ;
}

void func6(int num, char c){
    int i,j,k;
    for(i=1; i<=num; ++i){
        for(k=num-1-i; k>=0; --k){
            printf(" ");
        }
        for(j=0; j<i; ++j){
            
            printf(" %c ", c);
        }
        printf("\n");
    }

    for(i=num-1; i>=0; --i){
        for(k=0; k<num-i; ++k){
            printf(" ");
        }
        for(j=0; j<i; ++j){
            
            printf(" %c ", c);
        }
        printf("\n");
    }
    return ;
}


