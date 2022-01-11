#include<stdio.h>
#include<string.h>

void init_intro(char (*intro)[80], char **pint);
int input_intro(char (*intro)[80]);
void sort_intro(char **pint, int cnt);
void print_intro(int mode, void *vp, int cnt); 

int main(void)
{
	char intro[10][80];
	char *pint[10];
	int cnt;
	
	init_intro(intro, pint);
	cnt = input_intro(intro);
	sort_intro(pint, cnt);
	print_intro(1, pint, cnt);
	print_intro(0, intro, cnt);
	
	scanf("%d");
	
	return 0;
}

void init_intro(char (*intro)[80], char **pint)
{
	int i = 0;
	for(i=0; i<10; i++)
	{
		pint[i] = intro[i];
	}
	
	return;
}

int input_intro(char (*intro)[80])
{
	int cnt = 0;
	char input[80];
	
	while(1)
	{
		printf("인사말 입력 : ");
		gets(input);
		if(strcmp(input, "end") == 0 || cnt >= 10)
		{
			return cnt;
		}
		strcpy(intro[cnt++], input);
	}
	
	return cnt;
}

void sort_intro(char **pint, int cnt)
{
	int i = 0;
	int j = 0;
	char *temp;
	for(i=0; i<cnt; i++)
	{
		for(j=i+1; j<cnt; j++)
		{
			if(strcmp(pint[i], pint[j]) > 0)
			{
				temp = pint[i];
				pint[i] = pint[j];
				pint[j] = temp;
			}
		}
	}
}

void print_intro(int mode, void *vp, int cnt)
{
	int i = 0;
	if(mode==1)
	{
		printf("# 사전순으로 출력...\n");
		for(i=0; i<cnt; i++)
		{
			printf("%s\n", *((char**)vp + i));
		}
	}
	else	
	{
		printf("# 입력순으로 출력...\n");
		for(i=0; i<cnt; i++)
		{
			printf("%s\n", (char*)vp + (80*i));
		}
	}
	
	return;
}


/*
도전 3 인사말 정렬 프로그램
 - 키보드로 인사말을 입력한 후에 사전순으로 정렬하여 출력합니다. 이어서 입력한 순서대로 다시 한 번 출력합니다.
   정렬은 입력한 문자열을 바꾸지 않고 포이터 배열의 연결 순서를 바꾸어 구현합니다. 
*/ 
