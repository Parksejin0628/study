//Number of question : 1934
//Difficulty : Silver 5
//Time to solve : 6m 33s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int calGCD(int a, int b)
{
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return calGCD(b, a%b);
	}
}

int main(void)
{	
	int testcase=0;
	int a=0;
	int b=0;
	int gcd = 0;
	int lcm = 0;
	
	scanf("%d",&testcase);
	for(int t=0; t<testcase; t++)
	{
		scanf("%d %d",&a,&b);
		if(a<b)
		{
			gcd = calGCD(b, a);
		}
		else
		{
			gcd = calGCD(a, b);
		}
		lcm = gcd * (a/gcd) * (b/gcd);
		printf("%d\n",lcm);
	}
	
	return 0;
}
