//number of question : 1918
//Difficulty : Gold 4
//Time to solve : 1h 30m
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char input[110] = {'\0'};
char opStack[110] = {'\0'};
int opStackTop = -1;
int standardStack[110] = {-1, 0};
int stStackTop = 0; 

void plus()
{
	if(opStackTop <= standardStack[stStackTop])
	{
		//printf("\ncheck1\n");
		opStack[++opStackTop] = '+';
	}
	else
	{
		for(int i=opStackTop; i>standardStack[stStackTop]; i--)
		{
			printf("%c", opStack[i]);
		}
		opStackTop = standardStack[stStackTop];
		opStack[++opStackTop] = '+';
	}
}

void minus()
{
	if(opStackTop <= standardStack[stStackTop])
	{
		opStack[++opStackTop] = '-';
	}
	else
	{
		for(int i=opStackTop; i>standardStack[stStackTop]; i--)
		{
			printf("%c", opStack[i]);
		}
		opStackTop = standardStack[stStackTop];
		opStack[++opStackTop] = '-';
	}
}

void multi()
{
	if(opStackTop <= standardStack[stStackTop] || opStack[opStackTop] == '+' || opStack[opStackTop] == '-')
	{
		opStack[++opStackTop] = '*';
	}
	else
	{
		printf("%c",opStack[opStackTop]);
		opStack[opStackTop] = '*';
	}
}

void division()
{
	if(opStackTop <= standardStack[stStackTop] || opStack[opStackTop] == '+' || opStack[opStackTop] == '-')
	{
		opStack[++opStackTop] = '/';
	}
	else
	{
		printf("%c",opStack[opStackTop]);
		opStack[opStackTop] = '/';
	}
}

void open()
{
	standardStack[++stStackTop] = opStackTop;
}

void close()
{
	for(int i=opStackTop; i>standardStack[stStackTop]; i--)
	{
		//printf("check1 - i : %d, standardStack[%d] : %d\n",i, stStackTop, standardStack[stStackTop]);
		printf("%c", opStack[i]);
	}
	opStackTop = standardStack[stStackTop];
	stStackTop--;
}

int main(void)
{
	fgets(input, 110, stdin);
	
	for(int i=0; input[i]!='\0' && input[i]!='\n' && i<110; i++)
	{
		if(input[i] == '+')
		{
			//printf("\ncheck-plus\n"); 
			plus();
		}
		else if(input[i] == '-')
		{
			//printf("\ncheck-minus\n"); 
			minus();
		}
		else if(input[i] == '*')
		{
			//printf("\ncheck-multi\n"); 
			multi();
		}
		else if(input[i] == '/')
		{
			//printf("\ncheck-division\n"); 
			division();
		}
		else if(input[i] == '(')
		{
		//	printf("\ncheck-open\n"); 
			open();
		}
		else if(input[i] == ')')
		{
			//printf("\ncheck-close\n"); 
			close();
		}
		else
		{
			printf("%c",input[i]);
		}
		//printf("\n1 : %c 2 : %c\n",opStack[0],opStack[1]);
	}
	//printf("opStackTop : %d\n", opStackTop);
	for(int i=opStackTop; i>=0; i--)
	{
		printf("%c", opStack[i]);
	}
	//scanf("%d", &opStackTop);
	
	return 0;
}
