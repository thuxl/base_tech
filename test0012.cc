#include <stdio.h>
#include <iostream>
#include <string.h>
#include <assert.h>
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
			delete [] m_CakeArray ; 
		if (m_SwapArray != NULL)
			delete [] m_SwapArray ; 
		if (m_ReverseCakeArray != NULL)
			delete [] m_ReverseCakeArray ; 
		if (m_ReverseCakeArraySwap != NULL)
			delete [] m_ReverseCakeArraySwap ; 
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

		m_ReverseCakeArraySwap = new int [m_nMaxSwap];
		assert (m_ReverseCakeArraySwap != NULL);

	}

	int UpperBound (int nCakeCnt)
	{
		return nCakeCnt * 2;
	}

	int LowerBound (int* pCakeArray, int nCakeCnt)
	{
		int t, ret=0;

		for (int i = 1; i<nCakeCnt; i++)
		{
			t = pCakeArray [i] - pCakeArray [i-1];
			if (t==1 || t==-1) {}
			else 			   ret++;
		}
		return ret;
	}
	int LowerBound2 (int nCakeCnt)
	{
		return 15*nCakeCnt/14;
	}

	void Search (int step)
	{
		int i, nEstimate;
		m_nSearch++;

		nEstimate = LowerBound (m_ReverseCakeArray, m_nCakeCnt);
		//nEstimate = LowerBound2 (m_nCakeCnt);
		if (step + nEstimate > m_nMaxSwap)
			return ;

		if (IsSorted(m_ReverseCakeArray, m_nCakeCnt))
		{
			if (step < m_nMaxSwap)
			{
				m_nMaxSwap = step;
				for (i=0; i<m_nMaxSwap; i++)
					m_SwapArray [i] = m_ReverseCakeArraySwap [i];
				Output ();
			}
			else{
				cout << "get result, but too many steps:"<<step<<">=max:"<<m_nMaxSwap<<". ";
				for (i=0; i<step; i++)
					cout<< m_ReverseCakeArraySwap [i]<<" ";
				cout<<endl;
			}
			
			return;
		}
		for (i=1; i<m_nCakeCnt; i++)
		{
			Reverse(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Reverse(0, i);
		}
	}


	bool IsSorted(int* pCakeArray, int nCakeCnt)
	{
		for (int i=1; i<nCakeCnt; i++)
			if ( pCakeArray[i-1] > pCakeArray[i] )
				return false;
		return true;
	}
	
	void Reverse(int nBegin, int nEnd)
	{
		assert (nEnd > nBegin);
		int i, j, t;

		for (i = nBegin, j=nEnd; i<j; i++, j--)
		{
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
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



int main()
{
	CPrefixSorting  ob_cps;
	//int cakes [10] = {3, 2, 1, 6, 5, 4, 9, 8, 7, 0};
	//ob_cps.Run(cakes, 10);
	int cakes [3] = {3, 1, 2};
	ob_cps.Run(cakes, 3);


	return 1;
}
