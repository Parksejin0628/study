//Number of Question : 1912
//Difficulty : Silver 2
//Time to solve : 11m 40s
//mple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int calOptimalSum(int n);

int num[100000] = {0};
int optimalSum[100000]={0};
int max=-1000;

int calOptimalSum(int n)
{
	if(optimalSum[n]==0)
	{
		if(n==0)	optimalSum[n] = num[n];
		else	optimalSum[n] = calOptimalSum(n-1) + num[n];
		if(optimalSum[n]>max)	max=optimalSum[n];
	}
	if(optimalSum[n]<0)	return 0;
	else return optimalSum[n];
}


int main(void)
{
	int n=0;
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&num[i]);
	}
	calOptimalSum(n-1);
	printf("%d\n",max);
	
	
	return 0;
}
