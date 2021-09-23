//Number of question : 11444
//Difficulty : Gold 3
//Time to solve : 55m 18s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#define P 1000000007

long long fibonacci[2][2] = {{1, 1}, {1, 0}};
const long long fibonacciBase[2][2] = {{1, 1}, {1, 0}};

void calFibonacci(long long n)
{
	long long temp[2][2] = {0};
	if(n==1)	return;
	else if(n%2 == 0)
	{
		calFibonacci(n/2);
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				temp[i][j] = ((fibonacci[i][0] * fibonacci[0][j])%P + (fibonacci[i][1]*fibonacci[1][j])%P)%P;
			}
		}
	}
	else
	{
		calFibonacci(n-1);
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				temp[i][j] = ((fibonacci[i][0] * fibonacciBase[0][j])%P + (fibonacci[i][1]*fibonacciBase[1][j]%P))%P;
			}
		}
	}
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			fibonacci[i][j] = temp[i][j];
		}
	}
	
	return;
}

int main(void)
{	
	long long n=0;
	
	scanf("%lld",&n);
	calFibonacci(n);
	printf("%lld",fibonacci[1][0]);
	
	return 0;
}
