//Number of question : 2748
//Difficulty : Bronze 1
//Time to solve : Less than 10m
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
	long long fibonacci[100]={0,1};
	
	scanf("%d",&n);
	for(int i=2 ; i<=n ; i++)
	{
		fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
	}
	printf("%lld",fibonacci[n]);
	
	return 0;
}
