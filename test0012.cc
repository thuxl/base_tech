#include <stdio.h>
#include <iostream>
#include <string.h>
/*for beauty of programming 1-8. */

using namespace std;


class CPrefixSorting {
public:
	CPrefixSorting ()
	{
	}

private:
	int* m_CakeArray;  //烙饼信息数组
	int  m_nCakeCnt;   //烙饼个数
	int  m_nMaxSwap;   //最多交换次数: m_nCakeCnt * 2

}


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
