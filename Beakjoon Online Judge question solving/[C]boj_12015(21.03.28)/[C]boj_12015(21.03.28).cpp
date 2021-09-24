//number of question : 12015
//Difficulty : Gold 2
//Time to solve : 54m 26s
//Simple review : LIS / Use lowerbound

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[1000100] = {0};
int LIS[1000100] = {0}; 
int length = 0;

void updateLIS(int num);
void searchLowerBound(int num, int start, int end);

void updateLIS(int num)
{
	if(LIS[length] < num)
	{
		LIS[++length] = num;
		return;
	}
	else if(LIS[length] > num)
	{
		searchLowerBound(num, 0, length);
	}
	return;
}

void searchLowerBound(int num, int start, int end)
{
	int mid = 0;
	while(start<=end)
	{
		mid = (start + end) / 2;
		if(LIS[mid] < num)	start = mid + 1;
		else if(LIS[mid] >=num)	end = mid;
		if(start == mid)
		{
			LIS[start] = num;
			return;
		}
	}
}

int main(void)
{
	int n = 0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++) 
	{
		scanf("%d", &a[i]);	
	}
	LIS[0] = -1;
	LIS[1] = a[0];
	length = 1;
	for(int i=0; i<n; i++)
	{
		updateLIS(a[i]);
	}
	printf("%d",length);
	
	return 0;
}
