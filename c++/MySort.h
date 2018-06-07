#pragma once

class MySort
{
public:
	MySort();
	~MySort();

	void BubbleSort();
	void InsertSort();
	void SelectSort();
	void QuickSort(int low, int high);
	//BEGIN COMMENT, ADD, 2018/06/07
	void Merge(int* ary, int l, int m, int r);
	void MergeSort(int l, int r);
	//END COMMENT, ADD, 2018/06/07

	int getCount();
	int* initAry(int n);
	void uninitAry();

private:
	int m_nTop;
	int m_nCount;
	int * m_pData;
};