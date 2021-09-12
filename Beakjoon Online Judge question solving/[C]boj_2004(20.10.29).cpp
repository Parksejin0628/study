//Number of Question : 2004
//Difficulty : Silver 2
//Time to solve : 35m + @(more time)
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{
	int n=0;
	int m=0;
	int sum=0;
	int sum_2=0;
	
	scanf("%d %d",&n,&m);
	for(int i=1 ; i<=13 ; i++)
	{
		sum += (n / (int)pow(5.0,(double)i));
		sum -= ((n-m) / (int)pow(5.0,(double)i));
		sum -= (m / (int)pow(5.0,(double)i));
	}
	for(int i=1 ; i<=30 ; i++)
	{
		sum_2 += (n / (int)pow(2.0,(double)i));
		sum_2 -= ((n-m) / (int)pow(2.0,(double)i));
		sum_2 -= (m / (int)pow(2.0,(double)i));
	}
	if(sum<=sum_2)	printf("%d",sum);
	else	printf("%d",sum_2);
	
	return 0;
}
