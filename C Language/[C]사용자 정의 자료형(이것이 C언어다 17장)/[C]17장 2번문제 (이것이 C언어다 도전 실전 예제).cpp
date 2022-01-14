#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int i = 0;
	int j = 0;
	int cnt = 0;
	int no = 0;
	int index = 0;
	int *num;
	
	printf("양수 입력 : ");
	scanf("%d", &cnt);
	num = (int*)malloc(cnt * sizeof(int));
	for(i=2; i<cnt; i++)
	{
		if(i%5 == 2)	printf("\n");
		for(j=0; j<index; j++)
		{
			if(i%num[j] == 0)
			{
				printf("   X");
				no = 1;
				break;
			}
		}
		if(no == 1)
		{
			no=0;
			continue;
		}
		printf("%4d", i);
		num[index++] = i;
	}
	
	scanf("%d");
	
	return 0;
}


/*
도전 2 소수(prime number) 계산 프로그램
 - 1부터 입력한 수까지의 모든 소수를 출력합니다. 소수는 1과 자신 이외에는 어떤 수로도 나누어 떨어지지 않으므로 1과 자신은 소수에서 제외합니다.
  따라서, 2부터 입력한 수 -1 까지의 모든 소수를 출력하며 소수가 아닌 수는 X를 출력합니다. 
*/ 
