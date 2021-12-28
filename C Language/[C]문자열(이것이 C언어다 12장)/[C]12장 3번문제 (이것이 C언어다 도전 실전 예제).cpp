#include<stdio.h>
#include<string.h> 

int main(void)
{
	char sentence[1000] = {'\0'};
	char input[100] = {'\0'};
	int result = 0;
	int i = 0;
	
	printf("문장 입력 : ");
	gets(sentence);
	while(1)
	{
		printf("검색할 문자열 입력 (종료는 end) : ");
		gets(input);
		if(strcmp(input, "end") == 0)
		{
			break;
		}
		for(int i=0; sentence[i] != '\0'; i++)
		{
			//printf("check1 : %s / %s - %d, %d\n", sentence+i, input, strncmp(sentence + i, input, strlen(input)), strlen(input));
			if(strncmp(sentence + i, input, strlen(input)) == 0)
			{
				result ++;
				i += (strlen(input)-1);
			}
		}
		printf("검색결과 : %d개\n", result); 
		result = 0;
	}
	
	scanf("%d");
	
	return 0;
}


/*
도전 3 문자열 검색 프로그램 
 - 키보드로 입력한 문장에서 원하는 문자열을 찾아 그 개수를 출력하는 프로그램을 만듭니다. 
 문장은 한 번만 입력하며 문자열 검색은 end가 입력될 때까지 반복합니다. 
*/ 
