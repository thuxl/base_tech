#include <stdio.h>
#include <string>
#include <iostream>
#include <typeinfo>
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
	int *p6= (int*)*b;
	//int *p5= (int *)(&(b+1)); //error!!
	printf("*b:%p, **(b+1):%d, *(int*)(*(&b+1)):%d, *b[0]:%d,*(b[0]+1):%d\n", *b, **(b+1), *(int*)(*(&b+1)), *b[0], *(b[0]+1));
	printf("*p2=&b[0]:%d, *(p2+1):%d \n", *p2, *(p2+1));
	printf("*p3=&b:%d, *(p3+1):%d\n", *p3, *(p3+1));
	printf("*p4=&b+1:%d, *(p4-1):%d\n", *p4, *(p4-1));
	printf("*p6=*b:%d, *(p6+1):%d\n", *p6, *(p6+1));
	printf("typeid(b)=%s\n", typeid(b).name());
	printf("typeid(&b)=%s\n", typeid(&b).name());
	printf("typeid(b[0])=%s\n", typeid(b[0]).name());


	char* c[]={"hello", "the", "world"};
	char** p5=c;
	p5++;
	printf("*p5=c,p5++=%s, *(p5+1)=%s\n", *p5, *(p5+1));
	printf("*c=%s, *(c+1)=%s\n", *c, *(c+1));
	printf("typeid(c)=%s\n", typeid(c).name());
	printf("typeid(&c)=%s\n", typeid(&c).name());
	printf("typeid(p5)=%s\n", typeid(p5).name());



	return 0;
}
