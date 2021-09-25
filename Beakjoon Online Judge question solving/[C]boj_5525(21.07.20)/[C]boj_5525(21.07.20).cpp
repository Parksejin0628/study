//number of question : 5525
//Difficulty : Silver 2
//Time to solve : 21m 29s
//Simple review : 

#include<stdio.h>
#include<string.h>

char input[1001000] = {'\0'};

int main(void)
{
	int n = 0;
	int m = 0;
	int answer = 0;
	int length_IOI = -1;
	int turn = 0;
	
	scanf("%d",&n);
	scanf("%d",&m);
	fgetc(stdin);
	fgets(input, 1001000, stdin);
	
	for(int i=0; i<m; i++)
	{
		if(input[i] == 'I')
		{
			//printf("check1\n");
			if(turn == 1)
			{
				length_IOI = -1;
				turn = 0;
			}
			turn = 1;
			length_IOI++;
			if(length_IOI >= n)
			{
				answer++;
			}
		}
		else
		{
			//printf("check2\n");
			if(turn == 0)
			{
				length_IOI = -1;
			}	
			turn = 0;
		}	
	} 
	
	printf("%d\n",answer);
	scanf("%d",&n);
	
	
	return 0;
}
