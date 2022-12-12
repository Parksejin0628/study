#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

class SolveQuestion
{
private:
	int arrSize;
	int* arr;
	int** dp;
	int** sum;
public:
	SolveQuestion(int arrSize);
	int mergeFile(int left, int right);
	int sumFile(int left, int right);
	~SolveQuestion();
};

SolveQuestion::SolveQuestion(int arrSize) : arrSize(arrSize)
{
	arr = new int[arrSize] {};
	dp = new int* [arrSize] {};
	sum = new int* [arrSize] {};
	for (int i = 0; i < arrSize; i++)
	{
		dp[i] = new int[arrSize] {};
		sum[i] = new int[arrSize] {};
	}
	for (int i = 0; i < arrSize; i++)
	{
		scanf("%d", &arr[i]);
	}
}

SolveQuestion::~SolveQuestion()
{
	delete[]arr;
	for (int i = 0; i < arrSize; i++)
	{
		delete[]dp[i];
		delete[]sum[i];
	}
	delete[]dp;
	delete[]sum;
}

int SolveQuestion::mergeFile(int left, int right)
{
	if (dp[left][right] == 0)
	{
		int min = 2000000000;
		int temp = 0;
		for (int i = left; i < right; i++)
		{
			temp = mergeFile(left, i) + mergeFile(i + 1, right) + sumFile(left, right);
			if (min > temp)
			{
				min = temp;
			}
		}
		if (left == right)
		{
			dp[left][right] = 0;
		}
		else
		{
			dp[left][right] = min;
			//printf("%d ~ %d 구간 최소값 : %d\n", left, right, dp[left][right]);
		}
	}

	return dp[left][right];
}

int SolveQuestion::sumFile(int left, int right)
{
	if (sum[left][right] == 0)
	{
		int temp = 0;
		for (int i = left; i <= right; i++)
		{
			temp += arr[i];
		}
		sum[left][right] = temp;
	}

	return sum[left][right];
}



int main(void)
{
	int testcase = 0;
	int arrSize = 0;
	SolveQuestion* solveQuestion;

	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++)
	{
		scanf("%d", &arrSize);
		solveQuestion = new SolveQuestion(arrSize);
		printf("%d\n",solveQuestion->mergeFile(0, arrSize - 1));
		delete solveQuestion;
	}
	

	return 0;
}
