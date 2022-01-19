#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int num;
	char name[20];
	double weight;
}Fitness;

int input_member(Fitness **pary);
double average_weight(Fitness **pary, int cnt);
int max_weight(Fitness **pary, int cnt);
void print_info(Fitness **pary, int index);
void free_ary(Fitness **pary, int cnt);


int main(void)
{
	Fitness* members[100] = {NULL} ;
	int inputNum = 0;
	char inputName[20];
	double inputWeight; 
	int memberCnt;
	int highestMember = 0; 
	
	for(memberCnt=0; memberCnt<100; memberCnt++)
	{
		printf("ȸ�� ��ȣ : "); 
		scanf("%d", &inputNum);
		if(inputNum < 0)
		{
			break;
		}
		printf("�̸� �Է� : ");
		scanf("%s", inputName);
		printf("ü�� �Է� : ");
		scanf("%lf", &inputWeight);
		members[memberCnt] = (Fitness*)malloc(sizeof(Fitness));
		members[memberCnt]->num = inputNum;
		members[memberCnt]->weight = inputWeight;
		strcpy(members[memberCnt]->name, inputName);
	}
	printf("# �� ȸ���� : %d\n", input_member(members));
	printf("# ��� ü�� : %.1lf\n", average_weight(members, memberCnt));
	printf("# ü���� ���� ���ſ� ȸ����?\n");
	highestMember = max_weight(members, memberCnt);
	print_info(members, highestMember);
	
	free_ary(members, memberCnt);
	
	scanf("%d");
	
	return 0;
}

int input_member(Fitness **pary)
{
	int cnt = 0;
	while(pary[cnt] != NULL)
	{
		cnt++;
	}
	
	return cnt;
}

double average_weight(Fitness **pary, int cnt)
{
	int i = 0;
	double sum = 0;
	
	for(i=0; i<cnt; i++)
	{
		sum += pary[i]->weight;
	}
	
	return sum / cnt;
}

int max_weight(Fitness **pary, int cnt)
{
	int i = 0;
	double max = 0;
	int max_index;
	
	for(i=0; i<cnt; i++)
	{
		if(pary[i]->weight > max)
		{
			max = pary[i]->weight;
			max_index = i;
		}
	}
	
	return max_index;
}

void print_info(Fitness **pary, int index)
{
	printf("ȸ�� ��ȣ : %d\n", pary[index]->num);
	printf("�̸� : %s\n", pary[index]->name);
	printf("ü�� : %.1lf\n", pary[index]->weight);
}

void free_ary(Fitness **pary, int cnt)
{
	int i = 0;
	
	for(i=0; i<cnt; i++)
	{
		free(pary[i]);
	}
	
	return;
}


/*
���� 2 ��Ʈ�Ͻ� ������ ȸ������ ���α׷�
 - �ű� ȸ���� ����ϸ� ȸ����ȣ, �̸�, ü���� �Է��Ͽ� ���� �Ҵ� ������ �����մϴ�. 
   ȸ�� ��ȣ�� ������ �Է��ϸ� �Է� �۾��� ��ġ�� �� ȸ�� ��, ��� ü��, �ְ� ü���� ���� ȸ���� ������ ����մϴ�.
   �ִ� ��� ȸ������ 100������ �����մϴ�. 
*/ 
