#include <stdio.h>
#include <iostream>
#include <string.h>
/*for const fun in object of class to change variables. */

using namespace std;


class foo {
public:
	void change(char *p) const;

	int a;

};


void foo::change(char *p) const
{
	//a = 1;
	p[0] = '0';
	p[1] = '1';
	p[2] = '2';
	p[3] = '\0';
}

int main()
{
	char *ptr = new char[20];
	memset(ptr, 0, 20*sizeof (char));
	
	foo f;

	f.change(ptr);


	printf("ptr=%s\n", ptr);
	return 1;
}
