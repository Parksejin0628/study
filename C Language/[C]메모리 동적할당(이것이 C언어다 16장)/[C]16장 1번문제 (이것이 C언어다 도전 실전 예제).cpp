#include<stdio.h>
#include<string.h>

int input_name(char (*name)[20]);
void print_name(char (*name)[20], int cnt);
int check_overlap_name(char *input, char (*name)[20], int cnt);

int main(void)
{
	char name[10][20];
	int cnt;
	
	cnt = input_name(name);
	print_name(name, cnt);
	
	scanf("%d");
	
	return 0;
}

int input_name(char (*name)[20])
{
	char input[20] = {'\0'};
	int cnt = 0;
	
	while(1)
	{
		printf("이름 : ");
		gets(input);
		if(strcmp(input, "end")==0 || cnt > 9)
		{
			printf("# 총 %d명이 입력되었습니다.\n", cnt);
			break;
		}
		if(check_overlap_name(input, name, cnt) == 0)
		{
			strcpy(name[cnt], input);
			cnt++;
		}
		else
		{
			printf("# 이름이 이미 등록되었습니다!\n");
		}
	}
	
	return cnt;
}
int check_overlap_name(char *input, char (*name)[20], int cnt)
{
	int i = 0;
	for(i=0; i<cnt; i++)
	{
		if(strcmp(input, name[i]) == 0)	return 1;
	}
	return 0;
}

void print_name(char (*name)[20], int cnt)
{
	int i = 0;
	for(i=0; i<cnt; i++)
	{
		printf("%s\n", name[i]);
	}
	
	return;
}


/*
도전 1 방명록 프로그램
 - 키보드로 이름을 반복 입력한 후 입력된 모든 이름을 출력합니다. 이름은 최대 10명까지 입력할 수 있으며 같은 이름이 입력되면 중복 메시지를 출력하고 end가 입력되면 입력을 끝냅니다.
   이름을 저장할 2차원 char 배열은 main 함수에 작성하고 이름을 입력하는 함수, 중복 여부를 검사하는 함수, 출력하는 함수를 작성하여 완성합니다.  
*/ 
