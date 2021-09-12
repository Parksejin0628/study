//Number of Question : 11051
//Difficulty : Silver 1
//Time to solve : 1h 38m 4s
//Simple review : Modular Arithmetic

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int calGcd(int num1, int num2)
{
	if(num1 % num2 == 0)	return num2;
	return calGcd(num2, num1%num2);
}

int main(void)
{
	int n=0;
	int k=0;
	int temp=1;
	int leftNum[600] = {0};
	int gcd=0;
	
	scanf("%d %d",&n,&k);
	if(k > n/2)	k = n-k;
	for(int i=1 ; i<=k ; i++)
	{
		leftNum[i] = i;
	}
	for(int i=n-k+1 ; i<=n ; i++)
	{
		temp*=i;
		for(int j=k ; j>=1 ; j--)
		{
			if(leftNum[j]>1)
			{
				gcd = calGcd(temp, leftNum[j]);
				temp/=gcd;
				leftNum[j]/=gcd;
			}
		}
		if(temp>10007)	temp%=10007;
	}
	printf("%d",temp);
	
	return 0;
}
