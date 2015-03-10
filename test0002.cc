#include <iostream>
#include <deque>
#include <stdio.h>
/* for test printf params*/

int main ()
{

	int i = 0,j=0;
  printf("i, i++, i++, ++i, ++i:%d, %d, %d, %d, %d\n", 
		  i, i++, i++, ++i, ++i);
  printf("j, j++, j++, j++, j++:%d, %d, %d, %d, %d\n", 
		  j, j++, j++, j++, j++);
  return 0;
}
//g++ test0001.cc -o ptest0001
