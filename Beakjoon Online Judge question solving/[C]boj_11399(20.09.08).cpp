//Number of Question : 11399
//Difficulty : Silver 3
//Time to solve : 11m 44s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

void mergeSort(int start, int end);

int tempTime[1010] = {0};
int sortedTime[1010] = {0};

void mergeSort(int start, int end)
{
	if(start>=end)	return;
	int mid = (start + end)/2;
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	int a=start;
	int b=mid + 1;
	int c=start;
	for(; c<=end ; c++)
	{
		if(a>mid || b>end)	break;
		if(tempTime[a] < tempTime[b])
		{
			sortedTime[c] = tempTime[a];
			a++;
		}
		else
		{
			sortedTime[c] = tempTime[b];
			b++;
		}
	}
	if(a>mid)
	{
		for(; c<=end ; c++)
		{
			sortedTime[c] = tempTime[b];
			b++;
		}
	}
	else if(b>end)
	{
		for(; c<=end ; c++)
		{
			sortedTime[c] = tempTime[a];
			a++;
		}
	}
	for(int i=start ; i<=end ; i++)
	{
		tempTime[i] = sortedTime[i];
	}
}

int main(void)
{
	int n=0;
	int addTime=0;
	int sumTime=0;
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&tempTime[i]);
	} 
	mergeSort(0, n-1);
	for(int i=0 ; i<n ; i++)
	{
		addTime+=tempTime[i];
		sumTime+=addTime;
	}
	printf("%d",sumTime);
	
	return 0;
}
