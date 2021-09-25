//number of question : 16928
//Difficulty : Silver 1
//Time to solve : 35m 59s
//Simple review : 

#include<stdio.h>

int game();

int board[110] = {0};
int ladder[110] = {0};
int snake[110] = {0};
int searchStack[2][1010] = {0};

int main(void)
{
	int n = 0;
	int m = 0;
	int input[2] = {0};
	
	scanf("%d %d",&n ,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d", &input[0], &input[1]);
		board[input[0]] = 1;
		ladder[input[0]] = input[1];
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d", &input[0], &input[1]);
		board[input[0]] = 2;
		snake[input[0]] = input[1];
	}
	printf("%d\n",game());
	scanf("%d",&n);	
	
	return 0;
}

int game()
{
	int stackTop[2] = {-1, -1};
	int now = 0;
	int next = 1;
	int temp = 0;
	int level = 0;
	int candidate_max = 0;
	int vertex = 0;
	int checkBFS[110] = {0};
	
	searchStack[now][++stackTop[now]] = 1;
	while(stackTop[now] != -1)
	{
		while(stackTop[now] != -1)
		{
			vertex = searchStack[now][stackTop[now]--];
			if(checkBFS[vertex] == 1)
			{
				continue;
			}
			if(vertex >= 100)
			{
				return level;
			}
			checkBFS[vertex] = 1;
			for(int candidate=1; candidate<=6; candidate++)
			{
				if(board[vertex + candidate] == 1)
				{
					searchStack[next][++stackTop[next]] = ladder[vertex + candidate];
				}
				else if(board[vertex + candidate] == 2)
				{
					searchStack[next][++stackTop[next]] = snake[vertex + candidate];
				}
				else
				{
					candidate_max = candidate;
				}
			}
			searchStack[next][++stackTop[next]] = vertex + candidate_max;
		}
		level++;
		temp = now;
		now = next;
		next = temp;
	}
	
	return -1;
}
