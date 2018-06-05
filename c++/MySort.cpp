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
