//Number of Question : 11050
//Difficulty : Bronze 1
//Time to solve : 7m 43s
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
	int k=0;
	int temp=1;
	
	scanf("%d %d",&n,&k);
	for(int i=n ; i>=n-k+1 ; i--)
	{
		temp*=i;
	}
	for(int i=k ; i>=1 ; i--)
	{
		temp/=i;
	}
	printf("%d",temp);
	
	
	return 0;
}
