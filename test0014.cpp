// test0014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
�����ǸĽ��ļ����ط����Ľ���Ĵ����Լ��Ľ����������ĩβ��

1����ת�Ͻ�ĸĽ�����ʵ���ǿ���ͨ��ѡ��ĳ��������ԭʼ���н��з�תʹ֮���򣬼��㷭ת��������ô�����ת����������Ϊ�Ͻ磬��Ϊ���ŵķ����϶�����ȵ�ǰ�ķ�����Ľ��Ĵ�����ѡ�����Ͻ��ķ�ת������������δ��λ���ӱ���ת������Ӧ��λ�ã����������UpBound_case

2����ת�½�ĸĽ�������Ҫ������������������λ���ӱ���С�Ƿ����ڣ���Ҫ��������ձ��Ƿ��λ��������������ձ���������λ�ñ�ȻҪ��תһ��ʹ���λ�������������ձ���λ�ķ�ת���ı����е������ձ��������ԣ������LowerBound������

3��search���Ƿ񳬹��Ͻ�������жϣ�����˵����search������ע�ͣ��������224�� �� 240�У�

4���������Ĺ����У�����ĳ�����У�ԭʼ������ÿ��λ�ö���תһ�Σ��Ľ��󣬶������к����Ѿ��ź����λ�þͲ����з�ת����Ϊ���ź����λ�÷�ת��Ȼ������ٷ�ת������������ͨ��search�����ڶ�������ʵ�֡�

5���ڶ����з�ת������ʱ��Դ�����Ǵӵ�һ��λ�����ε����һ��λ�÷�ת���������Ľ������ǶԷ�תÿ��λ�÷�ת������н���һ�����������������������еľ��룬Ȼ��������������С�����С�����������ʵ����LowerBound����

6�������з�ת������ʱ����ĳ����ת�պ�ʹ����������ô������ת�����϶��ᵼ��������˿��Է�������������ͨ��search�ķ���ֵʵ�֣�������������292��

�Ľ�����ͽ�����£�
*/

#include<cstdio>
#include<cassert>
#include<vector>
#include<algorithm>
struct node
{
    int index;
    int score;
};

bool comp(struct node a, struct node b)
{
    return a.score < b.score;
}

class CPrefixSorting
{
public:

    CPrefixSorting()
    {
        m_nCakeCnt = 0;
        m_nMaxSwap = 0;
        m_CakeArray = NULL;
        m_SwapArray = NULL;
        m_ReverseCakeArray = NULL;
        m_ReverseCakeArraySwap = NULL;
        flag1 = false;
    }

    ~CPrefixSorting()
    {
        releaseAll();
    }

    void releaseAll()
    {
        if( m_CakeArray != NULL )
        {
            delete []m_CakeArray;
            m_CakeArray = NULL;
        }
        if( m_SwapArray != NULL )
        {
            delete []m_SwapArray;
            m_SwapArray = NULL;
        }
        if( m_ReverseCakeArray != NULL )
        {
            delete []m_ReverseCakeArray;
            m_ReverseCakeArray = NULL;
        }
        if( m_ReverseCakeArraySwap != NULL )
        {
            delete []m_ReverseCakeArraySwap;
            m_ReverseCakeArraySwap = NULL;
        }
    }

    //
    // �����ӱ���ת��Ϣ
    // @param
    // pCakeArray    �洢�ӱ���������
    // nCakeCnt    �ӱ�����
    //
    void Run(int* pCakeArray, int nCakeCnt)
    {

        releaseAll();
        Init(pCakeArray, nCakeCnt);

        m_nSearch = 0;
        Search(0, nCakeCnt - 1);
    }

    //
    // ����ӱ����巭ת�Ĵ���
    //
    void Output()
    {
        for(int i = 0; i < m_nMaxSwap; i++)
        {
            printf("%d ", m_SwapArray[i]);
        }

        printf("\n |Search Times| : %d\n", m_nSearch);
        printf("Total Swap times = %d\n\n", m_nMaxSwap);
    }

private:

