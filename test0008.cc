#include <stdio.h>
#include <string>
#include <iostream>
/* for test pointer declaration.*/
/*  use gdb. */


int main ()
{
	float(**a)[10];
	double*(*b)[10];
	double(*c[10])();
	int* (*d)[10];
	long (*e)(int);
	int(*(*f)(int, int))(int);
	

	printf("sizeof: a=%d, b=%d, c=%d.\n", sizeof(a), sizeof(b), sizeof(c));
	printf("sizeof: d=%d, e=%d, f=%d.\n", sizeof(d), sizeof(e), sizeof(f));

	return 0;
}
