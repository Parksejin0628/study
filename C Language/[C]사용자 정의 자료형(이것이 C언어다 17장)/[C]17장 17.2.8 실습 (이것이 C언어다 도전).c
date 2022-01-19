#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef union
{
	int ea;
	double kg;
	double liter;
}Unit;

typedef struct
{
	char name[20];
	enum { EGG = 1, MILK, MEAT	}	kind;
	Unit amount;
}Gift;

void print_list(Gift a);

int main(void)
{
	Gift list[5];
	int i;
	
	for(i=0; i<5; i++)
	{
		printf("�̸� �Է� : ");
		scanf("%s", list[i].name);
		printf("ǰ�� ����(1. ���, 2.����, 3.���) : ");
		scanf("%d", &list[i].kind);
		
		switch(list[i].kind)
		{
			case EGG : list[i].amount.ea = 30; break;
			case MILK : list[i].amount.kg = 4.5; break;
			case MEAT : list[i].amount.kg = 0.6; break;
		}
		
		/*if(list[i].kind == EGG)	list[i].amount.ea = 30;
		else if(list[i].kind == MILK)	list[i].amount.kg = 4.5;
		else	list[i].amount.kg = 0.6;*/
	}
	
	printf("# �� ��° ��ǰ ��÷��...\n");
	print_list(list[2]);
	
	scanf("%d");
	
	return 0;
}

void print_list(Gift a)
{
	printf(" �̸� : %s, ���� ǰ�� : ", a.name);
	
	if(a.kind == EGG)	printf("��� %d��\n", a.amount.ea);
	else if(a.kind == MILK)	printf("���� %.1lf����\n", a.amount.liter);
	else	printf("��� %.1lfkg\n", a.amount.kg);
	
	return;
}



