//number of question : 1920
//Difficulty : Silver 4
//Time to solve : 54m 27s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int num[100100] = {0};
int sortNum[100100] = {0};

void mergeSort(int start, int end);
int checkNum(int inputNum, int start, int end);

void mergeSort(int start, int end)
{
	if(start >= end)	return;
	//printf("check1 - start : %d, end : %d\n", start, end);
	 
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	
	for(; k<=end; k++)
	{
		if(num[i]<=num[j])	sortNum[k] = num[i++];
		else	sortNum[k] = num[j++];
		if(i>mid)
		{
			k++;
			break;
		}
		if(j>end)
		{
			k++;
			break;
		}
	}
	if(i>mid)
	{
		for(; j<=end; j++)
		{
			sortNum[k++] = num[j];
		}
	}
	else if(j>end)
	{
		for(; i<=mid; i++)
		{
			sortNum[k++] = num[i];
		}
	}
	
	for(k=start; k<=end; k++)
	{
		num[k] = sortNum[k];
	}
}

int checkNum(int inputNum, int start, int end)
{
	int mid = 0;
	while(start<=end)
	{
		mid = (start + end) / 2;
		//printf("ºñ±³Áß...start : %d, end : %d, mid : %d num[%d] : %d / inputNum : %d\n",start, end, mid, mid, num[mid], inputNum);
		if(num[mid]==inputNum)	return 1;
		else if(num[mid] > inputNum)	end = mid - 1;
		else	start = mid + 1;
	}
	return 0;
}

int main(void)
{
	int n=0;
	int m=0;
	int inputNum = 0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&num[i]);
	}
	mergeSort(0, n-1);
	/*for(int i=0; i<n; i++)
	{
		printf("num[%d] : %d\n",i, num[i]);
	}*/
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		scanf("%d",&inputNum);
		printf("%d\n",checkNum(inputNum, 0, n-1));
	}
	
	return 0;
}
