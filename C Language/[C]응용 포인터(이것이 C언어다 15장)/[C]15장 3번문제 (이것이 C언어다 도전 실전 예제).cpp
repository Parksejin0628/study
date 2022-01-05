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
	
	printf("������ ���...\n");
	for(i=0; i<4; i++)
	{
		if(rank[i] == branch[0])	printf("������");
		else if(rank[i] == branch[1])	printf("������");
		else if(rank[i] == branch[2])	printf("����");
		else if(rank[i] == branch[3])	printf("�븲��"); 
		for(j=0; j<7; j++)
		{
			printf("%5d", rank[i][j]);
		}
		printf("\n");
	}
	
	printf("\n������ ���...\n");
	for(i=0; i<4; i++)
	{
		if(i==0)	printf("������");
		else if(i==1)	printf("������");
		else if(i==2)	printf("����");
		else if(i==3)	printf("�븲��"); 
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
���� 3 ������ ���� ���� ���α׷�  
 - �Ƕ� �н��� ������ ��ݱ� ������ �������� �����Ͽ� ����մϴ�. �� ������ ��ݱ� ��� ������ ���� �Ŀ� ������ ���� ���� �������� ���ʷ� ����մϴ�.
   �̾ ������ ���� ��Ȳ�� �� �� �� ����մϴ�. ������ ��ݱ� ������ ������ ���� �ʱ�ȭ�ϸ� ��� ������ �Ҽ��� ���� ���� �ݿø��մϴ�. 
*/ 
