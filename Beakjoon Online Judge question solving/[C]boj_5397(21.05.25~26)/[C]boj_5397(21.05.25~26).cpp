//number of question : 5397
//Difficulty : Silver 3
//Time to solve : 50m
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char input[1000100] = {'\0'};
char leftStack[1000100] = {'\0'};
char rightStack[1000100] = {'\0'};

int main(void)
{
	int testCase = 0;
	int leftTop = -1;
	int rightTop = -1;
	int length = 0;
	//int num = 0;
	
	scanf("%d", &testCase);
	fgetc(stdin);
	for(int t=0; t<testCase; t++)
	{
		//printf("check1\n");
		//fgets(input, 1000100, stdin);
		scanf("%s",input);
		fgetc(stdin);
		//printf("check2\n");
		length = strlen(input)-1; 
		for(int i=0; i<=length; i++) 
		{
			//printf("%d\n",++num);
			if(input[i] == '<')
			{
				if(leftTop > -1)	rightStack[++rightTop] = leftStack[leftTop--];
			}
			else if(input[i] == '>')
			{
				if(rightTop > -1)	leftStack[++leftTop] = rightStack[rightTop--];
			}
			else if(input[i] == '-')
			{
				if(leftTop > -1)	leftTop--;
			}
			else
			{
				leftStack[++leftTop] = input[i];
			}
		}
		for(int i=0; i<=leftTop; i++)
		{
			printf("%c",leftStack[i]);
		}
		for(int i=rightTop; i>=0; i--)
		{
			printf("%c",rightStack[i]);
		}
		printf("\n");
		leftTop = -1;
		rightTop = -1;
	}
	//scanf("%d",&leftTop);
	
	return 0;
}
