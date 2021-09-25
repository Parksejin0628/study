//number of question : 17219
//Difficulty : Silver 4
//Time to solve : 50m 32s
//Simple review : 

#include<stdio.h>
#include<string.h>

void mergeSort(int start, int end);
int findPassword(char inputAddress[30], int max);

typedef struct SiteInformation
{
	char address[30];
	char password[30];
}siteInformation;

siteInformation site[100100];
siteInformation sort[100100];

int main(void)
{
	int n = 0;
	int m = 0;
	char inputAddress[30] = {'\0'};
	
	scanf("%d %d",&n, &m);
	fgetc(stdin);
	
	for(int i=0; i<n; i++)
	{
		scanf("%s %s", site[i].address, site[i].password);
		fgetc(stdin); 
	}
	mergeSort(0, n-1);
	/*for(int i=0; i<n; i++)
	{
		printf("%d - address : %s / password : %s\n", i+1, site[i].address, site[i].password);
	}*/
	for(int i=0; i<m; i++)
	{
		scanf("%s", inputAddress);
		fgetc(stdin);
		printf("%s\n", site[findPassword(inputAddress, n-1)].password);
	}
	scanf("%d",&n);
	
	return 0;
}

void mergeSort(int start, int end)
{
	if(start >= end)	return;
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	int temp = 0;
	
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	
//	printf("check3 - start : %d, end : %d\n", start, end);
	
	for(; k<=end; k++)
	{
		if(i>mid || j>end)
		{
			break;
		}
		temp = strcmp(site[i].address, site[j].address);
		//printf("check1 - i: %d, j : %d / %s 와 %s 비교 temp : %d\n", i ,j, site[i].address, site[j].address, temp);
		if(temp < 0)
		{
			sort[k] = site[i++];
		}
		else
		{
			sort[k] = site[j++];
		}
	}
	if(i > mid)
	{
		for(; k<=end; k++)
		{
			sort[k] = site[j++];
		}
	}
	else
	{
		for(; k<=end; k++)
		{
			sort[k] = site[i++];
		}
	}
	for(k = start; k<=end; k++)
	{
		site[k] = sort[k];
	}
}

int findPassword(char inputAddress[30], int max)
{
	int min = 0;
	int mid = (min + max) / 2;
	int temp = 0;
	
	while(min <= max)
	{
		temp = strcmp(inputAddress, site[mid].address);
	//	printf("check2 -mid : %d /  %s 와 %s 비교 temp : %d\n",mid,  inputAddress, site[mid].address, temp);
		if(temp == 0)
		{
			return mid;
		}
		else if(temp < 0)
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
		mid = (min + max) / 2;
	}
	printf("error\n");
	
	return 0;
}
