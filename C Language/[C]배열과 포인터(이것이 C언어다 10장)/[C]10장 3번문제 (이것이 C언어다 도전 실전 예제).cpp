#include<stdio.h>

void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);

int main(void)
{
	int lotto_nums[6];
	
	input_nums(lotto_nums);
	print_nums(lotto_nums);
	scanf("%d");
	
	return 0;
}

void input_nums(int *lotto_nums)
{
	for(int i=0; i<6; i++)
	{
		printf("��ȣ �Է� : ");
		scanf("%d", lotto_nums + i);
		for(int j=0; j<i; j++)
		{
			if(lotto_nums[i] == lotto_nums[j])
			{
				printf("���� ��ȣ�� �ֽ��ϴ�!\n");
				i--;
				break;
			}
		}
	}
	
	return;
}
void print_nums(int *lotto_nums)
{
	printf("�ζ� ��ȣ : ");
	for(int i=0; i<6; i++)
	{
		printf("%d ", lotto_nums[i]);
	}
	printf("\n");
}

/*
[���� 3 : �ζ� ��ȣ ���� ���α׷�]
 - 1���� 45 �߿� 6���� ���� �ٸ� ���� �迭�� �Է��ϰ� ����մϴ�. 
 �Է��� ���� �̹� ����� ���� ������ ���� �޽����� ����ϰ� �ٽ� �Է��մϴ�. 
*/
