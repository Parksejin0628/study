//Number of question : 2164
//Difficulty : Silver 4
//Time to solve : 12m 57s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int num[1000100] = {0};

int main(void)
{	
	int n=0;
	int firstIndex=1;
	int rearIndex=0;
	
	scanf("%d",&n);
	rearIndex = n;
	for(int i=1 ; i<=n ; i++)
	{
		num[i] = i;
	}
	for(int i=1 ; i<=2*n ; i++)
	{
		if(firstIndex==rearIndex)
		{
			printf("%d\n",num[firstIndex]);
			break;
		}
		if(i%2==0)
		{
			rearIndex++;
			num[rearIndex] = num[firstIndex];
			firstIndex++;
		}
		else
		{
			firstIndex++;
		}
	}
	
	return 0;
}
