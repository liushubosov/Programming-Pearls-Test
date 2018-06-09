#include "stdafx.h"
#include "MySort.h"
#include <assert.h>
#include "iostream"
using namespace std;


MySort::MySort()
{
	m_nTop = -1;
	m_nCount = 10;
}

MySort::~MySort()
{
	uninitAry();
}

int MySort::getCount()
{
	return m_nCount;
}

int* MySort::initAry(int n)
{
	m_nCount = n;
	m_pData = new int[n];
	return m_pData;
}

void MySort::uninitAry()
{
	if (m_pData)
	{
		delete m_pData;
		m_pData = NULL;
	}
}

//ð������
void MySort::BubbleSort()
{
	int n = getCount();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			int nTmp = m_pData[j];
			assert((j + 1) < n);
			if (m_pData[j] > m_pData[j + 1])
			{
				m_pData[j] = m_pData[j + 1];
				m_pData[j + 1] = nTmp;
			}
		}
	}
}

//��������
void MySort::InsertSort()
{
	int n = getCount();
	for (int i = 1; i < n; i++)
	{
		int key = m_pData[i];
		//m_pData[0...i-1] Ϊ����������飬ʣ��� m_pData[i...n] Ϊδ���������
		//m_pData[0...i-1] �����ʱ�ʾΪһ��ѭ������ʽ
		/**
		ѭ������ʽ�������ʣ�
			��ʼ����ѭ���ĵ�һ�ε���ǰ����Ϊ��
			���֣����ѭ����ĳ�ε���֮ǰ��Ϊ�棬��ô�´ε���֮ǰ����Ϊ��
			��ֹ����ѭ����ֹʱ������ʽΪ�����ṩ��һ�����õ����ʣ�������������֤��
				�㷨����ȷ��
		**/
		int j = i - 1;		
		while (key < m_pData[j] && j > 0)
		{
			m_pData[j + 1] = m_pData[j];
			j--;
		}
		m_pData[j + 1] = key;
	}
}

//ѡ������
void MySort::SelectSort()
{
	int n = getCount();
	for (int i = 0; i < n; i++)
	{
		int min = m_pData[i];
		int minIndex = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (min > m_pData[j])
			{
				min = m_pData[j];
				minIndex = j;
			}				
		}
		if (minIndex > 0)
		{
			m_pData[minIndex] = m_pData[i];
			m_pData[i] = min;
		}
	}
}

//��������
void MySort::QuickSort(int low,int high)
{
	if (low >= high)
		return;
	int l = low;
	int r = high-1;	
	int key = m_pData[high];

	while (l < r)
	{
		while (l < r && m_pData[l] < key) //1.m_pData[l] == key��ҲҪ��������Ȼ�п�������ѭ��
			l++;
		while (l < r && m_pData[r] >= key)
			r--;
		std::swap(m_pData[l], m_pData[r]);
	}

	if (m_pData[l] >= key)
	{
		std::swap(m_pData[l], m_pData[high]);
	}
	else
		l++;

	QuickSort(low, l-1);
	QuickSort(l + 1, high);
}

//�ϲ����������������
void MySort::Merge(int * ary, int l, int m, int r)
{
	int nL = m - l + 1;
	int nR = r - m;

	int * aryL= new int[nL+1];
	int * aryR = new int[nR+1];
	for (int i = 0; i < nL; i++)
	{
		aryL[i] = ary[l + i];
	}

	for (int j = 0; j < nR; j++)
	{
		aryR[j] = ary[m + j + 1];
	}

	aryL[nL] = 0XFFFE;
	aryR[nR] = 0XFFFE;

	int i = 0, j = 0;
	for (int k = l; k < r+1; k++)
	{
		int x = aryL[i];
		int y = aryR[j];
		if (x <= y || y == 0XFFFE)
		{
				ary[k] = x;
				i++;
		}
		else
		{
				ary[k] = y; 
				j++;
		}		
	}
	delete aryL;
	delete aryR;
}

void MySort::MergeSort(int l, int r)
{
	if (l < r)
	{
		assert(l >= 0 && r > 0 && l < r);
		int m = (l + r) / 2;
		MergeSort(l,m);
		MergeSort(m + 1, r);
		Merge(m_pData,l,m,r);
	}
}



