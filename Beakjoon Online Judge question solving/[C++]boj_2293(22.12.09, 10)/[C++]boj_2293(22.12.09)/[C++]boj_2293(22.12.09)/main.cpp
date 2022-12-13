#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

int coinCount = 0;
int* coin;
int* temp;
int dp[10005] = { 0 };

void mergeSort(int start, int end);
int searchCase(int value, int coinCount);

int main(void)
{
	int value;

	scanf("%d %d", &coinCount, &value);

	coin = new int[coinCount];
	temp = new int[coinCount];

	for (int i = 0; i < coinCount; i++)
	{
		scanf("%d", &coin[i]);
	}
	mergeSort(0, coinCount - 1);
	printf("%d\n", searchCase(value, coinCount));
	/*
	for (int i = 0; i <= value; i++)
	{
		printf("value : %d = %d\n", i, dp[i]);
	}
	*/
	delete[]coin;
	delete[]temp;

	return 0;
}

int searchCase(int value, int coinCount)
{
	for (int i = 0; i < coinCount; i++)
	{
		if (coin[i] > 10000)
		{
			continue;
		}
		dp[coin[i]] += 1;
		for (int j = coin[i]; j <= value; j++)
		{
			//printf("coin : %d원, value : %d, 원래dp값 : %d, dp[j-coin[i]]값 : %d ", coin[i], j, dp[j], dp[j - coin[i]]);
			dp[j] = dp[j] + dp[j - coin[i]];
			//printf("계산 후 dp값 : %d\n", dp[j]);
		}
	}

	return dp[value];
}

void mergeSort(int start, int end)
{
	if (start >= end)	return;
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int k = start;

	for (; k <= end; k++)
	{
		if (i > mid || j > end)
		{
			break;
		}
		if (coin[i] < coin[j])
		{
			temp[k] = coin[i++];
		}
		else
		{
			temp[k] = coin[j++];
		}
	}
	if (j > end)
	{
		for (; k <= end; k++)
		{
			temp[k] = coin[i++];
		}
	}
	else
	{
		for (; k <= end; k++)
		{
			temp[k] = coin[j++];
		}
	}
	for (k = start; k <= end; k++)
	{
		coin[k] = temp[k];
	}
}