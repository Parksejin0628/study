//number of question : 14500
//Difficulty : Gold 5
//Time to solve : 1h 16m 16s
//Simple review : 

#include<stdio.h>

void settingBoard(int n, int m);
int searchBoard(int n, int m);
int searchMaxTetromino(int n, int m, int level);

int board[550][550] = {0};
int checkBoard[550][550] = {0};

int main(void)
{
	int n = 0;
	int m = 0;
	
	scanf("%d %d",&n, &m);
	settingBoard(n, m); 
	printf("%d", searchBoard(n, m));
	scanf("%d",&n);
	
	return 0;
}

void settingBoard(int n, int m)
{
	for(int r=1; r<=n; r++)
	{
		for(int c=1; c<=m; c++)
		{
			scanf("%d",&board[r][c]);
		}
	}
	for(int i=0; i<=n+1; i++)
	{
		checkBoard[i][0] = 1;
		checkBoard[i][m+1] = 1;
	}
	for(int i=0; i<=m+1; i++)
	{
		checkBoard[0][i] = 1;
		checkBoard[n+1][i] = 1;
	}
	
	return;
}

int searchBoard(int n, int m)
{
	int max = -1;
	int temp = -1;
	
	for(int r=1; r<=n; r++)
	{
		for(int c=1; c<=m; c++)
		{
			//printf("\n\n r : %d, c : %d 탐색 시작\n", r, c);
			temp = searchMaxTetromino(r, c, 4);
			if(max < temp)	
			{
				max = temp;
				//printf("check1 - r : %d, c : %d에서 max : %d로 갱신\n", r, c, max);
			}
		}
	}
	
	return max;
}

int searchMaxTetromino(int n, int m, int level)
{
	int max = -1;
	int temp = -1;
	int value[4] = {0};
	int sum = 0;
	
	checkBoard[n][m] = 1;
	if(level >= 2)
	{
		if(checkBoard[n+1][m] != 1)
		{
			temp = searchMaxTetromino(n+1, m, level-1);
			value[0] = board[n+1][m];
			if(max < temp)	max = temp;
		}
		if(checkBoard[n-1][m] != 1)
		{
			temp = searchMaxTetromino(n-1, m, level-1);
			value[1] = board[n-1][m];
			if(max < temp)	max = temp;
		}
		if(checkBoard[n][m+1] != 1)
		{
			temp = searchMaxTetromino(n, m+1, level-1);
			value[2] = board[n][m+1];
			if(max < temp)	max = temp;
		}
		if(checkBoard[n][m-1] != 1)
		{
			temp = searchMaxTetromino(n, m-1, level-1);
			value[3] = board[n][m-1];
			if(max < temp)	max = temp;
		}
		for(int i=0; i<=2; i++)
		{
			for(int j=i; j<=3; j++)
			{
				if(value[i] < value[j])
				{
					temp = value[i];
					value[i] = value[j];
					value[j] = temp;
				}
			}
		}
	}
	sum += board[n][m];
	max += board[n][m];
	level --;
	for(int i=0; i<level; i++)
	{
		sum += value[i];
	}
	if(max < sum)	max = sum;
	checkBoard[n][m] = 0;
	//printf("check2 - r : %d, c : %d, level : %d, max : %d\n", n, m, level+1, max);
	
	return max;
}
