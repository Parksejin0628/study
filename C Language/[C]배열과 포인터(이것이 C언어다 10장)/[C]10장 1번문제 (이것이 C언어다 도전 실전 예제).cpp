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
도전 1 별 그래프 출력 프로그램
 - 다섯 과목의 점수가 저장된 배열의 값에 따라 별 그래프를 그립니다. 별은 5점당 하나씩 출력하며 남는 점수는 버립니다. 
 배열은 main함수에 선언하고 그래프를 그리는 함수는 별도로 작성합니다.
*/ 
