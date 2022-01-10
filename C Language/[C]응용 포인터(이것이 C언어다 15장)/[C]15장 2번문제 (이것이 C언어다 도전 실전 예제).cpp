#include<stdio.h>
#include<string.h>

void swap(char *type, void *pa, void *pb);

int main(void)
{
	int age1;
	int age2;
	double height1;
	double height2;
	
	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &age1, &height1);
	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &age2, &height2);
	
	swap("int", (int*)&age1, (int*)&age2);
	swap("double", (double*)&height1, (double*)&height2);
	
	printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", age1, height1);
	printf("두 번재 사람의 나이와 키 : %d, %.1lf\n", age2, height2);
	
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
도전 2 프로필 교환 프로그램
 - 두 명의 나이와 키를 입력한 후에 바꾸어 출력합니다. 단, 나이와 키를 바꾸는 함수는 int형과 double형을 모두 교환할 수 있도록 하나의 함수로 구현합니다.
*/ 
