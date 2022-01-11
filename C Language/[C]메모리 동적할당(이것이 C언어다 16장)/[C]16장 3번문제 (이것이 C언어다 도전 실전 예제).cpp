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
		printf("�λ縻 �Է� : ");
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
		printf("# ���������� ���...\n");
		for(i=0; i<cnt; i++)
		{
			printf("%s\n", *((char**)vp + i));
		}
	}
	else	
	{
		printf("# �Է¼����� ���...\n");
		for(i=0; i<cnt; i++)
		{
			printf("%s\n", (char*)vp + (80*i));
		}
	}
	
	return;
}


/*
���� 3 �λ縻 ���� ���α׷�
 - Ű����� �λ縻�� �Է��� �Ŀ� ���������� �����Ͽ� ����մϴ�. �̾ �Է��� ������� �ٽ� �� �� ����մϴ�.
   ������ �Է��� ���ڿ��� �ٲ��� �ʰ� ������ �迭�� ���� ������ �ٲپ� �����մϴ�. 
*/ 
