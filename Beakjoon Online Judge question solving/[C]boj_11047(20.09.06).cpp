//Number of Question : 11047
//Difficulty : Silver 2
//Time to solve : 4m 43s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

void calOptimalSum(int num);
void mergeSort(int start, int end);



int main(void)
{
	int n=0;
	int k=0;
	int v[10] = {0};
	int acount=0;
	scanf("%d %d",&n, &k);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&v[i]);
	}
	for(int i=n-1 ; i>=0 ; i--)
	{
		while(k>=v[i])
		{
			acount++;
			k-=v[i];
		}
		if(k==0)
		{
			printf("%d",acount);
			break;
		}
	}
	
	return 0;
}
