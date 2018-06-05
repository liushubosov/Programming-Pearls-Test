#pragma once

class MySort
{
public:
	MySort();
	~MySort();

	void BubbleSort();
	void InsertSort();
	int getCount();
	int* initAry(int n);
	void uninitAry();

private:
	int m_nTop;
	int m_nCount;
	int * m_pData;
};