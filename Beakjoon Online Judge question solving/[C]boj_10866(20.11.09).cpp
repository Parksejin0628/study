//Number of question : 10866
//Difficulty : Silver 4
//Time to solve : 16m 25s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{	
	int n=0;
	int temp=0;
	int num[20020] = {0};
	int firstIndex = 10009;
	int rearIndex = 10010;
	char command[20] = {'\0'};
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%s",command);
		if(strcmp(command,"push_front")==0)
		{
			scanf("%d",&temp);
			num[firstIndex--] = temp;
		}
		else if(strcmp(command,"push_back")==0)
		{
			scanf("%d",&temp);
			num[rearIndex++] = temp;
		}
		else if(strcmp(command,"pop_front")==0)
		{
			if(rearIndex - firstIndex == 1)
			{
				printf("-1\n");
			}
			else	printf("%d\n",num[++firstIndex]);
		}
		else if(strcmp(command,"pop_back")==0)
		{
			if(rearIndex - firstIndex == 1)
			{
				printf("-1\n");
			}
			else	printf("%d\n",num[--rearIndex]);
		}
		else if(strcmp(command,"size")==0)
		{
			printf("%d\n",rearIndex - firstIndex - 1);
		}
		else if(strcmp(command,"empty")==0)
		{
			if(rearIndex - firstIndex == 1)	printf("1\n");
			else	printf("0\n");
		}
		else if(strcmp(command,"front")==0)
		{
			if(rearIndex - firstIndex == 1)
			{
				printf("-1\n");
			}
			else	printf("%d\n",num[firstIndex+1]);
		}
		else if(strcmp(command,"back")==0)
		{
			if(rearIndex - firstIndex == 1)
			{
				printf("-1\n");
			}
			else	printf("%d\n",num[rearIndex - 1]);
		}
		else	printf("error\n");
	}
	
	return 0;
}
