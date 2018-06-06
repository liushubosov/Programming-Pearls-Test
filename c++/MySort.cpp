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

//ð������
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
	int l = low;
	int r = high;
	int key = m_pData[r];
	if (l >= r)
		return;

	while (l < r)
	{
		while (l < r && m_pData[l] <= key) //1.m_pData[l] == key��ҲҪ��������Ȼ�п�������ѭ��
			l++;
		m_pData[r] = m_pData[l];

		while (l < r && m_pData[r] >= key)//2.ͬ1
			r--;
		m_pData[l] = m_pData[r];
	}
	m_pData[r] = key;

	int medium = (r - l) / 2;
	QuickSort(l, medium - 1);
	QuickSort(medium + 1, r);
}


