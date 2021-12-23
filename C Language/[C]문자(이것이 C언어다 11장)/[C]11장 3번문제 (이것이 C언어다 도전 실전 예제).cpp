#include<stdio.h>
#include<string.h>

int main(void)
{
	char ch = '\0';
	int seat = 0;
	int answer = 0;
	
	for(seat = 0; seat<=10; seat++)
	{
		ch = getchar();
		if(ch == '\n')
		{
			break;
		}
		answer *= 10;
		answer += (int)(ch - '0');
	}
	printf("%d\n", answer+10);
	
	scanf("%d");
	
	return 0;
}
