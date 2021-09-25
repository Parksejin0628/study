//number of question : 11723
//Difficulty : Silver 5
//Time to solve : 6m 25s
//Simple review : 

#include<stdio.h>
#include<string.h>

int main(void)
{
	int s[30] = {0};
	int num = 0;
	char command[20] ={'\0'};
	int m = 0;
	
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		scanf("%s",command);
		if(strcmp(command, "add") == 0)
		{
			scanf("%d",&num);
			s[num] = 1;
		}
		if(strcmp(command, "remove") == 0)
		{
			scanf("%d",&num);
			s[num] = 0;
		}
		if(strcmp(command, "check") == 0)
		{
			scanf("%d",&num);
			printf("%d\n",s[num]);
		}
		if(strcmp(command, "toggle") == 0)
		{
			scanf("%d",&num);
			if(s[num]==0)	s[num] = 1;
			else	s[num] = 0;
		}
		if(strcmp(command, "all") == 0)
		{
			for(int i=1; i<=20; i++)
			{
				s[i] = 1;
			}
		}
		if(strcmp(command, "empty") == 0)
		{
			for(int i=1; i<=20; i++)
			{
				s[i] = 0;
			}
		}
	}
	//scanf("%d",&m);
	
	return 0;
}
