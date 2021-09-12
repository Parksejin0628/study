//Number of question : 1932
//Difficulty : Silver 1
//Time to solve : 1h 12m 48s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int n=0;
int triInt[500][500]={0};
int sum[500][500] = {0};

int selectBest(int x, int y)
{
	if(sum[y][x]==0)
	{
		if(y==n-1)	sum[y][x] = triInt[y][x];
		else if(selectBest(x,y+1)>selectBest(x+1,y+1))	sum[y][x] = sum[y+1][x] + triInt[y][x];
		else if(selectBest(x,y+1)<=selectBest(x+1,y+1))	sum[y][x] = sum[y+1][x+1] + triInt[y][x];
	}
	//printf("x : %d, y : %d 의 최적합은 %d입니다.\n",x+1,y+1,sum[y][x]);
	return sum[y][x];
}

int main(void)
{
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<=i ; j++)
		{
			scanf("%d",&triInt[i][j]);
		}
	}
	printf("%d",selectBest(0,0));
	
	return 0;
}
