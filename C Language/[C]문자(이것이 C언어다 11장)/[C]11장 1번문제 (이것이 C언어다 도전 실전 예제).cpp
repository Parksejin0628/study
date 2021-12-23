#include<stdio.h>
#include<string.h>

int main(void)
{
	char ch = '\0';
	int length_max = 0;
	int length = 0;
	
	while(true)
	{
		ch = getchar();
		if(ch == -1)
		{
			break;
		}
		if(ch == '\n')
		{
			length = 0;
			continue;
		}
		length++;
		if(length_max < length)
		{
			length_max = length;
		}
	}
	
	printf("가장 긴 단어의 길이 : %d\n", length_max);
	scanf("%d");
	
	return 0;
}
