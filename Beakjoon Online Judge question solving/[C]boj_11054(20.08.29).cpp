//Number of Question : 11054
//Difficulty : Gold 3
//Time to solve : 1h 38m 34s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

void calOptimalSum_up();
void calOptimalSum_down();

int n=0;
int a[1000]={0};
int optimalSum_up[1000] = {0};
int optimalSum_down[1000] = {0}; 
int cumulativeMax=0;

void calOptimalSum_up()
{
	int max=0;
	for(int i=0 ; i<n ; i++)
	{
		max=0;
		for(int j=i-1 ; j>=0 ; j--)
		{
			if(a[j]<a[i]&&optimalSum_up[j] > max)	max = optimalSum_up[j];
		}
		optimalSum_up[i] = max+1;
	}
}

void calOptimalSum_down()
{
	int max=0;
	for(int i=n-1 ; i>=0 ; i--)
	{
		max=0;
		for(int j=i+1 ; j<n ; j++)
		{
			if(a[j]<a[i]&&optimalSum_down[j] > max)	max = optimalSum_down[j];
		}
		optimalSum_down[i] = max+1;
	}
}



int main(void)
{
	int min=2000;
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}
	calOptimalSum_up();
	calOptimalSum_down();
	
	for(int i=0 ; i<n ; i++)
	{
		if(cumulativeMax < optimalSum_up[i] + optimalSum_down[i]-1)
		{
			cumulativeMax = optimalSum_up[i] + optimalSum_down[i]-1;
		}
	 }
	
	printf("%d\n",cumulativeMax);
	
	return 0;
}
