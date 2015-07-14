// test0015.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <typeinfo>
using namespace std;

class base{
public:
	virtual void funcA() {cout << "base" << endl;}
};
class derived: public base
{
public:
	virtual void funcB(){cout<<"derived"<<endl;}
};

void funcC(base *p)
{
	derived *dp = dynamic_cast<derived*>(p);
	if (dp != NULL)
		dp->funcB();
	else
		p->funcA();
}
void funcD(base *p)
{
	derived *dp = NULL;
	if (typeid(*p)==typeid(derived))
	{
		dp = static_cast<derived*>(p);
		dp->funcB();
	}
	else
		p->funcA();
}


int main(int argc, _TCHAR* argv[])
{
	base *cp = new derived;
	cout<< typeid(cp).name() <<endl;
	cout<< typeid(*cp).name() <<endl;
	funcD(cp);
	funcC(cp);
	base *dp=new base;
	funcC(dp);
	funcD(dp);
	
	return 0;
}

