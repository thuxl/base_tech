#include <stdio.h>
#include <string>
#include <iostream>
/* for test sizeof */



char* str1()
{
	char *str = "hello word";       //global
	return str;
}
char* str2()
{
	static char str[] = "hello word"; //local with static
	return str;
}
char* str3()
{
	char str[] = "hello word"; //local
	return str;
}


int main ()
{
	char *str_1 = str1();
	//str_1[0] = '0'; //wrong!!
	printf("*str_1=%s\n", str_1);
	
	char *str_2 = str2();
	str_2[0] = '0';
	printf("*str_2=%s\n", str_2);

	char *str_3 = str3();
	//str_3[0] = '0'; //wrong!!
	printf("*str_3=%s\n", str_3);

	char b[]= "hello";
	b[0]='0';
	printf("*b=%s\n", b);

	char *a= "hello world";
	//*a='0'; a[1]='1'; //wrong!!
	printf("*a=%s\n", a);

}
