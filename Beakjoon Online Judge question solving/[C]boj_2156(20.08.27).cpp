//Number of Question : 2156
//Difficulty : Silver 1
//Time to solve : 56m 53s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int n=0;
int wine[10010]={0};
int optimalSum[10010][2]={0};

int calOptimalSum(int num, int poss)
{
	int max=0;
	if(num<0)	return 0;
	if(optimalSum[num][poss]==0)
	{
		//printf("%d %d check4\n",num,optimalSum[num][poss]);
		if(num==1)
		{
			//printf("check1\n");
			optimalSum[num][0] = calOptimalSum(num-1,0) + wine[num];
			optimalSum[num][1] = wine[num];
		}
		else if(num==0)
		{
			//printf("check2\n");
			optimalSum[num][0] = wine[num];
			optimalSum[num][1] = wine[num];
		}
		else
		{
			//printf("%d check3\n",num);
			optimalSum[num][0] = calOptimalSum(num-1,1) + wine[num];
			if(max<calOptimalSum(num-2,0))	max = optimalSum[num-2][0];
			if(max<calOptimalSum(num-2,1))	max = optimalSum[num-2][1];
			if(max<calOptimalSum(num-3,0))	max = optimalSum[num-3][0];
			if(max<calOptimalSum(num-3,1))	max = optimalSum[num-3][1];
			optimalSum[num][1] = max + wine[num];
		}
		if(optimalSum[num][0] == 0)	optimalSum[num][0] = -1;
		if(optimalSum[num][1] == 0)	optimalSum[num][1] = -1;
	}
	//printf("연속가능%c인%d번째최적합은 %d입니다.\n",(poss) ? 'o' : 'x', num+1, optimalSum[num][poss]);
	
	if(optimalSum[num][poss] == -1)	return 0;
	return optimalSum[num][poss];
}

int main(void)
{
	int max = 0;
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&wine[i]);
	}
	if(max<calOptimalSum(n-1,0))	max=optimalSum[n-1][0];
	if(max<calOptimalSum(n-1,1))	max=optimalSum[n-1][1];
	if(max<calOptimalSum(n-2,0))	max=optimalSum[n-2][0];
	if(max<calOptimalSum(n-2,1))	max=optimalSum[n-2][1];
	
	
	printf("%d\n",max);
	scanf("%d",&n); 
	
	return 0;
}
