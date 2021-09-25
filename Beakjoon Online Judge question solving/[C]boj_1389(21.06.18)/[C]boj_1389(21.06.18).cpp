//number of question : 1389
//Difficulty : Silver 1
//Time to solve : 29m 25s 
//Simple review : 

#include<stdio.h>

int edge[110][110] = {0};
int edgeTop[110] = {0};

int BFS(int start);

int main(void)
{
	int n = 0;
	int m = 0;
	int vertex1 = 0;
	int vertex2 = 0;
	int min = 999999;
	int temp = 0; 
	int answer = 0;
	
	scanf("%d %d",&n, &m);
	
	for(int i=0; i<m; i++) 
	{
		scanf("%d %d", &vertex1, &vertex2);
		edge[vertex1][++edgeTop[vertex1]] = vertex2;
		edge[vertex2][++edgeTop[vertex2]] = vertex1;
	}
	for(int i=1; i<=n; i++)
	{
		temp = BFS(i);
		if(temp < min)
		{
			min = temp;
			answer = i;
		}
	}
	
	printf("%d\n",answer);
	scanf("%d",&n);
	
	return 0;
}

int BFS(int start)
{
	int checkBFS[110] = {0};
	int searchStack[2][1110] = {0};
	int stackTop[2] = {-1, -1};
	int now = 0;
	int next = 1;
	int temp = 0;
	int sum = 0;
	int vertex = 0;
	int level = 0;
	
	searchStack[now][++stackTop[now]] = start;
	
	while(stackTop[now] > -1)
	{
		level++;
		while(stackTop[now] > -1)
		{
			vertex = searchStack[now][stackTop[now]--];
			if(checkBFS[vertex] == 1)	continue;
			sum += level;
			//printf("check1 - start : %d, vertex : %d, level : %d, sum : %d\n",start, vertex, level, sum);
			checkBFS[vertex] = 1;
			for(int i=1; i<=edgeTop[vertex]; i++)
			{
				if(checkBFS[edge[vertex][i]] == 0)
				{
					searchStack[next][++stackTop[next]] = edge[vertex][i];
				}
			}
		}
		stackTop[now] = -1;
		temp = now;
		now = next;
		next = temp;
	}
	
	return sum;
}
