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
	int n = 10;
	int* aryNN;

	MySort * mySort = new MySort();
	aryNN = mySort->initAry(n);
	assert(aryNN != NULL);
	for (int i = 0; i < n; i++)
	{
		RandomNumber = rand() % 2001 -1000;//生成1~100随机数
		aryNN[i] = RandomNumber;
		cout << RandomNumber << endl;
	}

	mySort->BubbleSort();
	cout << "*** Data had be sort ***" << endl;
	int j = 0;
	while (j < n)
	{
		j++;
		int x = aryNN[j];
		cout << x << endl;
	}

	//clock_t startTime, endTime;
	//startTime = clock();
	//nMaxNum = FirstFun(aryNN, n);
	//endTime = clock();
	//cout << "FirstFun nMaxNum : " << nMaxNum;
	//cout << "|FirstFun Time : " << (double)(endTime  - startTime)/ CLOCKS_PER_SEC << endl;

	//startTime = clock();
	//nMaxNum = SecondFun(0,n,aryNN);
	//endTime = clock();
	//cout << "SecondFun nMaxNum : " << nMaxNum << endl;
	//cout << "|SecondFun Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

	//startTime = clock();
	//nMaxNum = ThirdFun(0, n, aryNN);
	//endTime = clock();
	//cout << "ThirdFun nMaxNum : " << nMaxNum << endl;
	//cout << "|ThirdFun Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

	system("pause");
    return 0;
}
