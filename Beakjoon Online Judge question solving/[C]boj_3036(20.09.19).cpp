//Number of Question : 3036
//Difficulty : Silver 3
//Time to solve : 4m 33s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int gdp(int a, int b)
{
	if(b>a)
	{
		int temp = a;
		a=b;
		b=temp;
	}
	if(a%b==0)	return b;
	return gdp(b,a%b);
}

int main(void)
{
	int n=0;
	int ring[100] = {0};
	int gdpNum=0;
	
	scanf("%d",&n);
	
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&ring[i]);
	}
	for(int i=1 ; i<n ; i++)
	{
		gdpNum = gdp(ring[0],ring[i]);
		printf("%d/%d\n",ring[0]/gdpNum, ring[i]/gdpNum);
	}
	
	
	return 0;
}
