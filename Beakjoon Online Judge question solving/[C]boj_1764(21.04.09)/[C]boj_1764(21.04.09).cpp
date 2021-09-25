//number of question : 1764
//Difficulty : Silver 4
//Time to solve : 28m 15s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char noListen[500500][30] = {'\0'};
char noHear[500500][30] = {'\0'};
char noListenHear[500500][30] = {'\0'};
char temp[500500][30] = {'\0'};

void mergeSort(char list[][30], int start, int end)
{
	if(start >= end)	return;
	
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	
	mergeSort(list, start, mid);
	mergeSort(list, mid + 1, end);
	
	for(; k<=end; k++)
	{
		if(i>mid || j>end)	break;
		if(strcmp(list[i], list[j]) < 0)
		{
			strcpy(temp[k], list[i++]);
		}
		else
		{
			strcpy(temp[k], list[j++]);
		}
	}
	if(j>end)
	{
		for(; k<=end; k++)
		{
			strcpy(temp[k], list[i++]);
		}
	}
	else if(i>mid)
	{
		for(; k<=end; k++)
		{
			strcpy(temp[k], list[j++]);
		}
	}
	for(k=start; k<=end; k++)
	{
		strcpy(list[k], temp[k]);
	}
}

int main(void)
{
	int n = 0;
	int m = 0;
	int start = 0;
	int mid = 0;
	int end = 0;
	int account = 0;
	int cmp = 0;
	
	scanf("%d %d",&n, &m);
	fgetc(stdin);
	//printf("check1\n");
	for(int i=0; i<n; i++)
	{
		fgets(noListen[i], 30, stdin);
	}
	for(int i=0; i<m; i++)
	{
		fgets(noHear[i], 30, stdin);
	}
	mergeSort(noListen, 0, n-1);
	mergeSort(noHear, 0, n-1);
	
	for(int i=0; i<n; i++)
	{
		start = 0;
		end = n-1;
		mid = (start + end) / 2;
		while(start <= end)
		{
			cmp = strcmp(noListen[i], noHear[mid]);
			if(cmp == 0)
			{
				strcpy(noListenHear[account++], noListen[i]);
				break;
			}
			else if(cmp < 0)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
			mid = (start + end) / 2;
		}
	}
	printf("%d\n",account);
	for(int i=0; i<account; i++)
	{
		printf("%s",noListenHear[i]);
	}
	//scanf("%d",&n);
	
	
	return 0;
}
