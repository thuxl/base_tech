#include <stdio.h>
#include <iostream>
/*for pointer of function, 2 methods of usage of pointer.*/

using namespace std;


class foo {
public:
	int a;
	foo(int pa=0) : a (pa) {}

	int getA() {return a;} 
};

typedef foo* (*funcp)(int aa);

foo* myfun(int fa)
{
	foo *f=new foo(fa);
	return f;
}

int main()
{
	funcp fp1=myfun;

	foo* f1 = fp1(99);
	foo* f2 = (*fp1)(100);
	printf("f1.a=%d, f2.a=%d\n", f1->getA(), f2->getA());
	return 1;
}
