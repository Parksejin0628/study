//Number of question : 2749
//Difficulty : Gold 2
//Time to solve : 43m 59s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#define P 1000000

int original[2][2] = 
{
	{1, 1},
	{1, 0}
};
long long cal[2][2] = {0};
long long temp[2][2] = {0};

void square(long long exponent)
{
	long long tempNum=0;
	if(exponent == 1)
	{
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				cal[i][j] = original[i][j];
			}
		}
		return;
	}
	else if(exponent%2 == 0)
	{
		square(exponent/2);
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				tempNum = 0;
				for(int k=0; k<2; k++)
				{
					tempNum += (cal[i][k] * cal[k][j]) % P;
					tempNum %= P;
				}
				temp[i][j] = tempNum % P;
			}
		}
	}
	else
	{
		square(exponent-1);
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				tempNum = 0;
				for(int k=0; k<2; k++)
				{
					tempNum += (cal[i][k] * original[k][j]) % P;
					tempNum %= P;
				}
				temp[i][j] = tempNum % P;
			}
		}
	}
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			cal[i][j] = temp[i][j] % P;
		}
	}
	return;
}

int main(void)
{	
	long long n = 0;
	scanf("%lld",&n);
	square(n);
	printf("%d",cal[1][0]);
	
	return 0;
}
