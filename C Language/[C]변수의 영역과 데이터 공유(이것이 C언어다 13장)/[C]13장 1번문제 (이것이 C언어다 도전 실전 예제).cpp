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
	printf("�� ���� �Է� : ");
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
	printf("�� ���� ��� : %d, %d", a, b);
	
	return;
}


/*
���� 1 ���� ���� ��ȯ ���α׷�  
 - �� ���� ���� ������ ���� �Է��ϰ� ��ȯ�� �Ŀ� ����ϴ� ���α׷��� �ۼ��մϴ�. �Է�, ��ȯ, ��� �۾��� ������ ���õ� �Լ� ������ ���� �ۼ��մϴ�. 
*/ 
