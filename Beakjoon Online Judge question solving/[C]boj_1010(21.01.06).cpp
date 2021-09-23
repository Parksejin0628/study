//Number of question : 1010
//Difficulty : Silver 5
//Time to solve : 23m 51s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

long long factorial(int min, int max)
{
	long long result = 0;
	if(max>min)	
	{
		result = max * factorial(min, max-1);
	}
	else if(max == min)
	{
		result = max;
	}
	return result;
}

int main(void)
{	
	int testcase = 0;
	int n=0;
	int m=0;
	long long a=0;
	long long b=0;
	
	scanf("%d",&testcase);
	for(int t=0; t<testcase; t++)
	{
	scanf("%d %d",&n,&m);
	if(n > m/2)	n = m-n;
	if(n==0)
	{
		printf("1\n");
		continue;
	}
	a=factorial(m-n+1, m);
	b=factorial(1,n);
	printf("%lld\n", a/b);	
	}
	return 0;
}
