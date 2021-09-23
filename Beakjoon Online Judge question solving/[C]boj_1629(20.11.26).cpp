//Number of question : 1629
//Difficulty : Silver 1
//Time to solve : 57m 21s
//Simple review : Even if the value of long long type variable is less than the range of int type
//                , long long type variable should not be returned to int.

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

long long pow_(int num1, int num2, int num3)
{
	long long num=0;
	if(num2==1)	 num = num1%num3;
	else if( num2%2==0)
	{
		num = pow_(num1, num2/2,num3);
		num *= num;
		num = num%num3;
	}
	else if(num2%2==1)
	{
		num =(pow_(num1, num2-1, num3) * (num1%num3))%num3;
	}
	return num%num3;
}

int main(void)
{	
	int a=0;
	int b=0;
	int c=0;
	
	scanf("%d %d %d",&a,&b,&c);
	printf("%lld\n",pow_(a,b,c));
	return 0;
}
