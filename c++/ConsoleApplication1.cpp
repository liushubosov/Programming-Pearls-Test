// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <stdlib.h>
#include <time.h> 
using namespace std;

int FirstFun(int* aryNN, int n);
int SecondFun(int l, int r, int* aryNN);
int ThirdFun(int b, int e, int* aryNN);
int max(int a, int b, int c);

int main_1()
{
	int RandomNumber;
	srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。  
	  
	int n = 10;
	int* aryNN = new int[n];
	//int aryNN [] = { -84,6,-23,37,97,1,4,31,-78,7 };
	int nMaxNum = 0;

	for (int i = 0; i < n; i++)
	{
		RandomNumber = rand() % 201 -100;//生成1~100随机数
		aryNN[i] = RandomNumber;
		cout << RandomNumber << endl;
	}


	nMaxNum = FirstFun(aryNN, n);
	cout << "FirstFun nMaxNum : " << nMaxNum << endl;
	nMaxNum = SecondFun(0,n,aryNN);
	cout << "SecondFun nMaxNum : " << nMaxNum << endl;
	nMaxNum = ThirdFun(0, n, aryNN);
	cout << "ThirdFun nMaxNum : " << nMaxNum << endl;
	system("pause");
    return 0;
}


int FirstFun(int* aryNN,int n)
{
	int nMaxNum = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			int nTmp = aryNN[j];
			sum += nTmp;

			nMaxNum = __max(nMaxNum, sum);
		}
	}
	return nMaxNum;
}

//分治算法
int SecondFun(int l, int r, int* aryNN)
{
	if (l > r)
	{
		return 0;
	}
	if (l == r)
	{
		return __max(0, aryNN[l]);
	}

	int medium = (l+r) / 2;
	int lSum = 0,rSum = 0,lMax = 0,rMax = 0;

	for (int i = medium; i >= l; i--)
	{
		lSum += aryNN[i];
		lMax = __max(lMax, lSum);
	}

	for (int j = medium+1; j < r; j++)
	{
		rSum += aryNN[j];
		rMax = __max(rMax, rSum);
	}

	return max(lMax + rMax,SecondFun(l, medium, aryNN), SecondFun(medium+1, r, aryNN));
}

//扫描算法
int ThirdFun(int b, int e, int* aryNN)
{
	int maxSoFar = 0;
	int maxEndingHere = 0;

	for (int i = b; i < e; i++)
	{
		maxEndingHere = __max(maxEndingHere + aryNN[i], 0);
		maxSoFar = __max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}


int max(int a, int b, int c)
{
	int tmp = a > b ? a: b;
	tmp = tmp > c ? tmp : c;
	return tmp;
}
