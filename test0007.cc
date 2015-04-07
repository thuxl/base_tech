#include <stdio.h>
#include <string>
#include <iostream>
/* for test struct to fix num of digit*/

struct {
	unsigned char a:4;
	unsigned char b:4;
}i;

struct {
	unsigned char a;
	unsigned char b;
}j;

struct {
	unsigned int a:64;
	unsigned int b:64;
}a;

struct {
	unsigned int a;
	unsigned int b;
}b;

int main ()
{
	printf("sizeof(i)=%d,  sizeof(j)=%d\n", sizeof(i),  sizeof(j) );
	printf("sizeof(a)=%d,  sizeof(b)=%d\n", sizeof(a),  sizeof(b) );

	return 0;
}
