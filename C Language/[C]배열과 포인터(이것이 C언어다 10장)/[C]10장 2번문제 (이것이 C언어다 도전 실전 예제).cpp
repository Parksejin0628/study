#include<stdio.h>

int check_same(int *lotto_nums, int *my_nums);

int main(void)
{
	int lotto_nums[6] = {4, 10, 25, 30, 41, 45};
	int my_nums[6] = {1, 4, 7, 22, 41, 43};
	
	printf("일치하는 번호의 개수 : %d\n",check_same(lotto_nums, my_nums));
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
[도전 2 : 로또 번호 확인 프로그램]
 - 구입한 로또 복권의 번호와 추첨한 로또 복권의 번호를 확인하여 일치하는 번호의 개수를 출력합니다.
 두 배열은 main 함수에 선언하고 두 배열에서 일치하는 번호를 찾아 그 개수를 반환하는 함수를 만들어 main 함수에서 사용합니다. 
*/
