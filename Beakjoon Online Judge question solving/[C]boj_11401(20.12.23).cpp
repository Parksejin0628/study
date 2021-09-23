//Number of question : 11401
//Difficulty : Gold 1
//Time to solve : 54m 12s + @
//Simple review : a - integer, p-decimal / a^(p-1) = 1(mod p) / multiplicative inverse : a^(p-2)

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#define P 1000000007

long long factorial(int min, int max)
{
	long long result = 0;
	if(max>min)	
	{
		result = (max * factorial(min, max-1))%P;
	}
	else if(max == min)
	{
		result = max % P;
	}
	return result;
}

long long square(int num, int exponent)
{
	long long result = 0;
	if(exponent == 1)
	{
		return num%P;
	}
	if(exponent%2 == 0)
	{
		long long temp = square(num, exponent/2);
		result = (temp * temp) % P;
	}
	else
	{
		result = (square(num, exponent-1) * num)%P;
	}
	return result;
}

int main(void)
{	
	int n=0;
	int k=0;
	long long a=0;
	long long b=0;
	
	scanf("%d %d",&n,&k);
	if(k > n/2)	k = n-k;
	if(k==0)
	{
		printf("1\n");
		return 0;
	}
	//printf("k : %d\n",k);
	a=factorial(n-k+1, n);
	b=factorial(1,k);
	//printf("b1 = %lld\n",b);
	b=square(b, P-2);
	//printf("a : %lld, b : %lld\n", a, b);
	printf("%lld", (a*b)%P);
	
	
	return 0;
}
