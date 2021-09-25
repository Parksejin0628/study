//number of question : 1012
//Difficulty : Silver 2
//Time to solve : 1h 3m 54s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cabbage[60][60][2] = {0};

void checkSide(int x, int y)
{
	cabbage[x][y][1] = 1;
	if(cabbage[x+1][y][0] == 1 && cabbage[x+1][y][1] == 0)	
	{
		cabbage[x+1][y][1] = 1;
		checkSide(x+1, y);
	}
	if(cabbage[x][y+1][0] == 1 && cabbage[x][y+1][1] == 0)
	{
		cabbage[x][y+1][1] = 1;
		checkSide(x, y+1);
	}
	if(cabbage[x-1][y][0] == 1 && cabbage[x-1][y][1] == 0)
	{
		cabbage[x-1][y][1] = 1;
		checkSide(x-1, y);
	}
	if(cabbage[x][y-1][0] == 1 && cabbage[x][y-1][1] == 0)	
	{
		cabbage[x][y-1][1] = 1;
		checkSide(x, y-1);
	}
	return;
}

int checkCabbage(int m, int n)
{
	int account = 0;
	
	for(int y=1; y<=n; y++)
	{
		for(int x=1; x<=m; x++)
		{
			if(cabbage[x][y][0] == 1 && cabbage[x][y][1] == 0)
			{
				checkSide(x, y);
				account++;
			}
		}
	}
	return account; 
}

int main(void)
{
	int tc = 0;
	int m = 0;
	int n = 0;
	int k = 0;
	int x = 0;
	int y = 0;
	
	scanf("%d",&tc);
	for(int t=0; t<tc; t++)
	{
		scanf("%d %d %d",&m, &n, &k);
		for(int i=0; i<k; i++)
		{
			scanf("%d %d",&x, &y);
			cabbage[x+1][y+1][0] = 1;
		}
		printf("%d\n",checkCabbage(m, n));
		for(int j=0; j<=60; j++)
		{
			for(int i=0; i<=60; i++)
			{
				cabbage[i][j][0] = 0;
				cabbage[i][j][1] = 0;
			}
		}
	}
	scanf("%d",&tc);
	
	return 0;
}
