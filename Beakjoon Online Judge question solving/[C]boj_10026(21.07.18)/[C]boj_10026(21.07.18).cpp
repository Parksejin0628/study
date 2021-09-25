//number of question : 10026
//Difficulty : Gold 5
//Time to solve : 29m 29s
//Simple review : 

#include<stdio.h>
#include<string.h>

void searchDFS_normal(int row, int column, int color);
void searchDFS_colorWeakness(int row, int column, int color);

int board[110][110] = {0};
int checkDFS_normal[110][110] = {0};
int checkDFS_colorWeakness[110][110] = {0};

int main(void)
{
	int n = 0;
	char input[110] = {'\0'};
	char temp = 0;
	int areaCount_normal = 0;
	int areaCount_colorWeakness = 0;
	
	scanf("%d", &n);
	fgetc(stdin);
	for(int r=1; r<=n; r++)
	{
		scanf("%s", input);
		for(int c=1; c<=n; c++)
		{
			temp = input[c-1];
			if(temp == 'R')
			{
				board[r][c] = 1;
			}
			else if(temp == 'G')
			{
				board[r][c] = 2;
			}
			else
			{
				board[r][c] = 3;
			}
		}
	}
	for(int r=1; r<=n; r++)
	{
		for(int c=1; c<=n; c++)
		{
			if(checkDFS_normal[r][c] == 0)
			{
				areaCount_normal++;
				searchDFS_normal(r, c, board[r][c]);
			}
			if(checkDFS_colorWeakness[r][c] == 0)
			{
				areaCount_colorWeakness++;
				searchDFS_colorWeakness(r, c, board[r][c]);
			}
		}
	}
	printf("%d %d\n", areaCount_normal, areaCount_colorWeakness);
	scanf("%d", &n);
	
	return 0;
}

void searchDFS_normal(int row, int column, int color)
{
	int R = row;
	int C = column;
	
	checkDFS_normal[row][column] = 1;
	
	R = row - 1;
	if(checkDFS_normal[R][C] == 0 && board[R][C] == color)
	{
		searchDFS_normal(R, C, color);
	}
	
	R = row + 1;
	if(checkDFS_normal[R][C] == 0 && board[R][C] == color)
	{
		searchDFS_normal(R, C, color);
	}
	
	R = row;
	C = column - 1;
	if(checkDFS_normal[R][C] == 0 && board[R][C] == color)
	{
		searchDFS_normal(R, C, color);
	}
	C = column + 1;
	if(checkDFS_normal[R][C] == 0 && board[R][C] == color)
	{
		searchDFS_normal(R, C, color);
	}
	
	return;
}

void searchDFS_colorWeakness(int row, int column, int color)
{
	int R = row;
	int C = column;
	int otherColor = color;
	
	checkDFS_colorWeakness[row][column] = 1;
	
	if(color == 1)
	{
		otherColor = 2;
	}
	if(color == 2)
	{
		otherColor = 1;
	}
	
	R = row - 1;
	if(checkDFS_colorWeakness[R][C] == 0 && (board[R][C] == color || board[R][C] == otherColor))
	{
		searchDFS_colorWeakness(R, C, color);
	}
	
	R = row + 1;
	if(checkDFS_colorWeakness[R][C] == 0 && (board[R][C] == color || board[R][C] == otherColor))
	{
		searchDFS_colorWeakness(R, C, color);
	}
	
	R = row;
	C = column - 1;
	if(checkDFS_colorWeakness[R][C] == 0 && (board[R][C] == color || board[R][C] == otherColor))
	{
		searchDFS_colorWeakness(R, C, color);
	}
	C = column + 1;
	if(checkDFS_colorWeakness[R][C] == 0 && (board[R][C] == color || board[R][C] == otherColor))
	{
		searchDFS_colorWeakness(R, C, color);
	}
	
	return;
}
