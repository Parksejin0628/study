#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

struct app
{
	int memory;
	int cost;
};

int appCount;
app apps[105];
int dp[105][1000];

int searchCase(int index, int memory);

int main(void)
{
	int requiredMemory = 0;
	scanf("%d %d", &appCount, &requiredMemory);
	for (int i = 0; i < appCount; i++)
	{
		scanf("%d", &apps[i].memory);
	}
	for (int i = 0; i < appCount; i++)
	{
		scanf("%d", &apps[i].cost);
	}
	printf("%d", searchCase(0, requiredMemory));

	return 0;
}

int searchCase(int index, int memory)
{
	if (memory < 0)	return 0;
	if (index >= appCount)	return -1;
	if (dp[index][memory] == 0)
	{
		int temp[2];
		temp[0] = searchCase(index + 1, memory);
		temp[1] = searchCase(index + 1, memory - apps[index].memory) + apps[index].cost;
		//-1에 대한 예외처리 할 것
		if (temp[0] < temp[1])
		{
			dp[index][memory] = temp[0];
		}
		else
		{
			dp[index][memory] = temp[1];
		}
	}
	return dp[index][memory];
}