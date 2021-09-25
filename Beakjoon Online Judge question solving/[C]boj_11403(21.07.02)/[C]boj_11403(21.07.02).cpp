//number of question : 11403
//Difficulty : Silver 1
//Time to solve : 1h 11m 35s
//Simple review : 

#include<stdio.h>

void searchVertex(int vertex, int max);

int edge[110][110] = {0};
int edgeTop[110] = {0};
int checkVertex[110] = {0};
int answer[110][110] = {0};


int main(void)
{
	int n = 0;
	int temp = 0;
	
	scanf("%d",&n);
	for(int r=1; r<=n; r++)
	{
		for(int c=1; c<=n; c++)
		{
			scanf("%d",&temp);
			if(temp == 1)
			{
				edge[r][++edgeTop[r]] = c;
			}
		}
	}
	for(int r=1; r<=n; r++)
	{
		checkVertex[r] = 1;
		if(edgeTop[r] > 0)
		{
			searchVertex(r, n);
		}
	}
	for(int r=1; r<=n; r++)
	{
		for(int c=1; c<=n; c++)
		{
			printf("%d ",answer[r][c]);
		}
		printf("\n");
	}
	scanf("%d",&n);
	
	return 0;
}

void searchVertex(int vertex, int max)
{
	int searchStack[2][110] = {0};
	int stackTop[2] = {-1, -1};
	int now = 0;
	int next = 0;
	int searchingVertex = 0;
	int searchEdge = 0;
	int checkBFS[110] = {0};
	int temp = 0;
	
	searchStack[now][++stackTop[now]] = vertex;
	while(stackTop[now] != -1)
	{
		while(stackTop[now] != -1)
		{
			searchingVertex = searchStack[now][stackTop[now]--];
			for(int i=1; i<=edgeTop[searchingVertex]; i++)
			{
				searchEdge = edge[searchingVertex][i];
				answer[vertex][searchEdge] = 1;
				if(checkVertex[searchEdge] == 1)
				{
					for(int j=1; j<=max; j++)
					{
						if(answer[searchEdge][j] == 1)
						{
							answer[vertex][j] = 1;
							checkBFS[j] = 1;
						}
					}
				}
				else if(checkBFS[searchEdge] != 1)
				{
					searchStack[next][++stackTop[next]] = searchEdge;
				}
				checkBFS[searchEdge] = 1;
			}
			temp = now;
			now = next;
			next = temp;
		}
	}
	
	return;
}
