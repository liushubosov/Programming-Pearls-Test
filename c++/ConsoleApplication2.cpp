// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <stdlib.h>
#include <time.h> 
#include "Stack.h"
using namespace std;

int main_2()
{
	int RandomNumber;
	srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。  
	//  
	int n = 5000;
	int* aryNN = new int[n];
	////int aryNN [] = { -84,6,-23,37,97,1,4,31,-78,7 };
	//int nMaxNum = 0;

	Stack * myStack = new Stack();
	for (int i = 0; i < n; i++)
	{
		RandomNumber = rand() % 2001 -1000;//生成1~100随机数
		aryNN[i] = RandomNumber;
		cout << RandomNumber << endl;
		
		myStack->push(RandomNumber);
	}

	int j = n;
	while (j > 0)
	{
		j--;
		int x = myStack->pop();
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