#include <stdio.h>
#include <iostream>
#include <string.h>
/*for beauty of programming 1-8. */

using namespace std;


class CPrefixSorting {
public:
	CPrefixSorting ()
	{
		m_nCakeCnt = 0;   //烙饼个数
		m_nMaxSwap = 0;   //最多交换次数: m_nCakeCnt * 2
	}
	~CPrefixSorting ()
	{
		if (m_CakeArray != NULL)
			delete m_CakeArray ; 
		if (m_SwapArray != NULL)
			delete m_SwapArray ; 
		if (m_ReverseCakeArray != NULL)
			delete m_ReverseCakeArray ; 
		if (m_ReverseCakeArraySwap != NULL)
			delete m_ReverseCakeArraySwap ; 
	}
	void Run (int* pCakeArray, int nCakeCnt)
	{
		Init (pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search (0);
	}
	void Output ()
	{
		for (int i = 0; i < m_nMaxSwap; i++)
			printf("%d ", m_SwapArray[i]);
		printf("\n Search Times: %d\n", m_nSearch);
		printf("Total Swap Times: %d\n", m_nMaxSwap);
	}

private:
	void Init(int* pCakeArray, int nCakeCnt)
	{
		assert (pCakeArray != NULL);
		assert (nCakeCnt  > 0);
		
		m_nCakeCnt = nCakeCnt;
		m_CakeArray = new int [m_nCakeCnt];
		assert (m_CakeArray != NULL);
		for (int i = 0; i < m_nCakeCnt; i++)
			m_CakeArray [i] = pCakeArray[i];
		
		m_nMaxSwap = UpperBound(m_nCakeCnt);
		
		m_SwapArray = new int [m_nCakeCnt + 1];
		assert (m_SwapArray != NULL);

		m_ReverseCakeArray = new int [m_nCakeCnt];
		assert (m_ReverseCakeArray != NULL);
		for (int i = 0; i < m_nCakeCnt; i++)
			m_ReverseCakeArray [i] = m_CakeArray [i];

		m_ReverseCakeArraySwap = new int [m_nCakeCnt];
		assert (m_ReverseCakeArraySwap != NULL);

	}

	int UpperBound (int nCakeCnt)
	{
		return nCakeCnt * 2;
	}
private:
	int* m_CakeArray;  //烙饼信息数组
	int  m_nCakeCnt;   //烙饼个数
	int  m_nMaxSwap;   //最多交换次数: m_nCakeCnt * 2
	int* m_SwapArray;  //交换结果数组

	int* m_ReverseCakeArray;        //当前反转烙饼 信息 数组
	int* m_ReverseCakeArraySwap;    //当前反转烙饼 交换结果 数组
	int  m_nSearch;                 //当前搜索次数信息

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
