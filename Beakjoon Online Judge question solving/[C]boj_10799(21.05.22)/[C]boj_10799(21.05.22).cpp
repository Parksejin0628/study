//number of question : 10799
//Difficulty : Silver 4
//Time to solve : 13m 18s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int main(void)
{
	int count = 0;
	int stack = 0;
	char input[100100] = {'\0'};
	
	fgets(input, 100100, stdin);
	for(int i=0; i<=100100; i++)
	{
		if(input[i]=='(')
		{
			count++;
			stack++;
		}
		else if(input[i]==')')
		{
			if(input[i-1]=='(')
			{
				count--;
				stack--;
				count += stack;
			}
			else
			{
				stack--;
			}
		}
		else	break;
		//printf("%d번째 문자 확인중... stack : %d, count : %d\n", i+1, stack, count);
	}
	printf("%d\n",count);
	//scanf("%d",&count);
	
	return 0;
}
