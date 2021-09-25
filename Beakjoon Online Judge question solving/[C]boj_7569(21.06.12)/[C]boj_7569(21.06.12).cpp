//number of question : 7569
//Difficulty : Silver 1
//Time to solve : 1h 6m 23s
//Simple review : 

#include<stdio.h>

typedef struct Position
{
	int x;  
	int y; 
	int z;  
}position;

int box[110][110][110] = {0};
position stack[2][1000100];
int top[2] = {-1, -1};
int maxX = 0;
int maxY = 0;
int maxZ = 0;
int greenTomato = 0;

void ripeTomato(int x, int y, int z, int next)
{
	//printf("check1 - x : %d, y : %d, z : %d\n", x, y, z);
	if(x+1 < maxX)
	{
		if(box[x+1][y][z] == 0)
		{
			greenTomato--;
			box[x+1][y][z] = 1;
			stack[next][++top[next]].x = x+1;
			stack[next][top[next]].y = y;
			stack[next][top[next]].z = z;
		}
	}
	
	if(y+1 < maxY)
	{
		if(box[x][y+1][z] == 0)
		{
			greenTomato--;
			box[x][y+1][z] = 1;
			stack[next][++top[next]].x = x;
			stack[next][top[next]].y = y+1;
			stack[next][top[next]].z = z;
		}
	}
	
	if(z+1 < maxZ)
	{
		if(box[x][y][z+1] == 0)
		{
			greenTomato--;
			box[x][y][z+1] = 1;
			stack[next][++top[next]].x = x;
			stack[next][top[next]].y = y;
			stack[next][top[next]].z = z+1;
		}
	}
	
	if(x-1 > 0)
	{
		if(box[x-1][y][z] == 0)
		{
			greenTomato--;
			box[x-1][y][z] = 1;
			stack[next][++top[next]].x = x-1;
			stack[next][top[next]].y = y;
			stack[next][top[next]].z = z;
		}
	}
	
	if(y-1 > 0)
	{
		if(box[x][y-1][z] == 0)
		{
			greenTomato--;
			box[x][y-1][z] = 1;
			stack[next][++top[next]].x = x;
			stack[next][top[next]].y = y-1;
			stack[next][top[next]].z = z;
		}
	}
	
	if(z-1 > 0)
	{
		if(box[x][y][z-1] == 0)
		{
			greenTomato--;
			box[x][y][z-1] = 1;
			stack[next][++top[next]].x = x;
			stack[next][top[next]].y = y;
			stack[next][top[next]].z = z-1;
		}
	}
	
	return;
}

int main(void)
{
	int m = 0;
	int n = 0;
	int h = 0;
	int input = 0; 
	
	int now = 0;
	int next = 1;
	int day = 0;
	int temp = 0;
	
	scanf("%d %d %d", &m, &n, &h);
	maxX = m + 1;
	maxY = n + 1;
	maxZ = h + 1;
	for(int z=1; z<=h; z++)
	{
		for(int y=1; y<=n; y++)
		{
			for(int x=1; x<=m; x++)
			{
				scanf("%d",&input);
				if(input == -1)
				{
					box[x][y][z] = -1;
				}
				else if(input == 0)
				{
					greenTomato++;
				}
				else if(input == 1)
				{
					box[x][y][z] = 1;
					stack[now][++top[now]].x = x;
					stack[now][top[now]].y = y; 
					stack[now][top[now]].z = z;
				}
			}
		}
	}
	while((top[0] != -1 || top[1] != -1) && greenTomato != 0)
	{
		//printf("check2 - top[0] : %d, top[1] : %d, greenTomato : %d\n", top[0], top[1], greenTomato);
		day++;
		for(; top[now]>=0; top[now]--)
		{
			ripeTomato(stack[now][top[now]].x, stack[now][top[now]].y, stack[now][top[now]].z, next);
		}
		/*printf("\n\n\nday : %d\n", day);
		for(int z=1; z<=h; z++)
		{
			for(int y=1; y<=n; y++)
			{
				for(int x=1; x<=m; x++)
				{
					printf("%d",box[x][y][z]);
				}
				printf("\n");
			}
			printf("\n\n");
		}*/
		temp = now;
		now = next;
		next = temp;
	}
	if(greenTomato > 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",day);
	}
	//scanf("%d",&n);
	
	return 0;
}
