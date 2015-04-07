#include <stdio.h>
#include <string>
#include <iostream>
/* for test pointer of function */

int max(int x, int y)
{
	return x>y?x:y;
}


int main ()
{
	//int max(int, int);
	int (*p) (int, int) = &max;

	int a = 20, b = 6, c = 10, d;

	d = (*p) ((*p)(a,b), c);
	printf("among a=%d, b=%d, c=%d, the max=%d\n", a,b,c,d);

	return 0;
}
