#include<stdio.h>

void print_graph(int *ps, int size);

int main(void)
{
	int score[5] = {72, 88, 95, 64, 100};
	
	print_graph(score, sizeof(score) / sizeof(int));
	scanf("%d");
	
	return 0;
}

void print_graph(int *ps, int size)
{
	for(int i=0; i<size; i++)
	{
		printf("(%3d) ", ps[i]);
		for(int j=0; j<ps[i] / 5; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

/*
���� 1 �� �׷��� ��� ���α׷�
 - �ټ� ������ ������ ����� �迭�� ���� ���� �� �׷����� �׸��ϴ�. ���� 5���� �ϳ��� ����ϸ� ���� ������ �����ϴ�. 
 �迭�� main�Լ��� �����ϰ� �׷����� �׸��� �Լ��� ������ �ۼ��մϴ�.
*/ 
