//Number of Question : 2579
//Difficulty : Silver 3
//Time to solve : 58m 22s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int n=0;
int stairsNum[300] = {0};
int stairsSum[300][2] = {0};

int calOptimalSum(int num, int poss)
{
	if(stairsSum[num][poss]==0)
	{
		if(num==0)
		{
			stairsSum[num][0] = stairsSum[num][1] = stairsNum[0];
		}
		else if(num==1)
		{
			stairsSum[num][1] = stairsNum[1];
			stairsSum[num][0] = calOptimalSum(num-1,1) + stairsNum[num];
		}
		else
		{
			stairsSum[num][0] = calOptimalSum(num-1,1) + stairsNum[num];
			if(calOptimalSum(num-2,0) > calOptimalSum(num-2,1))
			{
				stairsSum[num][1] = stairsSum[num-2][0] + stairsNum[num];
			}
			else
			{
				stairsSum[num][1] = stairsSum[num-2][1] + stairsNum[num];
			}
		}
	}
	
	//printf("stairsSum[%d][%d] : %d\n",num,poss,stairsSum[num][poss]);
	return stairsSum[num][poss];
}

int main(void)
{
	int n=0;
	
	scanf("%d",&n);
	
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&stairsNum[i]);
	}
	if(calOptimalSum(n-1,0) > calOptimalSum(n-1,1))	printf("%d\n",stairsSum[n-1][0]);
	else	printf("%d\n",stairsSum[n-1][1]);
	
	return 0;
}
