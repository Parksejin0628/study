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
	
	printf("��� �Է� : ");
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
���� 2 �Ҽ�(prime number) ��� ���α׷�
 - 1���� �Է��� �������� ��� �Ҽ��� ����մϴ�. �Ҽ��� 1�� �ڽ� �̿ܿ��� � ���ε� ������ �������� �����Ƿ� 1�� �ڽ��� �Ҽ����� �����մϴ�.
  ����, 2���� �Է��� �� -1 ������ ��� �Ҽ��� ����ϸ� �Ҽ��� �ƴ� ���� X�� ����մϴ�. 
*/ 
