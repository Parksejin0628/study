#include<stdio.h>

char *my_token(char *ps);

int main(void)
{
	char str[80];
	char *p;
	
	printf("문장 입력 : ");
	gets(str);
	
	while((p = my_token(str)) != NULL)
	{
		printf("%s\n", p);
	}
	scanf("%d");
	
	return 0;
}

char *my_token(char *ps)
{
	static int addIndex;
	static char voca[80];
	int startIndex = addIndex;
	int vocaIndex = 0;
	
	if(*(ps+addIndex) == '\0')	return NULL;
	
	while(*(ps+addIndex) != ' ')
	{
		voca[vocaIndex++] = ps[addIndex];
		addIndex++;
	}
	voca[vocaIndex] = '\0';
	addIndex++;
	
	return voca;
}


/*
도전 3 단어 추출 프로그램 
 - 키보드로 한 줄의 문장을 입력한 후에 단어를 분리하여 출력하는 프로그램을 작성합니다. 단, 문장에서 단어를 분리하여 그 시작 주소를 반환하는 함수를 만들어 구현합니다.
   <char *my_token(char *ps)> 매개변수 ps는 단어를 분리할 문장의 포인터며 반환값은 분리한 단어의 주소입니다.
   함수를 반복 호출하면 문장의 모든 단어를 분리할 때까지 한 단어씩 주소를 반환합ㄴ디ㅏ. 함수 안에서는 정적 변수를 사용하여 끊어낼 다음 단어의 위치를 기억합니다. 
*/ 
