//Number of Question : 1463
//Difficulty : Silver 3
//Time to solve : 30m 1s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int x=0;
int optimalSum[1000010]={0};

int calOptimalSum(int num)
{
	int min=99999;
	if(num==1)	optimalSum[num]=0;
	else if(optimalSum[num]==0)
	{
		if(num%3==0)	
		{
			if(min>calOptimalSum(num/3))	min = optimalSum[num/3];
		}
		if(num%2==0)
		{
			if(min>calOptimalSum(num/2))	min = optimalSum[num/2];
		}
		if(min>calOptimalSum(num-1))	min = optimalSum[num-1];
		optimalSum[num] = min + 1;
	}
	//printf("%d일때 최적계산수 : %d\n",num,optimalSum[num]);
	
	return optimalSum[num];
}

int main(void)
{
	scanf("%d",&x);
	/*if(x!=1)*/	printf("%d",calOptimalSum(x));
	//else if(x==1)	printf("1");
	
	return 0;
}
