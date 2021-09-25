//number of question : 2178
//Difficulty : Silver 1
//Time to solve : 39m 23s
//Simple review : 

#include<stdio.h>

void updateBoard(int line, int length);
int searchMaze();

int n = 0;
int m = 0;
char input[110] = {0};
int board[110][110] = {0};
int checkBFS[110][110] = {0}; 

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int r = 1; r<=n; r++)
	{
		scanf("%s", input);
		updateBoard(r, m);
	}
	/*for(int r = 1; r<=n; r++)
	{
		for(int c=1; c<=m; c++)
		{
			printf("%d ", board[r][c]);
		}
		printf("\n");
	}*/
	
	printf("%d\n", searchMaze());
	scanf("%d",&n);
	
	return 0;
}

void updateBoard(int line, int length)
{
	for(int i=1; i<=length; i++)
	{
		board[line][i] = (int)(input[i-1] - '0');
		//printf("check1 - input[%d] : %c, board : %d\n", i-1, input[i-1], (int)(input[i-1] - '0'));
	}
	
	return;
}

int searchMaze()
{
	int searchStack[2][1000][2] = {0};
	int stackTop[2] = {-1, -1};
	int temp = 0;
	int R = 0;
	int C = 0;
	int R1 = 0;
	int C1 = 0;
	int level = 0;
	int now = 0;
	int next = 1;
	
	checkBFS[1][1] = 1;
	searchStack[now][++stackTop[now]][0] = 1;
	searchStack[now][stackTop[now]][1] = 1;
	while(stackTop[now] != -1)
	{
		level++;
		while(stackTop[now] != -1)
		{
			R = searchStack[now][stackTop[now]][0];
			C = searchStack[now][stackTop[now]--][1];
			
			R1 = R + 1;
			C1 = C;
			
			if(checkBFS[R1][C1] == 0 && board[R1][C1] == 1)
			{
				if(R1 == n && C1 == m)
				{
					return level + 1;
				}
				checkBFS[R1][C1] = 1;
				searchStack[next][++stackTop[next]][0] = R1;
				searchStack[next][stackTop[next]][1] = C1;
			}
			
			R1 = R - 1;
			
			if(checkBFS[R1][C1] == 0 && board[R1][C1] == 1)
			{
				if(R1 == n && C1 == m)
				{
					return level + 1;
				}
				checkBFS[R1][C1] = 1;
				searchStack[next][++stackTop[next]][0] = R1;
				searchStack[next][stackTop[next]][1] = C1;
			}
			
			R1 = R;
			C1 = C + 1;
			
			if(checkBFS[R1][C1] == 0 && board[R1][C1] == 1)
			{
				if(R1 == n && C1 == m)
				{
					return level + 1;
				}
				checkBFS[R1][C1] = 1;
				searchStack[next][++stackTop[next]][0] = R1;
				searchStack[next][stackTop[next]][1] = C1;
			}
			
			C1 = C - 1;
			
			if(checkBFS[R1][C1] == 0 && board[R1][C1] == 1)
			{
				if(R1 == n && C1 == m)
				{
					return level + 1;
				}
				checkBFS[R1][C1] = 1;
				searchStack[next][++stackTop[next]][0] = R1;
				searchStack[next][stackTop[next]][1] = C1;
			}
		}
		temp = now;
		now = next;
		next = temp;
	}
	
	return level;
}
