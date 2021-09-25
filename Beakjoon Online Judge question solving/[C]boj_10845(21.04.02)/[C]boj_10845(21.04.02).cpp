//number of question : 10845
//Difficulty : Silver 4
//Time to solve : 10m 18s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int quque[10100] = {0};

int main(void)
{
	int n=0;
	int num = 0;
	int frontIndex = 0;
	int rearIndex = 0;
	char command[10] = {'0'};
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%s",command);
		if(!strcmp(command, "push"))
		{
			scanf("%d",&num);
			quque[rearIndex++] = num;
		}
		else if(!strcmp(command, "pop"))
		{
			if(frontIndex == rearIndex)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n",quque[frontIndex++]);
		}
		else if(!strcmp(command, "size"))
		{
			printf("%d\n", rearIndex - frontIndex);
		}
		else if(!strcmp(command, "empty"))
		{
			if(frontIndex == rearIndex)	printf("1\n");
			else	printf("0\n");
		}
		else if(!strcmp(command, "front"))
		{
			if(frontIndex == rearIndex)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n",quque[frontIndex]);
		}
		else if(!strcmp(command, "back"))
		{
			if(frontIndex == rearIndex)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n",quque[rearIndex-1]);
		}
	}
	
	return 0;
} 
