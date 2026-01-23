#define OK 0
#define SIZE_ERROR -1
#define CHAR_TO_PRINT_ERROR -2

/*
DESCRIPTION - The function prints a num size aligned triangle
                *
                **
                ***
Input - The number of lines in the triangle (must be between 1 and 100) 
        The chatacter we want to print
OutPut - OK or ERROR
ERROR - SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int print_left_aligned_triangle(int lines_num, char char2print);

/*
DESCRIPTION - The function prints a backwards num size aligned triangle
                ***
                **
                *
Input - The number of lines in the triangle (must be between 1 and 100) 
        The chatacter we want to print 
OutPut - OK or ERROR
ERROR - SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_backward_lift_triangle(int lines_num, char char2print);

/*
DESCRIPTION - The function prints the right half of diamond num size 
                *
                **
                ***
                **
                *
Input - The number of lines in the diamond (must be between 1 and 100) 
        The chatacter we want to print 
OutPut - OK or ERROR
ERROR - SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_half_diamond(int lines_num, char char2print);

/*
DESCRIPTION - The function prints a num size triangle
                  *
                 * *
                * * *
Input - The number of lines in the triangle (must be between 1 and 100) 
        The chatacter we want to print 
OutPut - OK or ERROR
ERROR - SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int print_triangle(int lines_num, char char2print);


void func5(int num, char c);
void func6(int num, char c);