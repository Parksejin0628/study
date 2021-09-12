//Number of Question : 12865
//Difficulty : Gold 5
//Time to solve : 3h 22m 42s + @(more time)
//mple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

void calOptimalSum(int num);
void mergeSort(int start, int end);

int n=0;
int k=0;
int w[110] = {0};
int v[110] = {0};
int max=0;
int dp[110][100010] = {0};

int main(void)
{
	scanf("%d %d",&n,&k);
	for(int i=1 ; i<=n ; i++)
	{
		scanf("%d %d",&w[i], &v[i]);
	}
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=k ; j++)
		{
			if(j < w[i])	dp[i][j] = dp[i-1][j];
			else
			{
				if(v[i] + dp[i-1][j-w[i]] > dp[i-1][j])
				{
					dp[i][j] = v[i] + dp[i-1][j-w[i]];
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
			}
			if(dp[i][j] > max)	max = dp[i][j];
		}
	}
	/*for(int i=1 ; i<=n ; i++)
	{
		printf("%d - ",i);
		for(int j=1 ; j<=k ; j++)
		{
			printf("%4d",dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",max);
	
	return 0;
}
