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
���� 1 ���� ������ �� ���ϱ�  
 - 5�� 6���� 2���� �迭�� �����ϰ� 4�� 5�� �κ��� 1���� 20���� �ʱ�ȭ�մϴ�. 
   �ʱ�ȭ�� �迭���� ������ ���� ��ҿ��� �� ���� ���� �����ϰ� ������ ���� ��ҿ��� �� ���� ���� ������ �� ��ü �迭�� ���� ����մϴ�. 
*/ 
