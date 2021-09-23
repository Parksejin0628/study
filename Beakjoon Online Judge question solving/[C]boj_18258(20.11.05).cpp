//Number of question : 18258
//Difficulty : Silver 4
//Time to solve : 17m 29s
//Simple review : Queue_index name - firstIndex, rearIndex

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int num[2000100] = {0};

/*
void queue()
{
	for(int i=1 ;; i++)
	{
		if(num[i]==0)
		{
			num[i-1]=0;
			return;
		}
		num[i-1] = num[i];
	}
	printf("-1\n");
	return;
}
*/

int main(void)
{	
	int n=0;
	int numIndex=0;
	int ququeIndex=0;
	char command[10] = {'\0'};
	int x=0;
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%s",command);
		if(strcmp(command,"push")==0)
		{
			scanf("%d",&x);
			num[numIndex]=x;
			numIndex++;
		}
		else if(strcmp(command,"pop")==0)
		{
			if(num[ququeIndex]==0)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n",num[ququeIndex]);
			ququeIndex++;
			//queue();
			//numIndex--;
		}
		else if(strcmp(command,"size")==0)
		{
			printf("%d\n",numIndex - ququeIndex);
		}
		else if(strcmp(command,"empty")==0)
		{
			if(num[ququeIndex]==0)	printf("1\n");
			else	printf("0\n");
		}
		else if(strcmp(command,"front")==0)
		{
			if(num[ququeIndex]==0)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n",num[ququeIndex]);
		}
		else if(strcmp(command,"back")==0)
		{
			if(num[ququeIndex]==0)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n",num[numIndex-1]);
		}
		else
		{
			printf("error\n");
		}
	}
	
	return 0;
}
