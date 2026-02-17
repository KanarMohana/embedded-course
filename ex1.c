#include <stdio.h>

int Add(int _a, int _b)
{
	int sum;

	sum = _a + _b;
	return sum;
}

int Sub(int _a, int _b)
{
	return _a - _b;
}

int main(void)
{
	int sum, dif;

	sum = Add(7, 3);
	dif = Sub(7, 3);

	printf("%d + %d = %d\n", 7, 3, sum);
	printf("%d - %d = %d\n", 7, 3, dif);

	return 0;
}