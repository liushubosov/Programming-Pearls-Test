#include "stdafx.h"
#include "MySort.h"
#include <assert.h>

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
	if (m_pData != NULL)
	{
		delete m_pData;
		m_pData = NULL;
	}
}

//冒泡排序
void MySort::BubbleSort()
{
	int n = getCount();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i; j++)
		{
			int nTmp = m_pData[j];
			if (m_pData[j] > m_pData[j + 1])
			{
				m_pData[j] = m_pData[j + 1];
				m_pData[j + 1] = nTmp;
			}
		}
	}
}

//插入排序
void MySort::InsertSort()
{
	int n = getCount();
	for (int i = 1; i < n; i++)
	{
		int key = m_pData[i];
		//m_pData[0...i-1] 为已排序的数组，剩余的 m_pData[i...n] 为未排序的数组
		//m_pData[0...i-1] 的性质表示为一个循环不变式
		/**
		循环不变式三条性质：
			初始化：循环的第一次迭代前，它为真
			保持：如果循环的某次迭代之前它为真，那么下次迭代之前它仍为真
			终止：在循环终止时，不变式为我们提供了一个有用的性质，该性质有助于证明
				算法是正确的
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

//选择排序
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

//快速排序
void MySort::QuickSort(int low,int high)
{
	int l = low;
	int r = high;
	int key = m_pData[r];
	if (l >= r)
		return;

	while (l < r)
	{
		while (l < r && m_pData[l] <= key) //1.m_pData[l] == key，也要自增，不然有可能无限循环
			l++;
		m_pData[r] = m_pData[l];

		while (l < r && m_pData[r] >= key)//2.同1
			r--;
		m_pData[l] = m_pData[r];
	}
	m_pData[r] = key;

	int medium = (r - l) / 2;
	QuickSort(l, medium - 1);
	QuickSort(medium + 1, r);
}

//合并两个已排序的数组
void MySort::Merge(int * ary, int l, int m, int r)
{
	int nL = m - l + 1;
	int nR = r - m;

	int * aryL= new int[nL+1];
	int * aryR = new int[nR+1];
	for (int i = 0; i < nL; i++)
	{
		aryL[i] = ary[l + i-1];
	}

	for (int j = 0; j < nR; j++)
	{
		aryR[j] = ary[m + j];
	}

	aryL[nL + 1] = 0XFFFE;
	aryR[nR + 1] = 0XFFFE;

	int i = 0, j = 0;
	for (int k = l; k < r+1; k++)
	{
		if (aryL[i] <= aryR[j])
		{
				ary[k] = aryL[i];
				i++;
		}
		else
		{
				ary[k] = aryR[j];
				j++;
		}		
	}
}

void MySort::MergeSort(int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSort(l,m);
		MergeSort(m + 1, r);
		Merge(m_pData,l,m,r);
	}

}



