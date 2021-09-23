//Number of question : 2805
//Difficulty : Silver 3
//Time to solve : 20m 52s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int tree[1000100] = {0};

long long calMaxHeight(int n, int m, int high)
{
	int left = 0;
	int right = high;
	int mid = 0;
	long long maxHeight = 0;
	long long length = 0;
	
	while(left<=right)
	{
		//printf("check1\n");
		mid = (left + right) / 2;
		for(int i=0; i<n; i++)
		{
			if(tree[i] - mid > 0)
			{
				length += tree[i] - mid;
			}
		}
		if(length < m)
		{
			right = mid - 1;
		}
		else if(length >= m)
		{
			left = mid + 1;
			maxHeight = mid;
		}
		length = 0;
	}
	
	return maxHeight;
}

int main(void)
{	
	int n = 0;
	int m = 0;
	int high = 0;
	
	scanf("%d %d",&n, &m);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&tree[i]);
		if(high < tree[i])
		{
			high = tree[i];
		}
	}
	printf("%lld",calMaxHeight(n, m, high));
	
	return 0;
}
