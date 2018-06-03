#include "stdafx.h"
#include "Stack.h"
#include <assert.h>

Stack::Stack()
{
	m_nTop = -1;
	m_nMaxSize = 10;
	m_pData = new int[m_nMaxSize];
}

Stack::~Stack()
{
	if (m_pData != NULL)
	{
		delete m_pData;
		m_pData = NULL;
	}
}

int Stack::pop()
{
	assert(m_pData != NULL);
	assert(!isEmpty());
	return m_pData[m_nTop--];
}

void Stack::push(int x)
{
	m_nTop++;
	AutoIncrementAry();
	assert(m_pData != NULL);
	m_pData[m_nTop] = x;
}

bool Stack::isEmpty()
{
	return m_nTop < 0?true:false;
}

void Stack::AutoIncrementAry()
{
	if (m_nTop >= (m_nMaxSize*0.75))
	{
		m_nMaxSize *= 2;
		assert(m_pData != NULL);
		int * pData = new int[m_nMaxSize];
		for(int i = 0;i <m_nTop;i++)
		{
			//assert(pData != NULL && m_pData != NULL );
			//*pData++ = *m_pData++;
			pData[i] = m_pData[i];
			m_pData[i] = NULL;
		}
		if (pData != NULL && m_pData != NULL)
		{
			m_pData = pData;
		}
	}
}
