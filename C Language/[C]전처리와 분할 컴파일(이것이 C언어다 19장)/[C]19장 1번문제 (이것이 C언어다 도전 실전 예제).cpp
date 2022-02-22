#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INPUT scanf("%d %c %d")
#define CALCULATE(A, B, C) printf(#(A##B##C) "= %d", A##B##C)

int main(void)
{
	
	while(1)
	{
		INPUT
		
	}
	
	scanf("%d");
	
	return 0;
}


/*
도전 1 사칙연산 계산기 프로그램
 - 사칙연산 수식을 입력하면 그 결과를 출력하는 프로그램을 작성합니다. 단, 수식을 입력하는 함수와 사칙연산 함수를 매크로 함수로 작성합니다. 
*/ 
