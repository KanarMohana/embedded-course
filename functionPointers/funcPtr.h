#ifndef __FUNC_PTR_H__
#define __FUNC_PTR_H__

typedef int(*SortCriteria)(int _first, int _second);

int* Bubble_Sort(int* Arr, int Size, SortCriteria crt);

#endif