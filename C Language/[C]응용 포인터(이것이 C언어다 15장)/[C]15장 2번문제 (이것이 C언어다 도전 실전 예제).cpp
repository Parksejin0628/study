#include<stdio.h>
#include<string.h>

int main(void)
{
	char word[15][25];
	char research[25];
	int index = 0;
	int i = 0; 
	int check = 0;
	
	while(1)
	{
		printf("�ܾ� �Է� (����� end �Է�) : ");
		gets(word[index]);
		printf("check\n");
		if(strcmp(word[index], "end") == 0)
		{
			printf("# �� %d���� �ܾ �ԷµǾ����ϴ�!\n\n", index);
			break;
		}
		index++;
	}
	
	while(1)
	{
		printf("�˻� �ܾ� (����� end �Է�) : ");
		gets(research);
		if(strcmp(research, "end") == 0)
		{
			break;
		}
		for(i=0; i<index; i++)
		{
			if(strcmp(word[i], research) == 0)
			{
				printf("# %d��° ���� �ܾ �ֽ��ϴ�!\n", i+1);
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			printf("# ���� �ܾ��Դϴ�.\n");
		}
		check = 0;
	}
	
	 
	
	scanf("%d");
	
	return 0;
}


/*
���� 2 �ܾ� �˻� ���α׷�   
 - Ű����� ���� ���� �ܾ �Է��� �Ŀ� ���ϴ� �ܾ ã�� ���α׷��� �ۼ��մϴ�. �Է� �ܾ��� ���� �ִ� 10�������� �� �ܾ��� ���̴� �ִ� 20�ڷ� �����մϴ�. 
*/ 
