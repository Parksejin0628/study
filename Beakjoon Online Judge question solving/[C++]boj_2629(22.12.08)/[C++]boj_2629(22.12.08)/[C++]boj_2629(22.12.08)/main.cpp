#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

int* weight;
int** dp;
int numberOfWeight;

bool scale(int index, int requiredWeight);

int main(void)
{
	
	int numberOfBead = 0;
	int beadWeight = 0;
	bool answer = false;

	scanf("%d", &numberOfWeight);
	weight = new int[numberOfWeight] {};
	dp = new int* [numberOfWeight] {};
	for (int i = 0; i < numberOfWeight; i++)
	{
		dp[i] = new int[100000] {};
	}

	for (int i = 0; i < numberOfWeight; i++)
	{
		scanf("%d", &weight[i]);
	}

	scanf("%d", &numberOfBead);
	for (int i = 0; i < numberOfBead; i++)
	{
		scanf("%d", &beadWeight);
		answer = scale(0, beadWeight + 50000);
		if (answer)
		{
			printf("Y ");
		}
		else
		{
			printf("N ");
		}
	}

	for (int i = 0; i < numberOfWeight; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
	delete[]weight;

	return 0;
}

bool scale(int index, int requiredWeight)
{
	if (index >= numberOfWeight)	return false;
	//printf("현재 index : %d / 추의 무게 : %d / 요구 무게 : %d\n", index, weight[index], requiredWeight);
	if (dp[index][requiredWeight] == 0)
	{
		if (weight[index] == requiredWeight-50000 || weight[index] == (requiredWeight-50000) * -1)
		{
			dp[index][requiredWeight] = 1;
		}
		else if (scale(index + 1, requiredWeight))
		{
			dp[index][requiredWeight] = 1;
		}
		else if (scale(index + 1, requiredWeight + weight[index]))
		{
			dp[index][requiredWeight] = 1;
		}
		else if (scale(index + 1, requiredWeight - weight[index]))
		{
			dp[index][requiredWeight] = 1;
		}
		else
		{
			dp[index][requiredWeight] = -1;
		}
	}
	if (dp[index][requiredWeight] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}