//Number of question : 10816
//Difficulty : Silver 4
//Time to solve : 21m 54s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int a[500100] = {0};
int sort[500100] = {0};
int areaLeft = -1;
int areaRight = -1;

void mergeSort(int start, int end)
{
	if(start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	int i = start;
	int j = mid + 1;
	int k = start;
	for(; k<=end; k++)
	{
		if(a[i] <= a[j])
		{
			sort[k] = a[i++];
		}
		else
		{
			sort[k] = a[j++];
		}
		if(i>mid || j>end)
		{
			break;
		}
	}
	if(i>mid)
	{
		for(; j<=end; j++)
		{
			sort[++k] = a[j];
		}
	}
	else if(j>end)
	{
		for(; i<=mid; i++)
		{
			sort[++k] = a[i];
		}
	}
	for(int k=start; k<=end; k++)
	{
		a[k] = sort[k];
		//printf("start : %d, end : %d일 때 정렬 : %d번째 - %d\n",start, end, k, a[k]); 
	}
}

void binarySearch(int searchNum, int left, int right)
{
	int mid = 0;
	while(left<=right)
	{
		mid = (right + left) / 2; 
		if(a[mid] == searchNum)
		{
			if(mid < areaLeft || areaLeft == -1)
			{
				areaLeft = mid;
				binarySearch(searchNum, left, mid-1);
				binarySearch(searchNum, mid+1, right);
			}
			if(mid > areaRight || areaRight == -1)
			{
				areaRight = mid;
				binarySearch(searchNum, left, mid-1);
				binarySearch(searchNum, mid+1, right);
			}
			return;
		}
		else if(a[mid] < searchNum)
		{
			left = mid + 1;
		}
		else if(a[mid] > searchNum)
		{
			right = mid - 1;
		}
	}
	return;
}

int main(void)
{	
	int n=0;
	int m=0;
	int searchNum = 0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	mergeSort(0, n-1);
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		scanf("%d",&searchNum);
		binarySearch(searchNum, 0, n-1);
		if(areaRight == -1 || areaLeft == -1)
		{
			printf("0 ");
		}
		else
		{
			printf("%d ",areaRight - areaLeft + 1);
		}
		areaLeft = -1;
		areaRight = -1;
	}
	
	return 0;
}
