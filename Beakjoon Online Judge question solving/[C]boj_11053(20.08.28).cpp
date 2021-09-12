//Number of Question : 11053
//Difficulty : Silver 2
//Time to solve : 35m 52s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int n=0;
int a[1000] = {0};
int optimalSum[1000] = {-1};
int max=0;

void calOptimalSum(int cumulative, int pos)
{
	int min=2000;
	
	if(optimalSum[pos] >= cumulative)	return;
	else
	{
		optimalSum[pos] = cumulative;
		//printf("%d번째까지 최고 누적길이 : %d\n",pos+1,cumulative);
	}
	if(cumulative > max)	max=cumulative;
	if(cumulative==0)
	{
		calOptimalSum(1,0);
		for(int i=pos+1 ; i<n ; i++)
		{		
			if(a[i]<min)
			{
				min=a[i];
				calOptimalSum(cumulative+1, i);
			}
		}
	}
	else
	{
		for(int i=pos+1 ; i<n ; i++)
		{		
			if(a[i]<=min && a[i]>a[pos])
			{
				min=a[i];
				calOptimalSum(cumulative+1, i);
			}
		}
	}
	
	return;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}
	calOptimalSum(0,0);
	
	printf("%d\n",max);
	
	return 0;
}
