#include<stdio.h>


int main(void)
{
	int branch[4][7] = { {70, 45, 100, 92, 150, 81}, {88, 92, 77, 30, 52, 55}, {50, 90, 88, 75, 77, 49}, {120, 92, 80, 150, 130, 105} };
	int *rank[4] = {branch[0], branch[1], branch[2], branch[3]};
	int *temp;
	int i = 0;
	int j = 0;
	
	for(i=0; i<7; i++)
	{
		for(j=0; j<4; j++)
		{
			if(i==6)
			{
				branch[j][6] = (int)(branch[j][6] / 6.0 + 0.5);
				continue;
			}
			branch[j][6] += branch[j][i];
		}
	}
	for(i=0; i<4; i++)
	{
		for(j=i+1; j<4; j++)
		{
			if(rank[i][6] < rank[j][6])
			{
				temp = rank[i];
				rank[i] = rank[j];
				rank[j] = temp;
			}
		}
	}
	
	printf("실적별 출력...\n");
	for(i=0; i<4; i++)
	{
		if(rank[i] == branch[0])	printf("관악점");
		else if(rank[i] == branch[1])	printf("강남점");
		else if(rank[i] == branch[2])	printf("명동점");
		else if(rank[i] == branch[3])	printf("대림점"); 
		for(j=0; j<7; j++)
		{
			printf("%5d", rank[i][j]);
		}
		printf("\n");
	}
	
	printf("\n지점별 출력...\n");
	for(i=0; i<4; i++)
	{
		if(i==0)	printf("관악점");
		else if(i==1)	printf("강남점");
		else if(i==2)	printf("명동점");
		else if(i==3)	printf("대림점"); 
		for(j=0; j<7; j++)
		{
			printf("%5d", branch[i][j]);
		}
		printf("\n");
	}
	
	
	
	scanf("%d");
	
	return 0;
}


/*
도전 3 지점별 실적 관리 프로그램  
 - 또또 분식의 지점별 상반기 매출을 순위별로 정렬하여 출력합니다. 각 지점별 상반기 평균 매출을 구한 후에 매출이 가장 좋은 지점부터 차례로 출력합니다.
   이어서 원래의 매출 현황을 한 번 더 출력합니다. 지점별 상반기 매출은 다음과 같이 초기화하며 평균 매출의 소수점 이하 값은 반올림합니다. 
*/ 
