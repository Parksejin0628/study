//Number of question : 10830
//Difficulty : Gold 4
//Time to solve : 39m 41s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#define P 1000

int a[5][5] = {0};
int mul[5][5] = {0};
int temp[5][5] = {0};

void square(int n, long long exponent)
{
	long long  tempNum=0;
	if(exponent == 1)
	{
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				mul[i][j] = a[i][j] % 1000;
			}
		}
		return;
	}
	else if(exponent % 2 == 0)
	{
		square(n, exponent/2);
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				tempNum = 0;
				for(int k=0 ; k<n ; k++)
				{
					tempNum += mul[i][k] * mul[k][j];
					tempNum %= 1000;
				}
				temp[i][j] = tempNum;
			}
		}
	}
	else
	{
		square(n, exponent-1);
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				tempNum = 0;
				for(int k=0 ; k<n ; k++)
				{
					tempNum += mul[i][k] * a[k][j];
					tempNum %= 1000;
				}
				temp[i][j] = tempNum;
			}
		}
	}
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			mul[i][j] = temp[i][j];
		}
	}
	return;
}

int main(void)
{	
	int n=0;
	long long b=0;
	
	scanf("%d %lld",&n,&b);
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	square(n, b);
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			printf("%d ",mul[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
