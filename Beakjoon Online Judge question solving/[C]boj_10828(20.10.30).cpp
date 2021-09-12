//Number of Question : 10828
//Difficulty : Silver 4
//Time to solve : 19m 11s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{	
	int num[10000] = {0};
	int n=0;
	int acount=0;
	char command[10] = {'0'};
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%s",command);
		if(strncmp(command,"push",4)==0)
		{
			scanf("%d",&num[acount]);
			//printf("check1-num[%d] : %d\n",acount,num[acount]);
			acount++;
		}
		else if(strcmp(command,"pop")==0)
		{
			if(acount>0)
			{
				printf("%d\n",num[acount-1]);
				num[acount-1] = 0;
				acount--;
			}
			else
			{
				printf("-1\n");
			}
		}
		else if(strcmp(command,"size")==0)
		{
			printf("%d\n",acount);
		}
		else if(strcmp(command, "empty")==0)
		{
			if(acount>0)	printf("0\n");
			else	printf("1\n");
		}
		else if(strcmp(command,"top")==0)
		{
			if(acount>0)
			{
				printf("%d\n",num[acount-1]);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	
	return 0;
}
