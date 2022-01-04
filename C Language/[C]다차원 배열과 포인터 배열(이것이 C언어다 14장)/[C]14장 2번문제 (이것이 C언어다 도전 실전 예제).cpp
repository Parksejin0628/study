#include<stdio.h>
#include<string.h>

int main(void)
{
	char word[15][25];
	char research[25];
	int index = 0;
	int i = 0; 
	int check = 0;
	
	while(1)
	{
		printf("단어 입력 (종료는 end 입력) : ");
		gets(word[index]);
		printf("check\n");
		if(strcmp(word[index], "end") == 0)
		{
			printf("# 총 %d개의 단어가 입력되었습니다!\n\n", index);
			break;
		}
		index++;
	}
	
	while(1)
	{
		printf("검색 단어 (종료는 end 입력) : ");
		gets(research);
		if(strcmp(research, "end") == 0)
		{
			break;
		}
		for(i=0; i<index; i++)
		{
			if(strcmp(word[i], research) == 0)
			{
				printf("# %d번째 같은 단어가 있습니다!\n", i+1);
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			printf("# 없는 단어입니다.\n");
		}
		check = 0;
	}
	
	 
	
	scanf("%d");
	
	return 0;
}


/*
도전 2 단어 검색 프로그램   
 - 키보드로 여러 개의 단어를 입력한 후에 원하는 단어를 찾는 프로그램을 작성합니다. 입력 단어의 수는 최대 10개까지며 한 단어의 길이는 최대 20자로 제한합니다. 
*/ 
