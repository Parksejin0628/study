//number of question : 11724
//Difficulty : Silver 2
//Time to solve : 17m 25s
//Simple review : 

#include<stdio.h>

int edge[1010][1010] = {0};
int top[1010] = {0};
int check[1010] = {0};

void DFS(int node)
{
	check[node] = 1;
	
	for(int i=1; i<=top[node]; i++)
	{
		//printf("check1 - %d\n",edge[node][i]); 
		if(check[edge[node][i]] == 0)
		{
			DFS(edge[node][i]);
		}
	}
}

int main(void)
{
	int n = 0;
	int m = 0;
	int u = 0;
	int v = 0;
	int cc = 0;
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
		scanf("%d %d",&u, &v);
		edge[u][++top[u]] = v;
		edge[v][++top[v]] = u;
	}
	for(int i=1; i<=n; i++)
	{
		if(check[i] == 0)
		{
			DFS(i);
			cc++;
		}
	}
	printf("%d",cc);
	scanf("%d",&n);
		
	return 0;
}
