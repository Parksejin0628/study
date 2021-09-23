//Number of question : 13305
//Difficulty : Silver 4
//Time to solve : 37m 8s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int distance[100100] = {0};
int price[100100] = {0};

int main(void)
{	
	int n=0;
	int minPrice = 1000000000;
	long long totalPrice = 0;
	scanf("%d",&n);
	for(int i=0; i<n-1; i++)
	{
		scanf("%d",&distance[i]);
	}
	for(int i=0; i<n; i++)
	{
		scanf("%d",&price[i]);
	}
	for(int i=0; i<n-1; i++)
	{
		if(price[i] < minPrice)
		{
			minPrice = price[i];
		}
		totalPrice += (long long)distance[i] * (long long)minPrice;
	}
	printf("%lld",totalPrice);
	
	return 0;
}
