#include <stdio.h>
#include <string>
#include <iostream>
/* for test sizeof */

class A{public:
	bool a;
	int b;
	bool c;
};
class B{public:
	int a;
	bool b;
	bool c;
};

class C{};

class D{
	public:
		D(){printf("hello\n");}
};
class E{
	public:
		E(){printf("hello\n");}
		//int printd(){printf("world\n");}
		virtual void f() {std::cout<<"E:f"<<std::endl;}
		virtual void f1() {std::cout<<"E:f1"<<std::endl;}
};
int main ()
{
	char a;
	char b[]="123";
	void *p;
	double *pp;
	std::string ss[]={"123456", "123456789"};
	
	printf("\tsizeof(char)=%d,sizeof(a)=%d,sizeof(b)=%d\n", sizeof(char), sizeof(a), sizeof(b) );
	printf("\tsizeof(int)=%d,sizeof(short)=%d,sizeof(long)=%d\n", sizeof(int), sizeof(short), sizeof(long) );
	printf("\tsizeof(unsigned int)=%d,sizeof(bool)=%d,sizeof(unsigned long)=%d\n", 
			sizeof(unsigned int), sizeof(bool), sizeof(unsigned long) );
	printf("\tsizeof(long long)=%d,sizeof(void)=%d,sizeof(void *)=%d\n", sizeof(long long), sizeof(void), sizeof(p) );
	printf("\tsizeof(float)=%d,sizeof(double)=%d,sizeof(long double)=%d\n", sizeof(float), sizeof(double), sizeof(long double) );
	printf("\tsizeof(double *)=%d\n", sizeof(pp) );
	printf("----\n\tsizeof(class A)=%d,sizeof(class B)=%d, sizeof(class C)=%d, sizeof(class D)=%d, sizeof(class E)=%d\n", 
			sizeof(A), sizeof(B),sizeof(C),sizeof(D), sizeof(E));
	printf("\tsizeof(string)=%d,sizeof(ss)=%d\n", sizeof(std::string), sizeof(ss));

  return 0;
}
//g++ test0001.cc -o ptest0001
