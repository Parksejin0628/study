#include<stdio.h>

int check_same(int *lotto_nums, int *my_nums);

int main(void)
{
	int lotto_nums[6] = {4, 10, 25, 30, 41, 45};
	int my_nums[6] = {1, 4, 7, 22, 41, 43};
	
	printf("��ġ�ϴ� ��ȣ�� ���� : %d\n",check_same(lotto_nums, my_nums));
	scanf("%d");
	
	return 0;
}

int check_same(int *lotto_nums, int *my_nums)
{
	int same = 0;
	int checkingNum = 0;
	for(int i=0; i<6; i++)
	{
		checkingNum = my_nums[i];
		for(int j=0; j<6; j++)
		{
			if(checkingNum == lotto_nums[j])
			{
				same++;
				break;
			}
		}
	}
	
	return same;
}
/*
[���� 2 : �ζ� ��ȣ Ȯ�� ���α׷�]
 - ������ �ζ� ������ ��ȣ�� ��÷�� �ζ� ������ ��ȣ�� Ȯ���Ͽ� ��ġ�ϴ� ��ȣ�� ������ ����մϴ�.
 �� �迭�� main �Լ��� �����ϰ� �� �迭���� ��ġ�ϴ� ��ȣ�� ã�� �� ������ ��ȯ�ϴ� �Լ��� ����� main �Լ����� ����մϴ�. 
*/
