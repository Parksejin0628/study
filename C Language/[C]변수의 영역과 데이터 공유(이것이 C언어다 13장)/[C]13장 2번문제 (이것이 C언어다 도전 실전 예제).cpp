#include<stdio.h>

void set(int h, int m);		// 최초 시간과 분을 설정하는 함수 
void show(void);			// 시간과 분을 화면에 출력하는 함수 
void move(void); 			// 한 번 호출될 때마다 1분씩 시간 증가  

int hour = 0;
int min = 0; 

int main(void)
{
	int addMin = 0;
	int defaultHour = 0;
	int defaultMin = 0;
	
	printf("최초 시간과 분 입력(24시간) : ");
	scanf("%d %d", &defaultHour, &defaultMin);
	
	set(defaultHour, defaultMin); 
	
	printf("설정된 시간 : ");
	show();
	
	printf("경과 시간 입력(분) : ");
	scanf("%d", &addMin);
	
	
	for(; addMin>0; addMin--)
	{
		move();
	}
	
	printf("현재 시간 : ");
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
도전 2 시계 프로그램  
 - 최초로 설정한 시간에서 일정 시간이 흐른 후 현재시간을 출력하는 프로그램을 작성합니다. 최초 시간 설정은 24시간 단위로 입력하며 출력할 때는 AM, PM을 사용하여 12시간 단위로 출력합니다.
 다음에 제시된 함수를 구현하고 실행 결과를 참고하여 작성합니다. 
*/ 
