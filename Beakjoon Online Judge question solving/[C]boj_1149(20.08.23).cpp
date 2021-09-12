//Number of question : 1149
//Difficulty : Silver 1
//Time to solve : 1h 14m 8s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int n=0;
int price[1000][3]={0};
int sumPrice[1000][3]={0};

int calPrice(int num, int index)
{
	if(sumPrice[num][index]==0)
	{
		if(num==n-1)	sumPrice[num][index] = price[num][index];
		else if(index==0)
		{
			if(calPrice(num+1,1)<calPrice(num+1,2))	sumPrice[num][index] = sumPrice[num+1][1] + price[num][index];
			else	sumPrice[num][index] = sumPrice[num+1][2] + price[num][index];
		}
		else if(index==1)
		{
			if(calPrice(num+1,0)<calPrice(num+1,2))	sumPrice[num][index] = sumPrice[num+1][0] + price[num][index];
			else	sumPrice[num][index] = sumPrice[num+1][2] + price[num][index];
		}
		else if(index==2)
		{
			if(calPrice(num+1,0)<calPrice(num+1,1))	sumPrice[num][index] = sumPrice[num+1][0] + price[num][index];
			else	sumPrice[num][index] = sumPrice[num+1][1] + price[num][index];
		}
	}
	//printf("%d번째 %d집까지 최적합 : %d\n",num+1,index+1,sumPrice[num][index]);
	return sumPrice[num][index];
}

int main(void)
{
	
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			scanf("%d",&price[i][j]);
		}
	}
	sumPrice[0][0]=calPrice(0,0);
	sumPrice[0][1]=calPrice(0,1);
	sumPrice[0][2]=calPrice(0,2);
	if(sumPrice[0][0]<sumPrice[0][1])
	{
		if(sumPrice[0][0]<sumPrice[0][2])	printf("%d",sumPrice[0][0]);
		else	printf("%d",sumPrice[0][2]);
	}
	else
	{
		if(sumPrice[0][1]<sumPrice[0][2])	printf("%d",sumPrice[0][1]);
		else	printf("%d",sumPrice[0][2]);
	}
	
	return 0;
}
