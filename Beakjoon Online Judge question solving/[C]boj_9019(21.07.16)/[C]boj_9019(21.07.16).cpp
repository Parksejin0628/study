//number of question : 9019
//Difficulty : Gold 5
//Time to solve : 1h 5m 18s
//Simple review : 

#include<stdio.h>
#include<string.h>

typedef struct Stack
{
	int num;
	char command[2000] = {'\0'};
}stack;

void searchAnswer(int firstNum, int targetNum);
int D(int num);
int S(int num);
int L(int num);
int R(int num);

char answer[2000] = {'\0'};
stack searchStack[2][20000];


int main(void)
{
	int testcase = 0;
	int initNum = 0;
	int targetNum = 0;
	
	scanf("%d",&testcase);
	for(int t=1; t<=testcase; t++)
	{
		scanf("%d %d", &initNum, &targetNum);
		searchAnswer(initNum, targetNum);
		printf("%s\n", answer);
		for(int i=0; i<20000; i++)
		{
			strcpy(searchStack[0][i].command, "\0");
			strcpy(searchStack[1][i].command, "\0");
		}
	}
	scanf("%d", &testcase);
	
	return 0;
}

void searchAnswer(int firstNum, int targetNum)
{
	int checkBFS[10000] = {0};
	int top[2] = {-1, -1};
	int level = -1;
	int temp = 0;
	int now = 0;
	int next = 1;
	char command[2000] = {'\0'};
	
	searchStack[now][++top[now]].num = firstNum;
	
	while(top[now] > -1)
	{
		level++;
		while(top[now] > -1)
		{
			//printf("check1 - level : %d\n", level);
			temp = D(searchStack[now][top[now]].num);
			strcpy(command,searchStack[now][top[now]].command);
			//printf("check2-1 : D - %d\n", temp);
			if(checkBFS[temp] != 1)
			{
				searchStack[next][++top[next]].num = temp;
				strcpy(searchStack[next][top[next]].command, strcat(command, "D"));
				checkBFS[temp] = 1;
				if(temp == targetNum)
				{
					//printf("check3 - answer : %s\n", searchStack[next][top[next]].command);
					strcpy(answer, searchStack[next][top[next]].command);
					return;
				}
			}
			
			temp = S(searchStack[now][top[now]].num);
			strcpy(command,searchStack[now][top[now]].command);
			//printf("check2-2 : S - %d\n", temp);
			if(checkBFS[temp] != 1)
			{
				searchStack[next][++top[next]].num = temp;
				strcpy(searchStack[next][top[next]].command, strcat(command, "S"));
				checkBFS[temp] = 1;
				if(temp == targetNum)
				{
					//printf("check3 - answer : %s\n", searchStack[next][top[next]].command);
					strcpy(answer, searchStack[next][top[next]].command);
					return;
				}
			}
			
			temp = L(searchStack[now][top[now]].num);
			strcpy(command,searchStack[now][top[now]].command);
			//printf("check2-3 : L - %d\n", temp);
			if(checkBFS[temp] != 1)
			{
				searchStack[next][++top[next]].num = temp;
				strcpy(searchStack[next][top[next]].command, strcat(command, "L"));
				checkBFS[temp] = 1;
				if(temp == targetNum)
				{
					//printf("check3 - answer : %s\n", searchStack[next][top[next]].command);
					strcpy(answer, searchStack[next][top[next]].command);
					return;
				}
			}
			
			temp = R(searchStack[now][top[now]].num);
			strcpy(command,searchStack[now][top[now]].command);
			//printf("check2-4 : R - %d\n", temp);
			if(checkBFS[temp] != 1)
			{
				searchStack[next][++top[next]].num = temp;
				strcpy(searchStack[next][top[next]].command, strcat(command, "R"));
				checkBFS[temp] = 1;
				if(temp == targetNum)
				{
					//printf("check3 - answer : %s\n", searchStack[next][top[next]].command);
					strcpy(answer, searchStack[next][top[next]].command);
					return;
				}
			}
			top[now] --;
		}
		temp = now;
		now = next;
		next = temp;
	}
	
	return;
}

int D(int num)
{
	int temp = num * 2;
	if(temp > 9999)
	{
		temp %= 10000;
	}
	return temp;
}

int S(int num)
{
	int temp = num - 1;
	if(temp < 0)
	{
		temp = 9999;
	}
	return temp;
}

int L(int num)
{
	int d1 = num/1000;
	int d2 = (num/100) % 10;
	int d3 = (num/10) % 10;
	int d4 = num % 10;
	
	return d2*1000 + d3*100 + d4*10 + d1;
}

int R(int num)
{
	int d1 = num/1000;
	int d2 = (num/100) % 10;
	int d3 = (num/10) % 10;
	int d4 = num % 10;
	
	return d4*1000 + d1*100 + d2*10 + d3;
}
