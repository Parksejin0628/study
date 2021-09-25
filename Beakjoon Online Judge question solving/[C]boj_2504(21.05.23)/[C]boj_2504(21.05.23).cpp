//number of question : 2504
//Difficulty : Silver 2
//Time to solve : 31m 16s
//Simple review : 

#include<stdio.h>
#include<string.h>

int main(void)
{
	char input[40] = {'\0'};
	int stack[40] = {0};
	int top = -1;
	int calStack[40] = {0};
	
	fgets(input, 40, stdin);
	for(int i=0; i<40; i++)
	{
		if(input[i] == '\0')	break;
		if(input[i] == '(')
		{
			stack[++top] = 2;
		}
		else if(input[i] == '[')
		{
			stack[++top] = 3;
		}
		else if(input[i] == ')')
		{
			if(stack[top] != 2)
			{
				//printf("check1\n");
				printf("0");
				//scanf("%s", input);
				return 0;
			}
			if(calStack[top + 1] != 0)
			{
				calStack[top] += 2 * calStack[top + 1];
			}
			else
			{
				calStack[top] += 2;
			}
			calStack[top + 1] = 0;
			top--;
		}
		else if(input[i] == ']')
		{
			if(stack[top] != 3)
			{
				//printf("check2\n");
				printf("0");
				//scanf("%s", input);
				return 0;
			}
			if(calStack[top + 1] != 0)
			{
				calStack[top] += 3 * calStack[top + 1];
			}
			else
			{
				calStack[top] += 3;
			}
			calStack[top + 1] = 0;
			top--;
		}
	} 
	if(top != -1)
	{
	//	printf("check3\n");
		printf("0");
	}
	else	printf("%d",calStack[0]);
	
	//scanf("%s",input);
	
	return 0;
}
