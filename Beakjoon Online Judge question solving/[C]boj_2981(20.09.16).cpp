//Number of Question : 2981
//Difficulty : Gold 5
//Time to solve : 1h 48m 17s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int gdp(int a, int b)
{
	if(a%b==0)	return b;
	return gdp(b,a%b);
}

int main(void)
{
	int n=0;
	int num[110] = {0};
	int numDif[110] = {0};
	int min=0;
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&num[i]);
		if(i>=1)
		{
			numDif[i] = num[i] - num[i-1];
			if(numDif[i]<0)	numDif[i]*=-1;
		}
	}
	min = numDif[1];
	for(int i=1 ; i<n ; i++)
	{
		min = gdp(numDif[i],min); 
	}
	//printf("min : %d\n",min);
	for(int i=2 ; i<=min/2; i++)
	{
		//printf("%d\n",i);
		if(min%i==0)	printf("%d ",i);
	}
	if(min>1)	printf("%d",min);
	
	
	return 0;
}
