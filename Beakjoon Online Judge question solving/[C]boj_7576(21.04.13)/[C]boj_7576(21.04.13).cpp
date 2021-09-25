//number of question : 7576
//Difficulty : Silver 1
//Time to solve : 1h 6m 18s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int quque[2][1001000][2] = {0}; 
int tomato[1100][1100] = {0};
int checkBFS[1100][1100] = {0};

int main(void)
{
	int m = 0;
	int n = 0;
	int greenTomato = 0;
	int time = -1;
	int level = 0;
	int nextLevel = 1;
	int x = 0;
	int y = 0;
	int rearIndex[2] = {0};
	int temp = 0;
	
	scanf("%d %d",&m, &n);
	for(int j=1; j<=n; j++)
	{
		for(int i=1; i<=m; i++)
		{
			scanf("%d",&tomato[i][j]);
			if(tomato[i][j] == 0)
			{
				greenTomato++;
			}
			else if(tomato[i][j] == 1)
			{
				quque[level][rearIndex[level]][0] = i;
				quque[level][rearIndex[level]][1] = j;
				checkBFS[i][j] = 1;
				rearIndex[level]++;
			}
		}
	}
	//printf("check1 - greenTomato : %d\n", greenTomato);
	if(greenTomato == 0)
	{
		printf("0");
	//	scanf("%d",&n);
		return 0;
	}
	while(rearIndex[level] != 0)
	{
		//printf("check4 - quque : %d\n",quque[level][0][0]);
		time++;
		//printf("check2 - time : %d\n",time);
		for(int i=0; i<rearIndex[level]; i++)
		{
			x = quque[level][i][0];
			y = quque[level][i][1];
			//printf("check3 - i : %d, level : %d, x : %d, y : %d\n", i, level, x, y);
			if(tomato[x][y] == 0)
			{
				greenTomato--;
				tomato[x][y] = 1;
			}
			//printf("check5 : 1 - checkBFS[%d][%d] : %d\n", x-1, y, 	checkBFS[x-1][y]);
			if(checkBFS[x-1][y] == 0 && tomato[x-1][y] != -1 && x-1 > 0 && x-1 <= m)
			{
				quque[nextLevel][rearIndex[nextLevel]][0] = x-1;
				quque[nextLevel][rearIndex[nextLevel]][1] = y;
				checkBFS[x-1][y] = 1;
				rearIndex[nextLevel]++;
			}
			//printf("check5 : 2 - checkBFS[%d][%d] : %d\n", x+1, y, 	checkBFS[x+1][y]);
			if(checkBFS[x+1][y] == 0 && tomato[x+1][y] != -1 && x+1 > 0 && x+1 <= m)
			{
				quque[nextLevel][rearIndex[nextLevel]][0] = x+1;
				quque[nextLevel][rearIndex[nextLevel]][1] = y;
				checkBFS[x+1][y] = 1;
				rearIndex[nextLevel]++;
			}
			//printf("check5 : 3 - checkBFS[%d][%d] : %d\n", x, y-1, 	checkBFS[x][y-1]);
			if(checkBFS[x][y-1] == 0 && tomato[x][y-1] != -1 && y-1 > 0 && y-1 <= n)
			{
				quque[nextLevel][rearIndex[nextLevel]][0] = x;
				quque[nextLevel][rearIndex[nextLevel]][1] = y-1;
				checkBFS[x][y-1] = 1;
				rearIndex[nextLevel]++;
			}
			//printf("check5 : 4 - checkBFS[%d][%d] : %d\n", x, y+1, checkBFS[x][y+1]);
			if(checkBFS[x][y+1] == 0 && tomato[x][y+1] != -1 && y+1 > 0 && y+1 <= n)
			{
				quque[nextLevel][rearIndex[nextLevel]][0] = x;
				quque[nextLevel][rearIndex[nextLevel]][1] = y+1;
				checkBFS[x][y+1] = 1;
				rearIndex[nextLevel]++;
			}	
		}
		if(greenTomato == 0)
		{
			printf("%d\n", time);
			//scanf("%d",&n);
			return 0;
		}
		rearIndex[level] = 0;
		temp = level;
		level = nextLevel;
		nextLevel = temp;
	}
	printf("-1");
	//scanf("%d",&n);
	
	return 0;
}
