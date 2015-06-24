// virtual_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class a1{
	virtual void func();
};
class b1:public virtual a1
{
	virtual void foo();
};

class a2{
	virtual void func();
};
class b2:public  a2
{
	virtual void foo();
};

class a3{
	virtual void func();
	char x;
};
class b3:public virtual a3
{
	virtual void foo();
};

class a4{
	virtual void func();
	char x[7];
};
class b4:public  a4
{
	char y[2];
	virtual void foo();
};


class AA{
	char k[3];
public:
	virtual void aa();
};
class BB:public virtual AA
{
	char j[3];
public:
	virtual void bb();
};
class CC:public virtual BB
{
	char i[3];
public:
	virtual void cc();
};

int main(int argc, _TCHAR* argv[])
{
	cout << "sizeof(a1)=" <<sizeof(a1)<<", sizeof(b1)="<<sizeof(b1)<<endl;
	cout << "sizeof(a2)=" <<sizeof(a2)<<", sizeof(b2)="<<sizeof(b2)<<endl;
	cout << "sizeof(a3)=" <<sizeof(a3)<<", sizeof(b3)="<<sizeof(b3)<<endl;
	cout << "sizeof(a4)=" <<sizeof(a4)<<", sizeof(b4)="<<sizeof(b4)<<"\n"<<endl;

	cout << "sizeof(AA)=" <<sizeof(AA)<<", sizeof(BB)="<<sizeof(BB)<<endl;
	cout << "sizeof(CC)=" <<sizeof(CC)<<"\n"<<endl;
	return 0;
}

