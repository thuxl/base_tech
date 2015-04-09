#include <stdio.h>
#include <string>
#include <iostream>
/* for test pointer of array.*/


int main ()
{
	
	int a[]={100,200,300,400,500};
	int *p1= (int *)(&a+1);
	printf("%d, %d\n", *(a+1), *(p1-1));

	int b[2][5] = {1,2,3,4,5,6,7,8,9,10};
	int *p2= (int *)(&b[0]);
	int *p3= (int *)(&b);
	int *p4= (int *)(&b+1);
	//int *p5= (int *)(&(b+1)); //error!!
	printf("*b:%p, **(b+1):%d, *(int*)(*(&b+1)):%d, *b[0]:%d,*(b[0]+1):%d\n", *b, **(b+1), *(int*)(*(&b+1)), *b[0], *(b[0]+1));
	printf("*p2=&b[0]:%d, *(p2+1):%d \n", *p2, *(p2+1));
	printf("*p3=&b:%d, *(p3+1):%d\n", *p3, *(p3+1));
	printf("*p4=&b+1:%d, *(p4-1):%d\n", *p4, *(p4-1));


	return 0;
}
