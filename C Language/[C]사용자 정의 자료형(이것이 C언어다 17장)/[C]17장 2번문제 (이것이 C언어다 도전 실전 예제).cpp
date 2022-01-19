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
		printf("회원 번호 : "); 
		scanf("%d", &inputNum);
		if(inputNum < 0)
		{
			break;
		}
		printf("이름 입력 : ");
		scanf("%s", inputName);
		printf("체중 입력 : ");
		scanf("%lf", &inputWeight);
		members[memberCnt] = (Fitness*)malloc(sizeof(Fitness));
		members[memberCnt]->num = inputNum;
		members[memberCnt]->weight = inputWeight;
		strcpy(members[memberCnt]->name, inputName);
	}
	printf("# 총 회원수 : %d\n", input_member(members));
	printf("# 평균 체중 : %.1lf\n", average_weight(members, memberCnt));
	printf("# 체중이 가장 무거운 회원은?\n");
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
	printf("회원 번호 : %d\n", pary[index]->num);
	printf("이름 : %s\n", pary[index]->name);
	printf("체중 : %.1lf\n", pary[index]->weight);
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
도전 2 피트니스 센터의 회원관리 프로그램
 - 신규 회원이 등록하면 회원번호, 이름, 체중을 입력하여 동적 할당 영역에 저장합니다. 
   회원 번호로 음수를 입력하면 입력 작업을 마치고 총 회원 수, 평균 체중, 최고 체중을 갖는 회원의 정보를 출력합니다.
   최대 등록 회원수는 100명으로 제한합니다. 
*/ 
