#include "stdafx.h"
#include "MySort.h"
#include <assert.h>

MySort::MySort()
{
	m_nTop = -1;
	m_nCount = 10;
	m_pData = new int[m_nCount];
}

MySort::~MySort()
{
	uninitAry();
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

int MySort::getCount()
{
	return m_nCount;
}

int* MySort::initAry(int n)
{
	assert(m_pData != NULL);
	m_nCount = n;
	m_pData = new int[n];
	for (int i = 0; i < n; i++)
	{
		m_pData[i] = -100000000;
	}
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
