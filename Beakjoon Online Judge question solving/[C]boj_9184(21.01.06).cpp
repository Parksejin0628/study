//Number of question : 9184
//Difficulty : Silver 2
//Time to solve : 31m 27s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int valueW[110][110][110] = {0};

int w(int a, int b, int c)
{
	int temp = 0;
	//printf("check1 %d %d %d\n",a,b,c);
	if(valueW[a+50][b+50][c+50]!=0)
	{
		return valueW[a+50][b+50][c+50];
	}
	else if(a<=0 || b<=0 || c<=0)
	{
		temp = 1;
		valueW[a+50][b+50][c+50] = temp;
		return temp;
	}
	else if(a>20 || b>20 || c>20)
	{
		temp = w(20, 20, 20);
		valueW[a+50][b+50][c+50] = temp;
		return temp;
	}
	else if(a<b && b<c)
	{
		temp = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		valueW[a+50][b+50][c+50] = temp;
		return temp;
	}
	else
	{
		temp = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		valueW[a+50][b+50][c+50] = temp;
		return temp;
	}
}

int main(void)
{	
	int a=0; 
	int b=0;
	int c=0;
	
	while(1)
	{
		scanf("%d %d %d",&a, &b, &c);
		if(a==-1 && b==-1 && c==-1)
		{
			break;
		}
		printf("w(%d, %d, %d) = %d\n",a, b, c, w(a, b, c));
	}
	
	return 0;
}
