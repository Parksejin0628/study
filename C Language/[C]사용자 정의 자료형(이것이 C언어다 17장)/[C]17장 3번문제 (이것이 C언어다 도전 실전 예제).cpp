#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char **word;
	char input_word[80]; 
	char last = '\0';
	int cnt = 0;
	int i = 0;
	int overlap = 0;
	
	word = (char**)malloc(sizeof(char*));
	
	while(1)
	{
		printf("단어 입력 : ");
		scanf("%s", input_word);
		if(strcmp(input_word, "end") == 0)	break;
		if(input_word[0] != last && cnt != 0)
		{
			printf("# 단어 잇기가 불가능합니다!\n");
			continue;
		}
		for(i=0; i<cnt; i++)
		{
			if(strcmp(word[i], input_word) == 0)
			{
				overlap = 1;
			}
		}
		if(overlap)
		{
			printf("# 이미 존재하는 단어입니다!\n");
			overlap = 0;
			continue;
		}
		cnt++;
		word = (char**)realloc(word, cnt * sizeof(char*));
		word[cnt-1] = (char*)malloc(strlen(input_word) + 1);
		last = input_word[strlen(input_word)-1]; 	
		
		strcpy(word[cnt-1], input_word);
	} 
	for(i=0; i<cnt; i++)
	{
		printf("%s ", word[i]);
	}
	
	scanf("%d");
	
	return 0;
}


/*
도전 3 끝말 잇기 프로그램
 - 단어를 입력하여 끝말 잇기를 합니다. 이미 입력된 단어와 끝말 잇기가 되지 않는 단어는 확인하여 제외합니다. end를 입력하면 입력을 끝내고 그 동안 입력한 모든 단어를 차례로 출력합니다.
  입력한 단어는 그 길이에 맞는 동적 할당 영역에 저장하며 입력 가능한 단어 수는 최대 100개로 제한합니다. 
*/ 
