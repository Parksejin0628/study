#include<stdio.h>
#include<string.h> 

int main(void)
{
	char output[1000] = {'\0'};
	char input[100] = {'\0'};
	while(1)
	{
		printf("단어 입력 : ");
		scanf("%s", input);
		if(strcmp(input, "end") == 0)
		{
			break;
		}
		strcat(output, input);
		strcat(output, " ");
		printf("현재까지의 문자열 : %s\n", output); 
	}
	
	scanf("%d");
	
	return 0;
}



/*
도전 2 단어 이어 출력하기
 - 키보드로 입력한 단어를 이어붙여 반복 출력합니다. end를 입력하면 반복을 종료합니다. 
*/ 
