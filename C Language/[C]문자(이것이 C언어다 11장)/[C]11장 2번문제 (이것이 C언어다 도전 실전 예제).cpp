#include<stdio.h>
#include<string.h>

int main(void)
{
	char ch = '\0';
	
	while(true)
	{
		ch = getchar();
		if(ch == '\n')
		{
			break;
		}
		if(ch >= 'a' && ch <='z')
		{
			putchar(ch - ('a' - 'A'));
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			putchar(ch + 'a' - 'A');
		}
		else
		{
			putchar(ch);
		}
	
	}
	scanf("%d");
	
	return 0;
}
