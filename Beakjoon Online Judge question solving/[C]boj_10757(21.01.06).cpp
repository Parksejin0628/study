//Number of question : 10757
//Difficulty : Bronze 5
//Time to solve : 31m 18s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{	
	char a[10100] = {'\0'};
	char b[10100] = {'\0'};
	char sum[10100] = {'\0'};
	int indexA = -1;
	int indexB = -1;
	int indexSum = 0;
	int numA = 0;
	int numB = 0;
	int numSum = 0;
	int temp = 0;
	
	scanf("%s %s",a, b);
	while(indexA==-1 || indexB == -1)
	{
		//printf("check1 - temp : %d, a[%d] : %c, b[%d] : %c\n",temp, temp, a[temp], temp, b[temp]);
		if(a[temp]=='\0' || a[temp]=='\n')
		{
			if(indexA==-1)	indexA = temp - 1;
		}
		if(b[temp]=='\0' || b[temp]=='\n')
		{
			if(indexB==-1)	indexB = temp - 1;
		}
		temp++;
	}
	if(indexA>=indexB)
	{
		indexSum = indexA;
	}
	else
	{
		indexSum = indexB;
	}
	temp = 0;
	while(indexSum>=0)
	{
		numA=0;
		numB=0;
		if(indexA>=0)
		{
			numA = (int)a[indexA] - (int)'0';
			indexA--;
		}
		if(indexB>=0)
		{
			numB = (int)b[indexB] - (int)'0';
			indexB--;
		}
		numSum = numA + numB + temp;
		temp = 0;
		if(numSum>=10)
		{
			temp=1;
			numSum-=10;
		}
		//printf("a[%d] = %d / b[%d] = %d / sum[%d] = %d\n",indexA+1, numA, indexB+1, numB, indexSum, numSum);
		sum[indexSum] = (char)(numSum + (int)'0');
		indexSum--;
	}
	if(temp==1)
	{
		printf("1");
	}
	printf("%s",sum);
	
	return 0;
}
