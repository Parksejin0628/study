#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{
	int i = 0;
	int cnt = 0;
	int input_donation;
	char input_name[20];
	int *donation;
	char **name;
	int sum = 0;
	
	donation = (int*)malloc(sizeof(int));
	name = (char**)malloc(sizeof(char));
	
	while(1)
	{
		printf("이름 : ");
		scanf("%s", input_name);
		if(strcmp(input_name, "end") == 0)
		{
			break;
		}
		printf("기부금 : ");
		scanf("%d", &input_donation);
		cnt++;
		donation = (int*)realloc(donation, cnt * sizeof(int));
		name = (char**)realloc(name, cnt * sizeof(char*));
		name[cnt-1] = (char*)malloc(strlen(input_name)+1);
		donation[cnt-1] = input_donation;
		sum += input_donation;
		strcpy(name[cnt-1], input_name);
	}
	for(i=0; i<cnt; i++)
	{
		printf("%d. %s %d\n", i+1, name[i], donation[i]);
	}
	printf("평균 기부액 : %d", sum / cnt);
	
	free(name);
	free(donation);
	
	scanf("%d");
	
	return 0;
}


/*
도전 1 기부금 관리 프로그램
 - 자서단체에 기부하는 사람들의 명단과 금액을 입력한 후에 평균 기부액을 출력합니다. 기부하는 사람의 수는 제한이 없으며 이름으로 'end'를 입력하면 입력을 종료합니다. 
*/ 
