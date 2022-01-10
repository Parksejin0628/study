#include<stdio.h>
#include<string.h>

void swap(char *type, void *pa, void *pb);

int main(void)
{
	int age1;
	int age2;
	double height1;
	double height2;
	
	printf("ù ��° ����� ���̿� Ű �Է� : ");
	scanf("%d %lf", &age1, &height1);
	printf("�� ��° ����� ���̿� Ű �Է� : ");
	scanf("%d %lf", &age2, &height2);
	
	swap("int", (int*)&age1, (int*)&age2);
	swap("double", (double*)&height1, (double*)&height2);
	
	printf("ù ��° ����� ���̿� Ű : %d, %.1lf\n", age1, height1);
	printf("�� ���� ����� ���̿� Ű : %d, %.1lf\n", age2, height2);
	
	scanf("%d");
	
	return 0;
}

void swap(char *type, void *pa, void *pb)
{
	if(strcmp(type, "int") == 0)
	{
		int temp;
		temp = *(int*)pa;
		*(int*)pa = *(int*)pb;
		*(int*)pb = temp;
	}
	else
	{
		double temp;
		temp = *(double*)pa;
		*(double*)pa = *(double*)pb;
		*(double*)pb = temp;
	}

	
	return;
}


/*
���� 2 ������ ��ȯ ���α׷�
 - �� ���� ���̿� Ű�� �Է��� �Ŀ� �ٲپ� ����մϴ�. ��, ���̿� Ű�� �ٲٴ� �Լ��� int���� double���� ��� ��ȯ�� �� �ֵ��� �ϳ��� �Լ��� �����մϴ�.
*/ 
