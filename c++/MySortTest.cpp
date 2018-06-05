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
	int n = 10000;
	int* aryNN;

	MySort * mySort = new MySort();
	aryNN = mySort->initAry(n);
	assert(aryNN != NULL);
	for (int i = 0; i < n; i++)
	{
		RandomNumber = rand() % 2001 -1000;//生成1~100随机数
		aryNN[i] = RandomNumber;
		//cout << RandomNumber << endl;
	}

	clock_t startTime, endTime;
	//startTime = clock();
	//mySort->BubbleSort();
	//endTime = clock();
	//cout << "|BubbleSort Time : " << (double)(endTime  - startTime)/ CLOCKS_PER_SEC << endl;

	startTime = clock();
	mySort->InsertSort();
	endTime = clock(); 
	cout << "|InsertSort Time : " << (double)(endTime  - startTime)/ CLOCKS_PER_SEC << endl;

	cout << "*** Data had be sort ***" << endl;
	int j = 0;
	while (j < n)
	{
		//cout << aryNN[j] << endl;
		j++;
	}

	system("pause");
    return 0;
}
