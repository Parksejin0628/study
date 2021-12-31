#include<stdio.h>

void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b); 

int a, b;

int main(void)
{
	input_data(&a, &b);
	swap_data();
	print_data(a, b);
	
	scanf("%d");
	
	return 0;
}

void input_data(int *pa, int *pb)
{
	printf("두 정수 입력 : ");
	scanf("%d %d", pa, pb);
	
	return;
}

void swap_data()
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
	
	return;
}

void print_data(int a, int b)
{
	printf("두 정수 출력 : %d, %d", a, b);
	
	return;
}


/*
도전 1 전역 변수 교환 프로그램  
 - 두 개의 전역 변수에 값을 입력하고 교환한 후에 출력하는 프로그램을 작성합니다. 입력, 교환, 출력 작업은 다음에 제시된 함수 원형을 지켜 작성합니다. 
*/ 
