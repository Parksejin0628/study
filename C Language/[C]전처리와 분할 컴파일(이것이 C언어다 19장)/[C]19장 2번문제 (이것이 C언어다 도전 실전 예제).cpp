#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FEMALE
#define LEVEL 5 


int main(void)
{
	double sum;
	#if LEVEL == 3
		double height[3];
	
		printf("단계별 키 입력(3단계) : ");
		scanf("%lf %lf %lf", height, height+1, height+2);
		#ifdef MALE
			double standard[3] = {49.4, 74.8, 85.0};
		#endif
	
		#ifdef FEMALE
			double standard[3] = {50.1, 76.0, 86.2};
		#endif
		printf("단계별 표준키와 차이 : ");
		for(int i=0; i<3; i++)
		{
			printf("%.1lf ", height[i] - standard[i]);
			sum += height[i] - standard[i];
		}
		printf("\n");
		printf("차이 평균 : %.1lf", sum / 3);
	
	#elif LEVEL == 5
		double height[5];
	
		printf("단계별 키 입력(5단계) : ");
		scanf("%lf %lf %lf %lf %lf", height, height+1, height+2, height+3, height+4);
	
		#ifdef MALE
			double standard[5] = {49.4, 66.3, 74.8, 79.9, 85.0};
		#endif
	
		#ifdef FEMALE
			double standard[5] = {50.1, 67.6, 76.0, 81.2, 86.2};
		#endif
		printf("단계별 표준키와 차이 : ");
		for(int i=0; i<5; i++)
		{
			printf("%.1lf ", height[i] - standard[i]);
			sum += height[i] - standard[i];
		}
		printf("\n");
		printf("차이 평균 : %.1lf", sum / 5);
	#endif
	
	
	
	scanf("%d");
	
	return 0;
}


/*
도전 2 신체 발육 검사 프로그램
 - 24개월까지 아이의 키를 단계별로 입력하여 표준키와 비교한 후 단계별 키의 차이와 차이의 평균을 출력합니다. 
  표준키는 다음 기준을 사용하고 전처리 단계에서 매크로명의 정의에 따라 선택되도록 조건부 컴파일로 작성합니다. 
  > 남자 아이 3단계 발육 표준 키 : 49.4 74.8 85.0
  > 남자 아이 5단계 발육 표준 키 : 49.4 66.3 74.8 79.9 85.0
  > 여자 아이 3단계 발육 표준 키 : 50.1 76.0 86.2 
  > 여자 아이 5단계 발육 표준 키 : 50.1 67.6 76.0 81.2 86.2 
*/ 
