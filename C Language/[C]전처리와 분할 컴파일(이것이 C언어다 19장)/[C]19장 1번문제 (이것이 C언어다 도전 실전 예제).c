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
		printf("���� �Է�(���� Ctrl + Z) : ");
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
���� 1 ��Ģ���� ���� ���α׷�
 - ��Ģ���� ������ �Է��ϸ� �� ����� ����ϴ� ���α׷��� �ۼ��մϴ�. ��, ������ �Է��ϴ� �Լ��� ��Ģ���� �Լ��� ��ũ�� �Լ��� �ۼ��մϴ�. 
*/ 