    //
    // ��ʼ��������Ϣ
    // @param
    // pCakeArray    �洢�ӱ���������
    // nCakeCnt    �ӱ�����
    //
    void Init(int* pCakeArray, int nCakeCnt)
    {
        assert(pCakeArray != NULL);
        assert(nCakeCnt > 0);

        flag1 = false;

        m_nCakeCnt = nCakeCnt;

        // ��ʼ���ӱ�����
        m_CakeArray = new int[m_nCakeCnt];
        assert(m_CakeArray != NULL);
        for(int i = 0; i < m_nCakeCnt; i++)
        {
            m_CakeArray[i] = pCakeArray[i];
        }

        // ��ʼ���м佻�������Ϣ
        m_ReverseCakeArray = new int[m_nCakeCnt];
        for(int i = 0; i < m_nCakeCnt; i++)
        {
            m_ReverseCakeArray[i] = m_CakeArray[i];
        }

        // ������ཻ��������Ϣ
        //m_nMaxSwap = UpBound(m_nCakeCnt);
        m_nMaxSwap = UpBound_case(m_ReverseCakeArray, m_nCakeCnt);
        //UpBound_case��m_ReverseCakeArray�ı���
        //m_ReverseCakeArray��ԭ
        for(int i = 0; i < m_nCakeCnt; i++)
        {
            m_ReverseCakeArray[i] = m_CakeArray[i];
        }

        // ��ʼ�������������
        m_SwapArray = new int[m_nMaxSwap + 1];
        assert(m_SwapArray != NULL);

        m_ReverseCakeArraySwap = new int[m_nMaxSwap];
        assert(m_ReverseCakeArraySwap != NULL);
    }


    //
    // Ѱ�ҵ�ǰ��ת���Ͻ�
    //
    //
    int UpBound(int nCakeCnt)
    {
        return nCakeCnt*2-2;
    }

    //--ÿ�ΰ����ķ�ת�������棬�������ַ�������Ҫ�Ĵ���
    //--��������б��淭ת�������Ϊ���ַ������ܾ�����С��ת�����ķ���
    //--�������������Ϊ��ת�������Ͻ�
    int UpBound_case(int* pCakeArray, int nCakeCnt)
    {
        int re = 0;
        for (int j = nCakeCnt - 1 ; ;)
        {
            while(j > 0 && j == pCakeArray[j])
                --j;
            if (j <= 0)
                break;
            int i = j;
            while (i >= 0 && pCakeArray[i] != j)
                --i;
            if (i != 0)
            {
                Revert(pCakeArray, 0, i);
                re++;
            }
            Revert(pCakeArray, 0, j);
            re++;
            --j;
        }
        return re;
    }

    //
    // Ѱ�ҵ�ǰ��ת���½�
    //
    //
    int LowerBound(int* pCakeArray, int nCakeCnt)
    {
        int t, ret = 0;

        // ���ݵ�ǰ�����������Ϣ������ж�������Ҫ�������ٴ�
        for(int i = 1; i < nCakeCnt; i++)
        {
            // �ж�λ�����ڵ������ӱ����Ƿ�Ϊ�ߴ����������ڵ�
            t = pCakeArray[i] - pCakeArray[i-1];
            if((t == 1) || (t == -1))
            {
            }
            else
            {
                ret++;
            }
        }
        //--��������ӱ��������һ��λ�ã���Ҫ�෭תһ��
        if (pCakeArray[nCakeCnt-1] != nCakeCnt-1) ret++;
        return ret;
    }

    //--����������������һ�����У�����������״̬����ķ�ת����Խ�٣��÷�Խ��
    //--����������״̬����ķ�ת����Խ�࣬�÷�Խ��
    //--����ʱ�������������÷��ٵ����У������ܾ���ﵽ���Ž�
    int Evaluate(int* pCakeArray, int nCakeCnt)
    {
        return LowerBound(pCakeArray, nCakeCnt);
    }

    // �����������
    //--��endBound+1 ���ձ�������ź���û�б�Ҫ���ź���Ľ��н���
    //--��Ϊ�����Ѿ��ź�����ձ�ֻ��ʹ������������
    //--�����ǰ�����������ź����򷵻�true�����򷵻�false
    bool Search(int step, int endBound)
    {
        int i, nEstimate;

        m_nSearch++;

        // ���������������Ҫ����С��������
        nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);

        //--����������Σ������ڷ�ת����Ϊm_nMaxSwap�Ľ���Ѿ����棬���̼�����
        //--�����������Ϳ��������ˣ���Ϊ��Ը÷�ת�����Ľ���Ѿ����棬
        //�����ټ���
        if(step + nEstimate == m_nMaxSwap && flag1 == false);
        else if(step + nEstimate >= m_nMaxSwap)
            return false;

        //���¼����ź����λ��
        int k = endBound;
        while(k > 0 && k == m_ReverseCakeArray[k])
            --k;

