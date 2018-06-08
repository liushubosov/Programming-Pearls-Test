// MySortTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <stdlib.h>
#include <time.h> 
#include "MySort.h"
#include <assert.h>
using namespace std;

int main()
{
	int RandomNumber;
	srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。  
	int n = 2;
	int* aryNN;
	int* aryRaw = new int[n];

	MySort * mySort = new MySort();
	aryNN = mySort->initAry(n);
	assert(aryNN != NULL);
	for (int i = 0; i < n; i++)
	{
		RandomNumber = rand() % 2001 -1000;//生成1~100随机数
		aryNN[i] = RandomNumber;
		//aryRaw[i] = RandomNumber;
		cout << RandomNumber << endl;
	}

	clock_t startTime, endTime;
	//startTime = clock();
	//mySort->BubbleSort();
	//endTime = clock();
	//cout << "|BubbleSort Time : " << (double)(endTime  - startTime)/ CLOCKS_PER_SEC << endl;

	//memcpy(aryNN, aryRaw, n*4);
	//startTime = clock();
	//mySort->InsertSort();
	//endTime = clock(); 
	//cout << "|InsertSort Time : " << (double)(endTime  - startTime)/ CLOCKS_PER_SEC << endl;

	//memcpy(aryNN, aryRaw, n*4);
	//startTime = clock();
	//mySort->SelectSort();
	//endTime = clock();
	//cout << "|SelectSort Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

	//memcpy(aryNN, aryRaw, n*4);
	//startTime = clock();
	//mySort->QuickSort(0,n-1);
	//endTime = clock();
	//cout << "|QuickSort Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

	//memcpy(aryNN, aryRaw, n*4);
	startTime = clock();
	mySort->MergeSort(0,n-1);
	endTime = clock();
	cout << "|MergeSort Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

	cout << "*** Data had be sort ***" << endl;
	int j = 0;
	while (j < n)
	{
		cout << aryNN[j] << endl;
		j++;
	}

	if (aryRaw != NULL)
	{
		delete aryRaw;
		aryRaw = NULL;
	}	

	mySort->uninitAry();
	system("pause");
    return 0;
}
