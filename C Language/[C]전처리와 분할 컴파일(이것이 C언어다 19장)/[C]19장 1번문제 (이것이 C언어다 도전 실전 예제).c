#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INPUT(a, b, c) scanf("%d %c %d", &a, &b, &c)
#define ADDITION(A, B) ((A) + (B))
#define SUBTRACTION(A, B) ((A) - (B))
#define MULTIPLICATION(A, B) ((A) * (B))
#define DIVISION(A, B) ((A) / (B))

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	char cal = '\0';
	int result = 0;
	while(1)
	{
		printf("수식 입력(종료 Ctrl + Z) : ");
		INPUT(num1, cal, num2);
		if(cal == '+')
		{
			result = ADDITION(num1, num2);
		}
		else if(cal == '-')
		{
			result = SUBTRACTION(num1, num2);
		}
		else if(cal == '*')
		{
			result = MULTIPLICATION(num1, num2);
		}
		else if(cal == '/')
		{
			result = DIVISION(num1, num2);
		}
		else
		{
			break;
		}
		printf("%d %c %d = %d\n", num1, cal, num2, result);
	}
	
	scanf("%d");
	
	return 0;
}


/*
도전 1 사칙연산 계산기 프로그램
 - 사칙연산 수식을 입력하면 그 결과를 출력하는 프로그램을 작성합니다. 단, 수식을 입력하는 함수와 사칙연산 함수를 매크로 함수로 작성합니다. 
*/ 