        // ���k=0,˵���Ѿ��ź��򣬼���ת��ɣ�������
        //if(IsSorted(m_ReverseCakeArray, m_nCakeCnt))
        if(k == 0)
        {
            if(step < m_nMaxSwap)
            {
                //--��ǰ�ҵ���һ����
                m_nMaxSwap = step;
                for(i = 0; i < m_nMaxSwap; i++)
                    m_SwapArray[i] = m_ReverseCakeArraySwap[i];
            }
            else if(step == m_nMaxSwap && flag1 == false)
            {
                //--ֻ�е�һ������step == m_nMaxSwapʱ�������²���
                //--��Ϊm_nMaxSwap��������С��ת���������Ҫ��¼�˴ν��
                //--�������������ʱ�����Ժ��ԣ���Ϊ�����ظ�������
                for(i = 0; i < m_nMaxSwap; i++)
                    m_SwapArray[i] = m_ReverseCakeArraySwap[i];
                flag1 = true;
            }
            return true;
        }

        // �ݹ���з�ת,k֮���Ѿ��ź����λ�þͲ��÷�ת��
        std::vector<node> swapIndexScore;
        //�Է�ת������н���������������������õ�����֮��ľ��룬������������С������
        for(i = 1; i <=k; i++)
        {
            struct node tnode;
            tnode.index = i;
            tnode.score = nEstimate;//ԭʼ���еķ���
            //��ת��ķ�������ת��ֻ�з�תλ��Ӱ������Ĵ�С
            if(i != m_nCakeCnt - 1)
            {
                if(abs(m_ReverseCakeArray[i] - m_ReverseCakeArray[i+1]) == 1)
                    tnode.score++;
                if(abs(m_ReverseCakeArray[0] - m_ReverseCakeArray[i+1]) == 1)
                    tnode.score--;
            }
            else
            {
                if(m_ReverseCakeArray[i] == i)tnode.score++;
                if(m_ReverseCakeArray[0] == i)tnode.score--;
            }
            swapIndexScore.push_back(tnode);
        }
        //���յ÷�С�������򣬵÷�С����������
        sort(swapIndexScore.begin(), swapIndexScore.end(),comp);

        for(i = 0; i < swapIndexScore.size() ; i++)
        {
            Revert(m_ReverseCakeArray, 0, swapIndexScore[i].index);
            m_ReverseCakeArraySwap[step] = swapIndexScore[i].index;
            bool isDone = Search(step + 1, k);
            Revert(m_ReverseCakeArray, 0, swapIndexScore[i].index);
            //�������������������ô������ת�����϶��ᵼ��������˲���Ҫ����
            if(isDone == true)break;
        }

//        for(i = 1; i <=k ; i++)
//        {
//            Revert(m_ReverseCakeArray, 0, i);
//            m_ReverseCakeArraySwap[step] = i;
//            Search(step + 1, k);
//            Revert(m_ReverseCakeArray, 0, i);
//        }
        return false;
    }
    //
    // true : �Ѿ��ź���
    // false : δ����
    //
    bool IsSorted(int* pCakeArray, int nCakeCnt)
    {
        for(int i = 1; i < nCakeCnt; i++)
        {
            if(pCakeArray[i-1] > pCakeArray[i])
            {
                return false;
            }
        }
        return true;
    }

    //
    // ��ת����
    //
    void Revert(int arry[], int nBegin, int nEnd)
    {
        assert(nEnd > nBegin);
        int i, j, t;

        // ��ת����
        for(i = nBegin, j = nEnd; i < j; i++, j--)
        {
            t = arry[i];
            arry[i] = arry[j];
            arry[j] = t;
        }
    }

private:

    int* m_CakeArray;    // �ӱ���Ϣ����
    int m_nCakeCnt;    // �ӱ�����
    int m_nMaxSwap;    // ��ཻ������������ǰ����ƶϣ��������Ϊ
    // m_nCakeCnt * 2
    int* m_SwapArray;    // �����������

    int* m_ReverseCakeArray;    // ��ǰ��ת�ӱ���Ϣ����
    int* m_ReverseCakeArraySwap;    // ��ǰ��ת�ӱ������������
    int m_nSearch;    // ��ǰ����������Ϣ
    bool flag1;//--���ʼ�����m_nMaxSwap����С��ת����ʱ������¼�������ת��
               //���,flag1 = ture������Ϊfalse�����search����
};

int main()
{
    CPrefixSorting a;
    //int cakeArry[] = {3,2,1,6,5,4,9,8,7,0};
    //int cakeArry1[] = {12,3,2,1,11,6,5,10,4,9,8,7,0};
    int cakeArry2[] = {2,0,1};
    //a.Run(cakeArry, sizeof(cakeArry) / sizeof(int));
    //a.Output();
    //a.Run(cakeArry1, sizeof(cakeArry1) / sizeof(int));
    //a.Output();
    a.Run(cakeArry2, sizeof(cakeArry2) / sizeof(int));
    a.Output();
    return 0;
}

