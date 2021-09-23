//Number of question : 11866
//Difficulty : Silver 4
//Time to solve : 25m 51s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int num[600000] = {0};
int josephus[1010] = {0};

int main(void)
{	
	int n=0;
	int k=0;
	int acount=0;
	int temp=0;
	int firstIndex=1;
	int rearIndex=0;
	int josephusIndex=0;
	
	scanf("%d %d",&n,&k);
	rearIndex = n;
	acount = n;
	
	for(int i=1 ; i<=n ; i++)
	{
		num[i] = i;
	}
	
	while(acount!=0)
	{
		temp = k%acount;
		if(temp == 0)	temp = k;
		for(int i=firstIndex ; i<firstIndex + temp - 1 ; i++)
		{
			num[++rearIndex] = num[i];
		}
		josephus[josephusIndex++] = num[firstIndex + temp - 1];
		firstIndex = firstIndex + temp;
		acount --;
	}
	
	printf("<%d",josephus[0]);
	for(int i=1 ; i<n ; i++)
	{
		printf(", %d",josephus[i]);
	}
	printf(">");
	
	return 0;
}\
