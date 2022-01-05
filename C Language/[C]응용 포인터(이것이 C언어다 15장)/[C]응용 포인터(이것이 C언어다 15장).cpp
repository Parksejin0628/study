#include<stdio.h>

void changePointer(char **pointer1, char **pointer2);
void printWords(char **words);

int main(void)
{
	int a = 27;
	int *pa = &a;
	int **ppa = &pa; 
	char *word1 = "apple";
	char *word2 = "banana";
	char *words[4] = {"tiger", "lion", "rabbit", "turtle"};
	
	printf("(1)\n");
	printf("      %30s%10s\n", "주소 값", "값");
	printf("a   : %30u%10d\n\n", &a, a);
	printf("      %20s%10s%10s\n", "주소 값", "값", "*연산 값");
	printf("pa  : %20u%10u%10d\n\n", &pa, pa, *pa);
	printf("      %10s%10s%10s%10s\n", "주소 값", "값", "*연산 값", "**연산값");
	printf("ppa : %10u%10u%10u%10d\n\n", &ppa, ppa, *ppa, **ppa);
	//2중 포인터 선언 및 사용방법 해당 실행결과를 통해 &, *, **, 변수 값의 차이와 해당 연산이 무엇을 가리키는지 파악할 수 있다.
	printf("\n(2)\n");
	printf("함수 호출 전 word1 : %s, word2 : %s\n", word1, word2);
	changePointer(&word1, &word2);
	printf("함수 호출 후 word1 : %s, word2 : %s\n", word1, word2);
	//2중 포인터는 포인터의 값을 바꾸는 함수의 매개변수로 사용한다.
	printf("\n(3)\n");
	printWords(words);
	//2중 포인터는 포인터배열을 사용하는 함수의 매개변수로 사용한다. 
	
	scanf("%d");
	return 0;
}

void changePointer(char **pointer1, char **pointer2)
{
	char *temp;
	
	temp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = temp;
	
	return;
}

void printWords(char **words)
{
	int i = 0;
	
	for(i=0; i<4; i++)
	{
		printf("%s ",words[i]);
	}
	printf("\n");
	
	return;
}

/*
[15장 응용 포인터]
<15.1 2중 포인터와 배열 포인터>
15.1.1 2중 포인터 개념
	- 포인터도 메모리에 저장 공간을 갖은 하나의 변수이므로 주소를 가지고 있으며 주소 연산으로 주소를 구할 수 있다.
		> 이 주소를 저장하는 포인터가 2중 포인터이다.
	- 2중 포인터는 변수명에 **을 붙여 선언한다.
		> 첫 번째 *은 가리키는 변수를 의미하며 포인터변수를 가리킨다는 뜻이다.
		> 두 번째 *은 해당 변수가 포인터로써 사용될 것이라는 의미이다.
			ex) int* *ppi 에서 int*(int*인 포인터를 가리킬 예정이다.) *ppi(포인터 변수이다.)
	- 변수 선언을 제외하고 *연산을 통해 해당 포인터가 가리키는 포인터가 가리키고 있는 변수의 주소를, **연산을 통해 해당 포인터가 가리키는 포인터가 가리키고 있는 변수의 값을 알 수 있다.
		ex) 변수 a, 변수 a를 가리키는 포인터 *pa, 포인터 pa를 가리키는 **ppa가 있다고 가정해보자
			ppa = &pa이다. (pa의 주소를 ppa가 가지므로 당연하다.)
			*ppa = pa = &a이다. (* 연산은 가리키고 있는 변수의 값을 구할 수 있다. 따라서, 가리키는 변수인 포인터 pa가 a의 주소를 가진다.
			**ppa = *pa = a이다. (* 연산을 통해 pa의 값을 구한다. pa또한 주소의 값을 가지고 있으므로 * 연산을 통해 pa가 가리키는 a의 값이 나온다.)
		> 이와 같이 2중 포인터에 값을 대입할 때에는 (이중포인터) = &(포인터)로 대입한다.
	- 2중 포인터는 저장할 주소가 어떤 자료형을 가리키는 포인터인지 파악하고 자료형을 지정한다.
		ex) 가리키는 포인터가 int*인 경우 int **(변수명)으로 선언하고 가리키는 포인터가 char을 가리키는 char*인 경우 char **(변수명)으로 저장한다.
	- 변수나 포인터는 (포인터도 변수이다.) 주소 연산자를 사용하여 주소를 구할 수 있지만, 주소 상수에는 주소 연산자를 쓸 수 없다.
		> 주소 상수를 저장하는 주소가 있을리가 없다. 상수인데
	- 2중 포인터는 3중 포인터에 저장할 수 있다.
		> 선언은 배열명앞에 ***을 사용하고 상황에 따라 *연산자의 개수를 조절하여 원하는 값을 파악할 수 있다.
		> 4중 이상의 포인터도 사용할 수 있으나 가독성이 떨어지므로 되도록 사용하지 않는다.
		> 2중 이상의 포인터를 다중 포인터라고한다. 
15.1.2 2중 포인터 활용 예1
	- 2중 포인터는 포인터의 값을 바꾸는 함수의 매개변수에 사용한다.
15.1.3 2중 포인터 활용 예2
	- 2중 포인터는 포인터 배열을 매개변수로 받는 함수에도 사용한다. 
15.1.4 배열 요소의 주소와 배열의 주소
	- 배열에 주소 연산자를 사용하면 배열을 가리키는 주소가 된다. (배열명은 첫 번째 요소의 주소값)
	- 배열의 주소도 첫 번째 요소의 주소와 같지만 정수 연산을 할 때 자료형의 크기가 아닌 배열 전체의 크기를 곱해서 연산한다.
		ex)int num[5]의 경우 &num == num 이지만 num + 1 != &num + 1 (num의 주소가 20이라고 치면 num + 1 = 24지만 &num + 1 = 40이다.)
	- 배열은 전체가 하나의 논리적인 변수이다. 즉, (자료형의 크기 * 배열의 갯수)크기를 가진 하나의 변수라고 볼 수 있지만, 논리적인 변수이므로 일반 연산같이 대입연산은 불가능하다. 
	- 1차원 배열에서는 정수 연산을 해도 할당된 메모리 영역을 벗어나므로 거의 사용하지 않는다.
		> 따라서 주로 2차원 이상의 배열에서 사용한다. 
			  

*/ 
