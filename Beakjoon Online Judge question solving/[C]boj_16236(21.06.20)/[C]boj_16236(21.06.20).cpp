//number of question : 16236
//Difficulty : Gold 4
//Time to solve : 1h 32m 57s
//Simple review : 

#include<stdio.h>

typedef struct Position
{
	int x;
	int y;
}position;

void initBoard(int boardSize);
int updateShark();

int board[30][30] = {0};
int sharkSize = 2;
int account = 0;
position sharkPos;

int main(void)
{
	int n = 0;
	int needFeed = 2;
	int time = 0;
	int temp = 0;
	
	scanf("%d",&n);
	initBoard(n);
	for(int y=1; y<=n; y++)
	{
		for(int x=1; x<=n; x++)
		{
			scanf("%d", &board[x][y]);
			if(board[x][y] == 9)
			{
				sharkPos.x = x;
				sharkPos.y = y;
			}
		}
	}
	while(1)
	{
		temp = updateShark();
		//printf("temp : %d\n", temp);
		if(temp == -1)	break;
		time += temp;
		needFeed --;
		if(needFeed <=0)
		{
			sharkSize++;
			needFeed = sharkSize;
		}
	}
	printf("%d\n",time);
	//printf("%d\n",account);
	scanf("%d",&n);
	
	return 0;
}

void initBoard(int boardSize)
{
	for(int i=0; i<= boardSize+1; i++)
	{
		board[0][i] = -1;
		board[boardSize+1][i] = -1;
		board[i][0] = -1;
		board[i][boardSize+1] = -1;
	}
}

int updateShark()
{
	position searchStack[2][1000];
	position nextFeed;
	position tempPos;
	int stackTop[2] = {-1, -1};
	int checkBFS[30][30] = {0};
	int level = -1;
	int now = 0;
	int next = 1;
	int X = 0;
	int Y = 0;
	int find = 0;
	int temp = 0;
	
	searchStack[now][++stackTop[now]] = sharkPos;
	
	while(stackTop[now] > -1 && find == 0)
	{
		level++;
		//printf("check1\n");
		while(stackTop[now] > -1)
		{
			//printf("check2\n");
			//printf("%d\n",++account);
			++account;
			X = searchStack[now][stackTop[now]].x;
			Y = searchStack[now][stackTop[now]--].y;
			//printf("check3 - level : %d, X : %d, Y : %d, v  : %d, top : %d\n",level,X,Y,board[X][Y], stackTop[now]);
			/*if(checkBFS[X][Y] == 1)
			{
				continue;
			}*/
			checkBFS[X][Y] = 1;
			if(board[X][Y] == -1 || (board[X][Y] > sharkSize && board[X][Y] != 9))
			{
				//printf("check5 - board[X][Y] : %d\n", board[X][Y]);
				continue;
			}
			else if(board[X][Y] < sharkSize && board[X][Y]!=0 && board[X][Y] != 9)
			{
				if(find == 0)
				{
					find = 1;
					nextFeed = {X, Y};
				}
				else
				{
					if(nextFeed.y == Y)
					{
						if(nextFeed.x > X)
						{
							nextFeed = {X, Y};
						}
					}
					else if(nextFeed.y > Y)
					{
						nextFeed = {X, Y};
					}
				}
			}
			if(checkBFS[X+1][Y] == 0)
			{
				//printf("check 4-1 - X : %d, Y : %d\n", X+1, Y);
				searchStack[next][++stackTop[next]] = {X+1, Y};
				checkBFS[X+1][Y] = 1;
			}
			if(checkBFS[X-1][Y] == 0)
			{
				//printf("check 4-2 - X : %d, Y : %d\n", X-1, Y);
				searchStack[next][++stackTop[next]] = {X-1, Y};
				checkBFS[X-1][Y] = 1;
			}
			if(checkBFS[X][Y+1] == 0)
			{
				//printf("check 4-3 - X : %d, Y : %d\n", X, Y+1);
				searchStack[next][++stackTop[next]] = {X, Y+1};
				checkBFS[X][Y+1] = 1;
			}
			if(checkBFS[X][Y-1] == 0)
			{
				//printf("check 4-4 - X : %d, Y : %d\n", X, Y-1);
				searchStack[next][++stackTop[next]] = {X, Y-1};
				checkBFS[X][Y-1] = 1;
			}
		}
		temp = now;
		now = next;
		next = temp;
	}
	if(find == 0)
	{
		return -1;
	}
	board[sharkPos.x][sharkPos.y] = 0;
	sharkPos = nextFeed;
	board[sharkPos.x][sharkPos.y] = 9;
	
	return level;
}
