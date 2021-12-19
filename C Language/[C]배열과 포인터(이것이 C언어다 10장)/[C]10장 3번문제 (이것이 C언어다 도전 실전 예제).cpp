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
		printf("번호 입력 : ");
		scanf("%d", lotto_nums + i);
		for(int j=0; j<i; j++)
		{
			if(lotto_nums[i] == lotto_nums[j])
			{
				printf("같은 번호가 있습니다!\n");
				i--;
				break;
			}
		}
	}
	
	return;
}
void print_nums(int *lotto_nums)
{
	printf("로또 번호 : ");
	for(int i=0; i<6; i++)
	{
		printf("%d ", lotto_nums[i]);
	}
	printf("\n");
}

/*
[도전 3 : 로또 번호 생성 프로그램]
 - 1부터 45 중에 6개의 서로 다른 수를 배열에 입력하고 출력합니다. 
 입력한 수가 이미 저장된 수와 같으면 오류 메시지를 출력하고 다시 입력합니다. 
*/
