//Number of Question : 11653
//Difficulty : Silver 4
//Time to solve : 5m 46s
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
	int temp=0;
	
	scanf("%d",&n);
	temp=n;
	for(int i=2 ; i<=n ; i++)
	{
		if(temp<=1)	break;
		while(temp%i==0)
		{
			printf("%d\n",i);
			temp/=i;
		}
	}
	
	return 0;
}
