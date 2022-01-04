#include<stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;
	int num[5][6] = {0};
	int now = 0;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<6; j++)
		{
			if(i==4)
			{
				num[i][j] = num[0][j] + num[1][j] + num[2][j] + num[3][j];
				continue;
			}
			if(j==5)
			{
				num[i][j] = num[i][0] + num[i][1] + num[i][2] + num[i][3] + num[i][4];
				break;
			}
			now++;
			num[i][j] = now;
		}
	} 
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<6; j++)
		{
			printf("%5d", num[i][j]);
		}
		printf("\n");
	}
	
	scanf("%d");
	
	return 0;
}


/*
도전 1 가로 세로의 합 구하기  
 - 5행 6열의 2차원 배열을 선언하고 4행 5열 부분은 1부터 20까지 초기화합니다. 
   초기화된 배열에서 마지막 열의 요소에는 각 행의 합을 저장하고 마지막 행의 요소에는 각 열의 합을 저장한 후 전체 배열의 값을 출력합니다. 
*/ 
