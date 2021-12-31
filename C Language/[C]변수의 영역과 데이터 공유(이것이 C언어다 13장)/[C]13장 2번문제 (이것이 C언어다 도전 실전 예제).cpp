#include<stdio.h>

void set(int h, int m);		// ���� �ð��� ���� �����ϴ� �Լ� 
void show(void);			// �ð��� ���� ȭ�鿡 ����ϴ� �Լ� 
void move(void); 			// �� �� ȣ��� ������ 1�о� �ð� ����  

int hour = 0;
int min = 0; 

int main(void)
{
	int addMin = 0;
	int defaultHour = 0;
	int defaultMin = 0;
	
	printf("���� �ð��� �� �Է�(24�ð�) : ");
	scanf("%d %d", &defaultHour, &defaultMin);
	
	set(defaultHour, defaultMin); 
	
	printf("������ �ð� : ");
	show();
	
	printf("��� �ð� �Է�(��) : ");
	scanf("%d", &addMin);
	
	
	for(; addMin>0; addMin--)
	{
		move();
	}
	
	printf("���� �ð� : ");
	show();
	
	scanf("%d");
	
	return 0;
}

void set(int h, int m)
{
	hour = h;
	min = m;	
	
	return;
}

void show(void)
{
	if(hour<10)	printf("0");
	printf("%d:%d(%s)\n", (hour%12), min, (hour < 12) ? "AM" : "PM");
	
	return;
}

void move(void)
{
	min++;
	if(min>=60)
	{
		hour++;
		min = 0;
		if(hour>=24)
		{
			hour = 0;
		}
	 } 
	 
	 return;
}




/*
���� 2 �ð� ���α׷�  
 - ���ʷ� ������ �ð����� ���� �ð��� �帥 �� ����ð��� ����ϴ� ���α׷��� �ۼ��մϴ�. ���� �ð� ������ 24�ð� ������ �Է��ϸ� ����� ���� AM, PM�� ����Ͽ� 12�ð� ������ ����մϴ�.
 ������ ���õ� �Լ��� �����ϰ� ���� ����� �����Ͽ� �ۼ��մϴ�. 
*/ 
