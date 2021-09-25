//number of question : 18870
//Difficulty : Silver 2
//Time to solve : 30m 17s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int num[1000100] = {0};
int temp[1000100] = {0};
int sortNum[1000100] = {0};
int coordinate_compression[1000100] = {0};

void mergeSort(int start, int end)
{
	if(start >= end)	return;
	
	int mid = (start + end) / 2;
	
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	
	int i = start;
	int j = mid + 1;
	int k = start;
	
	for(; k<=end; k++)
	{
		if(temp[i] <= temp[j])
		{
			sortNum[k] = temp[i++];
		}
		else
		{
			sortNum[k] = temp[j++];
		}
		if(i>mid || j > end)
		{
			k++;
			break;
		}
	} 
	if(j>end)
	{
		for(; k<=end; k++)
		{
			sortNum[k] = temp[i++];
		}
	}
	else if(i>mid)
	{
		for(; k<=end; k++)
		{
			sortNum[k] = temp[j++];
		}
	}
	for(k = start; k<=end; k++)
	{
		temp[k] = sortNum[k];
	}
} 

int binarySearch(int num, int start, int end)
{
	int mid = (start + end) / 2;
	
	while(start <= end)
	{
		//printf("num : %d, check1 - %d\n",num,temp[mid]);
		if(temp[mid] == num)
		{
			return coordinate_compression[mid];
		}
		else if(temp[mid] < num)
		{
			start = mid + 1;
		}
		else
		{
			end = mid -1;
		}
		mid = (start + end) / 2;
	}
	
	return -1;
}

int main(void)
{
	int n=0;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d",&num[i]);
		temp[i] = num[i];
	}
	mergeSort(0, n-1);
	/*printf("정렬 : ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", sortNum[i]);
	}
	printf("\n");*/
	for(int i=1; i<n; i++)
	{
		if(sortNum[i-1] < sortNum[i])
		{
			coordinate_compression[i] = coordinate_compression[i-1] + 1;
		}
		else if(sortNum[i-1] == sortNum[i])
		{
			coordinate_compression[i] = coordinate_compression[i-1];
		}
		else
		{
			coordinate_compression[i] = -1;
		}
	}
	/*printf("순서 : ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", coordinate_compression[i]);
	}
	printf("\n");*/
	for(int i=0; i<n; i++)
	{
		printf("%d ",binarySearch(num[i], 0, n-1));
	}
	
	//scanf("%d",&n);
	
	return 0;
}
