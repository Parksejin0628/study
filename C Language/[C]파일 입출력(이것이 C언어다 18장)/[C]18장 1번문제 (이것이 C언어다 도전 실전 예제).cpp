#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct money_box
{
	int w500;
	int w100;
	int w50;
	int w10;
};

typedef struct money_box MoneyBox;

void init(MoneyBox *s);
void save(MoneyBox *s, int unit, int cnt);
int total(MoneyBox *s);

int main(void)
{
	MoneyBox moneybox;
	int unit;
	int cnt;
	
	init(&moneybox);
	
	while(1)
	{
		printf("동전의 금액과 개수 : ");
		scanf("%d", &unit);
		if(unit <= 0)
		{
			break;
		}
		scanf("%d", &cnt);
		save(&moneybox, unit, cnt);
	}
	
	//printf("check\n");
	printf("총 저금액 : %d\n", total(&moneybox));
	
	scanf("%d");
	
	return 0;
}

void init(MoneyBox *s)
{
	*s = {0, 0, 0, 0};
	
	return;
}

void save(MoneyBox *s, int unit, int cnt)
{
	if(unit == 500)
	{
		s->w500 += cnt;
	}
	else if(unit == 100)
	{
		s->w100 += cnt;
	}
	else if(unit == 50)
	{
		s->w50 += cnt;
	}
	else if(unit == 10)
	{
		s->w10 += cnt;
	}
	
	return;
}

int total(MoneyBox *s)
{
	int sum = 0;
	
	sum += s->w500 * 500;
	sum += s->w100 * 100;
	sum += s->w50 * 50;
	sum += s->w10 * 10;
	
	return sum;
}


/*
도전 1 저금통 프로그램
 - 저금할 동전의 금액과 개수를 반복 입력하여 저금통에 저금합니다. 금액으로 0 또는 음수가 입력되면 입력을 마치고 총 저축액을 출력합니다. 
*/ 
