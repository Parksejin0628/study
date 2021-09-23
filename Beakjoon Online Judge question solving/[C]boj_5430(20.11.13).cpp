//Number of question : 5430
//Difficulty : Gold 5
//Time to solve : 1h 20m 2s
//Simple review : After using scanf, reset input buffer

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int num[100100] = {0};
char p[100100] = {'\0'};
	
int main(void)
{	
	int t=0;
	int n=0;
	int firstIndex=0;
	int rearIndex=0;
	int reverse=0;
	int error=0;
	char temp='\0';
	
	scanf("%d",&t);
	while(t--)
	{
		firstIndex=0;
		rearIndex=0;
		reverse=0;
		error=0;
		fgetc(stdin);
		scanf("%s",p);
		scanf("%d",&n);
		fgetc(stdin);
		scanf("%c",&temp);
		for(int i=0 ; i<n ; i++)
		{
			scanf("%d%c",&num[i],&temp);
			//printf("check3 : num[i] - %d\n",num[i]);
		}
		rearIndex = n-1;
		for(int i=0 ; p[i]=='R'||p[i]=='D' ; i++)
		{
			//printf("check2\n");
			if(p[i]=='R')
			{
				if(reverse==0)	reverse=1;
				else	reverse=0;
			}
			else if(p[i]=='D')
			{
				if(firstIndex > rearIndex)
				{
					printf("error\n");
					error=1;
					break;
				}
				if(reverse==0)
				{
					firstIndex++;
				}
				else
				{
					rearIndex--;
				}
			}
		}
		if(error)	continue;
		//printf("check1 : %d %d\n",firstIndex, rearIndex);
		printf("[");
		if(reverse==0)
		{
			//printf("check : reverse=0\n");
			for(int i=firstIndex ; i<=rearIndex ; i++)
			{
				if(i==firstIndex)	printf("%d",num[i]);
				else	printf(",%d",num[i]);
			}
		}
		else
		{
			//printf("check : reverse=1\n");
			for(int i=rearIndex ; i>=firstIndex ; i--)
			{
				//printf("check4\n");
				if(i==rearIndex)	printf("%d",num[i]);
				else	printf(",%d",num[i]);
			}
		}
		printf("]\n");
	}

	return 0;
}
