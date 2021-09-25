//number of question : 3190
//Difficulty : Gold 5
//Time to solve : 2h 36m 34s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define QUEUE_SIZE 110

typedef struct Position
{
	int x;
	int y;
}position;

typedef struct Rotation
{
	int remainingTime;
	char dir;
}rotation;

int time = 0;
int frontIndex = 1;
int rearIndex = 0;
int dirIndex = 0;
int rotIndex = 0;
int board[110][110] = {0};
position dir[4];
position posQueue[QUEUE_SIZE];
rotation rot[110];

void settingGame(int n)
{
	for(int i=0; i<=n+1; i++)
	{
		board[i][0] = 1;
		board[i][n+1] = 1;
	}
	for(int i=1; i<=n; i++)
	{
		board[0][i] = 1;
		board[n+1][i] = 1;
	}
	board[1][1] = 1;
	
	dir[0].x = 1;
	dir[0].y = 0;
	
	dir[1].x = 0;
	dir[1].y = 1;
	
	dir[2].x = -1;
	dir[2].y = 0;
	
	dir[3].x = 0;
	dir[3].y = -1;
	
	posQueue[++rearIndex % QUEUE_SIZE].x = 1;
	posQueue[rearIndex % QUEUE_SIZE].y = 1;
		
	return;
}

int moving()
{
	rearIndex++;
	posQueue[rearIndex % QUEUE_SIZE].x = posQueue[(rearIndex-1) % QUEUE_SIZE].x + dir[dirIndex].x;
	posQueue[rearIndex % QUEUE_SIZE].y = posQueue[(rearIndex-1) % QUEUE_SIZE].y + dir[dirIndex].y;
	
	int X = posQueue[rearIndex % QUEUE_SIZE].x;
	int Y = posQueue[rearIndex % QUEUE_SIZE].y;
	
	//printf("check5, headX : %d, headY : %d\n",X,Y);
	
	if(board[X][Y] == 1)
	{
		return -1;
	}
	if(board[X][Y] == 2)
	{
		board[X][Y] = 1;
		return 0;
	}
	board[X][Y] = 1;
	X = posQueue[frontIndex % QUEUE_SIZE].x;
	Y = posQueue[frontIndex % QUEUE_SIZE].y;
		
	board[X][Y] = 0;
	frontIndex++;
	
	return 0;
}

void turning()
{
	if(rot[rotIndex].remainingTime <= time)
	{
		if(rot[rotIndex].dir == 'D')
		{
			//printf("check8\n");
			dirIndex++;
			dirIndex %= 4;
		}
		else
		{
			//printf("check9\n");
			dirIndex--;
			dirIndex += 4;
			dirIndex %= 4;
		}
		rotIndex++;
	}
	
	return;
}

void printBoard(int n)
{
	for(int y=1; y<=n; y++)
	{
		for(int x=1; x<=n; x++)
		{
			if(board[x][y] == 1)
			{
				printf("X");
			}
			else if(board[x][y] == 2)
			{
				printf("A");
			}
			else
			{
				printf("O");
			}
		}
		printf("\n");
	}
	
	return;
}

int main(void)
{
	int n = 0;
	int k = 0;
	int l = 0;
	int tempX = 0;
	int tempY = 0;
	
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=0; i<k; i++)
	{
		scanf("%d %d",&tempY, &tempX);
		board[tempX][tempY] = 2;	
	}
	//printf("check1, input Dir\n");
	scanf("%d",&l);
	for(int i=0; i<l; i++)
	{
		scanf("%d %c", &rot[i].remainingTime, &rot[i].dir);
		fgetc(stdin);
		//printf("check7 : rot[%d].dir : %c\n", i, rot[i].dir);
	}
	//printf("check2, settingGame\n");
	settingGame(n);
//	printf("check3, startGame\n");
	while(moving()!= -1)
	{
		//printBoard(n);
		time++;
		//printf("check4, nowTime : %d\n\n", time);
		if(l>rotIndex)
		{
			turning();
		}
	}
	printf("%d\n",time+1);
	//scanf("%d",&n);
	
	return 0;
}
