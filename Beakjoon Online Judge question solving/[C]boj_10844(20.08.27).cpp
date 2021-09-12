//Number of Question : 10844
//Difficulty : Silver 1
//Time to solve : 19m 43s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int n=0;
long long optimalSum[110][10]={0};

long long calOptimalSum(int num, int pos)
{
	if(pos > n)	return 0;
	if(pos==n)	return 1;
	else if(optimalSum[pos][num]==0)
	{
		if(num==0)	optimalSum[pos][num] = calOptimalSum(num+1,pos+1);
		else if(num==9)	optimalSum[pos][num] = calOptimalSum(num-1, pos+1);
		else
		{
			optimalSum[pos][num] = calOptimalSum(num+1, pos+1) + calOptimalSum(num-1,pos+1);
		}
	}
	if(optimalSum[pos][num]>=1000000000)	optimalSum[pos][num]%=1000000000;
	
	return optimalSum[pos][num];
}

int main(void)
{
	long long sum=0;
	scanf("%d",&n);
	for(int i=1 ; i<=9 ; i++)
	{
		sum+=calOptimalSum(i,1) % 1000000000;
		//printf("%lld\n",calOptimalSum(i,1));
	}
	printf("%lld\n",sum%1000000000);
	
	
	return 0;
}
