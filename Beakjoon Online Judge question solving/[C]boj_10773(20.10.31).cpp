//Number of Question : 10773
//Difficulty : Silver 4
//Time to solve : 4m 5s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{	
	int k=0;
	int num[100000] = {0};
	int temp=0;
	int acount=0;
	long long sum = 0;
	
	scanf("%d",&k);
	for(int i=0 ; i<k ; i++)
	{
		scanf("%d",&temp);
		if(temp==0)
		{
			num[acount-1]=0;
			acount--;
		}
		else
		{
			num[acount] = temp;
			acount++;
		}
	}
	for(int i=0 ; i<acount ; i++)
	{
		sum+=num[i];
	}
	printf("%d",sum);
	
	return 0;
}
