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
		printf("�̸� : ");
		scanf("%s", input_name);
		if(strcmp(input_name, "end") == 0)
		{
			break;
		}
		printf("��α� : ");
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
	printf("��� ��ξ� : %d", sum / cnt);
	
	free(name);
	free(donation);
	
	scanf("%d");
	
	return 0;
}


/*
���� 1 ��α� ���� ���α׷�
 - �ڼ���ü�� ����ϴ� ������� ��ܰ� �ݾ��� �Է��� �Ŀ� ��� ��ξ��� ����մϴ�. ����ϴ� ����� ���� ������ ������ �̸����� 'end'�� �Է��ϸ� �Է��� �����մϴ�. 
*/ 
