//number of question : 1260
//Difficulty : Silver 2
//Time to solve : 1h 52m 38s 
//Simple review : 

#include<stdio.h>

void DFS(int vertex);
void BFS(int vertex);
void insertNode(int num);
int deleteNode();

int edge[1010][1010] = {0};
int top[1010] = {0};
int checkDFS[1010] = {0};
int checkBFS[1010] = {0};
int searchQueue[2][10010] = {0};
int queueTop[2] = {-1, -1};
int minHeap[10010] = {0};
int nodeTop = 0;

int main(void)
{
	int n = 0;
	int m = 0;
	int v = 0;
	int vertex1 = 0;
	int vertex2 = 0;
	
	scanf("%d %d %d",&n, &m, &v);
	for(int i=0; i<m; i++)
	{
		scanf("%d %d",&vertex1, &vertex2);
		edge[vertex1][++top[vertex1]] = vertex2;
		edge[vertex2][++top[vertex2]] = vertex1;
	}
	DFS(v);
	printf("\n");
	BFS(v);
	
	scanf("%d",&n);
	
	return 0;
}

void DFS(int vertex)
{
	if(checkDFS[vertex] == 1)	return;
	
	int temp = 0;
	int search[1010] = {0};
	int searchTop = -1;
	
	printf("%d ",vertex);
	checkDFS[vertex] = 1;
	for(int i=1; i<=top[vertex]; i++)
	{
		temp = edge[vertex][i];
	//	printf("check5 - temp : %d. checkDFS[temp] : %d\n", temp, checkDFS[temp]);
		if(checkDFS[temp] == 0)
		{
			insertNode(temp);
		}
	}
	while(1)
	{
		temp = deleteNode();
		//printf("check6 - temp : %d\n", temp);
		if(temp == 0)	break;
		search[++searchTop] = temp;
	}
	for(int i=0; i<=searchTop; i++)
	{
		//printf("check4 - i : %d, search[i] : %d\n", i, search[i]);
		DFS(search[i]);
	}
	
	return;
}

void BFS(int vertex)
{
	int temp = 0;
	int now = 0;
	int next = 1;
	int frontIndex = -1;
	
	searchQueue[now][++queueTop[now]] = vertex;
	while(queueTop[now] != -1)
	{
		//printf("check1\n"); 
		while(1)
		{
			//printf("check2\n");
			if(frontIndex >= queueTop[now])
			{
				queueTop[now] = -1;
				break;
			}
			temp = searchQueue[now][++frontIndex];
			//printf("check9 - temp : %d\n",temp);
			if(checkBFS[temp] == 1)	continue;
			printf("%d ",temp);
			checkBFS[temp] = 1;
			for(int i=1; i<=top[temp]; i++)
			{
				if(checkBFS[edge[temp][i]] == 0)
				{
					//printf("check7 - edge[%d][%d] : %d\n", temp, i, edge[temp][i]);
					insertNode(edge[temp][i]);
				}
			}
			for(int i=1; i<=9999; i++)
			{
				temp = deleteNode();
				//printf("check8 - temp : %d\n", temp);
				if(temp == 0)	break;	
				searchQueue[next][++queueTop[next]] = temp;
			}
			
		}
		temp = now;
		now = next;
		next = temp;
		frontIndex = -1;
		
		/*printf("\nnext : ");
		for(int i=0; i<=queueTop[now]+1; i++)
		{
			printf("%d ",searchQueue[now][i]);
		}
		printf("\n");*/
	}
	
	return;
}

void insertNode(int num)
{
	minHeap[++nodeTop] = num; 
	
	int parent = nodeTop / 2;
	int child = nodeTop;
	int temp = 0;
	
	while(minHeap[parent] > minHeap[child])
	{
		temp = minHeap[child];
		minHeap[child] = minHeap[parent];
		minHeap[parent] = temp;
		
		child = parent;
		parent = child / 2;
	}
	
	return;
}

int deleteNode()
{
	if(nodeTop == 0)	return 0;
	
	int min = minHeap[1];
	int parent = 1;
	int child = parent * 2;
	int temp = 0;
	
	minHeap[1] = minHeap[nodeTop--];
	if(child+1 <= nodeTop && minHeap[child] > minHeap[child+1])
	{
		child++;
	}
	while(minHeap[parent] > minHeap[child] && child <= nodeTop)
	{
		temp = minHeap[parent];
		minHeap[parent] = minHeap[child];
		minHeap[child] = temp;
		
		if(parent*2 > nodeTop)
		{
			break;
		}
		parent = child;
		child = parent * 2;
		if(child+1 <= nodeTop && minHeap[child] > minHeap[child+1])
		{
		child++;
		}
	}
	
	return min;
}

