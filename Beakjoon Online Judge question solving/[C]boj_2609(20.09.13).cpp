//Number of Question : 2609
//Difficulty : Silver 5
//Time to solve : 10m 55s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{
	int num1=0;
	int num2=0;
	int factor1[10000] ={0};
	int factor2[10000] ={0};
	int highFactor1=0;
	int highFactor2=0;
	int greatestCommonMeasure=1;
	int leastCommonMultiple=1;
	int temp=0;
	
	scanf("%d %d",&num1, &num2);
	for(int i=2 ; i<=10000 ; i++)
	{
		if(num1==1 && num2==1)	break;
		while(num1%i==0)
		{
			//printf("check1\n");
			factor1[i]++;
			num1/=i;
			highFactor1=i;
		}
		while(num2%i==0)
		{
			//printf("check2\n");
			factor2[i]++;
			num2/=i;
			highFactor2=i;
		}
	}
	for(int i=2 ; i<=10000 ; i++)
	{
		if(highFactor1<i && highFactor2<i)	break;
		while(factor1[i]>temp && factor2[i]>temp)
		{
			//printf("check3\n");
			greatestCommonMeasure*=i;
			temp++;
		}
		temp=0;
		while(factor1[i]>temp || factor2[i]>temp)
		{
			//printf("check4\n");
			leastCommonMultiple*=i;
			temp++;			
		}
		temp=0;
	}
	printf("%d %d",greatestCommonMeasure, leastCommonMultiple);
	
	return 0;
}
