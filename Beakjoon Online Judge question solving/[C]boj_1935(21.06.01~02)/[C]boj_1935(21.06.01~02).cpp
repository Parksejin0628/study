//number of question : 1935
//Difficulty : Silver 3
//Time to solve : 40m 38s
//Simple review : 

#include<stdio.h>
#include<string.h>

int main(void)
{
	int n=0;
	double num[30] = {0};
	double stack[30] = {0};
	int top = -1;
	char input[110] = {'\0'};
	
	scanf("%d", &n);
	fgetc(stdin); 
	fgets(input, 110, stdin);
	for(int i=0; i<n; i++)
	{
		scanf("%lf",&num[i]);
	}
	for(int i=0; input[i] != '\0' && input[i] != '\n'; i++)
	{
		if(input[i] == '+')
		{
			stack[top-1] = stack[top-1] + stack[top];
			top--;
		} 
		else if(input[i] == '-')
		{
			stack[top-1] = stack[top-1] - stack[top];
			top--;
		} 
		else if(input[i] == '*')
		{
			stack[top-1] = stack[top-1] * stack[top];
			top--;
		} 
		else if(input[i] == '/')
		{
			stack[top-1] = stack[top-1] / stack[top];
			top--;
		} 
		else 
		{
			stack[++top] = num[(int)(input[i]) - (int)('A')];
		} 
	/*	for(int j=0; j<=top; j++)
		{
			printf("%.2lf ", stack[j]);
		}
		printf("\n");*/
	}
	printf("%.2lf",stack[0]);
	//scanf("%d",&n);
	
	return 0;
}
