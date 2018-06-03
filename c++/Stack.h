#pragma once

class Stack
{
public:
	Stack();
	~Stack();

	int pop();
	void push(int x);
	bool isEmpty();
	void AutoIncrementAry();

private:
	int m_nTop;
	int m_nMaxSize;
	int * m_pData;
};