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
		printf("�̸� : ");
		gets(input);
		if(strcmp(input, "end")==0 || cnt > 9)
		{
			printf("# �� %d���� �ԷµǾ����ϴ�.\n", cnt);
			break;
		}
		if(check_overlap_name(input, name, cnt) == 0)
		{
			strcpy(name[cnt], input);
			cnt++;
		}
		else
		{
			printf("# �̸��� �̹� ��ϵǾ����ϴ�!\n");
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
���� 1 ���� ���α׷�
 - Ű����� �̸��� �ݺ� �Է��� �� �Էµ� ��� �̸��� ����մϴ�. �̸��� �ִ� 10����� �Է��� �� ������ ���� �̸��� �ԷµǸ� �ߺ� �޽����� ����ϰ� end�� �ԷµǸ� �Է��� �����ϴ�.
   �̸��� ������ 2���� char �迭�� main �Լ��� �ۼ��ϰ� �̸��� �Է��ϴ� �Լ�, �ߺ� ���θ� �˻��ϴ� �Լ�, ����ϴ� �Լ��� �ۼ��Ͽ� �ϼ��մϴ�.  
*/ 
