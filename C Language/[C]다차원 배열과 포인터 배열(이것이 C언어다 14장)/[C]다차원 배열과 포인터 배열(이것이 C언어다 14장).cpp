#include<stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	printf("(1)\n");
	int num1[3][4] = { {1, 2, 3, 4}, {11, 12, 13, 14}, {21, 22, 23, 24} };
	int num2[3][4] = { {1}, {2, 3}, {4, 5, 6}};
	int num3[3][4] = { {1, 2, 3, 4} };
	int num4[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int num5[3][4] = {0};
	
	printf("첫 번째 배열 : ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d ", num1[i][j]);
		}
		printf("/ ");
	}
	printf("\n");
	printf("두 번째 배열 : ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d ", num2[i][j]);
		}
		printf("/ ");
	}
	printf("\n");
	printf("세 번째 배열 : ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d ", num3[i][j]);
		}
		printf("/ ");
	}
	printf("\n");
	printf("네 번째 배열 : ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d ", num4[i][j]);
		}
		printf("/ ");
	}
	printf("\n");
	printf("다섯 번째 배열 : ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d ", num5[i][j]);
		}
		printf("/ ");
	}
	printf("\n");
	// 2차원 배열 선언 및 초기화 방법 
	printf("\n(2)\n");
	char name[][20] = {"apple", "banana", "orange", "melon"};
	for(i=0; i<4; i++)
	{
		printf("%d번 문자열 : %s\n", i, name[i]);
	}
	// 2차원 char 배열 선언 및 초기화 방법 / 행 첨자 생략 / 부분배열을 통한 문자열 출력 
	printf("\n(3)\n");
	int superNum[2][3][4] = { { {111, 112, 113, 114}, {121, 122, 123, 124}, {131, 132, 133, 134} }, { {211, 212, 213, 214}, {221, 222, 223, 224}, {231, 232, 233, 234} } };
	printf("3차원 배열 출력\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<4; k++)
			{
				printf("%d ", superNum[i][j][k]);
			}
			printf("/ ");
		}
		printf("\n");
	} 
	//3차원 배열 선언 및 초기화 
	printf("\n(4)\n");
	char *pname[3] = {"apple", "banana", "orange"};
	printf("첫 번째 문자열 : %s\n", pname[0]);
	printf("두 번째 문자열 : %s\n", pname[1]);
	printf("세 번째 문자열 : %s\n", pname[2]);
	//포인터 배열 선언 및 2차원 char배열처럼 사용하는 char 포인터 배열 
	int ary1[4] = {1, 2, 3, 4};
	int ary2[4] = {5, 6, 7, 8};
	int ary3[4] = {9, 10, 11, 12};
	int *pary[3] = {ary1, ary2, ary3};
	printf("\n(5)\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d ", pary[i][j]);
		}
		printf("/ ");
	}
	//포인터 배열 요소에 배열명을 넣음으로써 1차원 포인터배열을 2차원 포인터배열처럼 활용 
	
	scanf("%d");
	return 0;
}
/*
[14장 다차원 배열과 포인터 배열]
<14.1 2차원 배열>
14.1.1 2차원 배열 선언과 요소 사용
	- 2차원 배열은 1차원 배열을 요소로 갖는 배열이다. 
	- 2차원 배열은 행렬의 구조와 같다.
 	- 2차원 배열의 선언 방법은 다음과 같다.
  	 	> 자료형 배열이름[행의 수][열의 수]
		> 또한 배열이름[행][열]로 해당 요소에 접근이 가능하다.
	- 1차원 배열과 마찬가지로 2차원 배열도 첨자가 0부터 시작하여 최댓값은 '행의 수 -1 / 열의 수 -1' 이다. 
14.1.2 2차원 배열 초기화
 	- 2차원 배열 초기화는 중괄호 쌍 두개를 사용하여 행 부분도 표시한다.
 		ex) int num[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
		>즉, 1차원 배열 초기화 때와 동일하게 중괄호 안에 요소를 나열하여 초기화 하나 요소가 1차원 배열이므로 이중 중괄호가 사용되는 것이다.
	- 1차원 배열 때와 마찬가지로 중간에 생략한다면 나머지 값은 전부 0으로 처리된다.
 		ex) int num[3][4] = { {1, 2, 3, 4} }일 경우 실제로는 { {1, 2, 3, 4}, {0, 0, 0, 0}, {0, 0, 0, 0} }으로 초기화된다.
		> {0}으로 초기화할 경우 모든 요소가 0으로 초기화된다. 
 	- 1차원 배열이 요소이므로 이중 중괄호 안에 요소들도 생략하면 그 요소배열의 나머지 값들이 0으로 처리된다.
 		ex) int num[3][4] = { {1}, {2, 3}, {3, 4, 5} }일 경우 실제로는 { {1, 0, 0, 0}, {2, 3, 0, 0}, {3, 4, 5, 0} }으로 초기화된다. 
	- 이중 중괄호를 사용하지 않고 초기화될 경우 행 단위로 차례대로 초기화된다.
	 	ex) int num[3][4] = { 1, 2, 3, 4, 5, 6 }일 경우 실제로는 { {1, 2, 3, 4}, {5, 6, 0, 0}, {0, 0, 0, 0} }으로 초기화된다.
	- 2차원 배열은 1차원 배열을 요소로 하는 배열이다.
 		> 즉, num[3][4]의 경우 num[0], num[1], num[2]라는 부분배열을 가진다. (각각의 요소는 4개의 요소를 가진 1차원 배열이라 볼 수 있다.)
14.1.3 2차원 char 배열
	- 2차원의 char 배열은 여러 개의 문자열을 처리할 때 사용한다.
 	- 2차원 배열의 부분배열명이 각 행의 배열명 기능 즉, 하나의 문자열 기능을 한다.
 		ex) name[3][10]의 요소가 apple, banana, orange인 경우 name[0] == "apple" / name[1] == "banana" / name[2] == "orange"인 셈이다. 
14.1.4 2차원 char 배열 초기화
	- 2차원 char 배열을 초기화 하는 방법은 크게 2가지이다.
	- 첫 번쨰 방법은 다른 2차원 배열처럼 배열요소를 하나씩 초기화하는 방법이다.
		ex) name[3][10] = { {'a', 'p', 'p', 'l', 'e', '\0'}, {'b', 'a', ... 생략 }
	- 두 번재 방법은 각 행 단위를 문자열로 초기화하는 방법이다.
		ex) name[3][10] = { "apple", "banana", "orange"}
	- 두 번째 방법으로 초기화 할 때 행 단위를 생략하면 초기화되는 문자열 상수의 개수가 행의 수가 된다.
		ex) name[][10] = {"apple", "banana", "orange", "melon"}의 경우 행의 수가 4가 된다.
14.1.5 3차원 배열
	- 3차원 배열은 2차원 배열을 요소로 가지는 배열이다.
	- 1차원 -> 2차원으로 넘어갈 때와 특징이 매우 유사하다.
		> 3개의 첨자를 사용한다.
		> 초기화 방식도 유사하다.
		> 부분배열은 2차원 배열이 된다.
<14.2 포인터 배열> 
14.2.1 포인터 배열 선언과 사용
	- 포인터도 일반 변수처럼 메모리에 저장 공간을 갖는 변수로 같은 포인터가 많이 필요한 경우 배열을 사용하는 것이 좋다.
	- 포인터 배열은 같은 자료형의 포인터를 모아 만든 배열이다. 
	- 일반 배열 선언과 포인터 배열의 선언 방식은 같으나 포인터형이므로 배열명 앞에 *를 붙인다.
	- char 포인터 배열은 2차원 char 배열과 초기화 방법이 같다.
		> 2차원 char 배열 초기화 : char name[3][10] = {"apple", "banana", "orange"}; - 배열 요소에 문자열 저장
		> char 포인터 배열 초기화 : char *name[3] = {"apple", "banana", "orange"}; - 배열 요소에 각 문자열 시작 주소 저장
14.2.2 2차원 배열처럼 활용하는 포인터 배열
	- 포인터 배열은 첨자를 하나 사용하는 1차원 배열이지만 포인태 배열의 요소들이 1차원 배열을 연결하면 2차원 배열처럼 쓸 수 있다. 
		ex) 1차원 배열인 ary1, ary2, ary3가 있다고 가정하면 int *pary[3] = {ary1, ary2, ary3}로 초기화 함으로써 pary[0][2], pary[2][1]와 같이 2차원 배열처럼 사용할 수 있다.
		> 각 포인터의 요소가 1차원 배열의 시작 배열을 가리키므로 가능한 일이다. 
	- 이 경우 포인터 배열 요소들이 부분배열명의 기능을 하게된다.
	- 예를 들어 pary[2][2]는 *(pary[2] + 2)의 형태와 같다. (포인터 연산) 

*/ 
