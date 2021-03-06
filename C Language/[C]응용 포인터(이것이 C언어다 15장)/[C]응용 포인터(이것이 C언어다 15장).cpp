#include<stdio.h>

void changePointer(char **pointer1, char **pointer2);
void printWords(char **words);
void initAry(int (*p)[5]);
void printSentence(char *sentence);

int main(void)
{
	int a = 27;
	int *pa = &a;
	int **ppa = &pa; 
	int i = 0;
	int j = 0;
	char *word1 = "apple";
	char *word2 = "banana";
	char *words[4] = {"tiger", "lion", "rabbit", "turtle"};
	int array[10] = {0};
	int ary[4][5] = {0};
	int pary[4];
	int (*arypointer)[5];
	
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
	printf("\n(4)\n");
	printf("array 배열명으로 구한 주소 : %u / array &연산으로 구한 주소 : &u\n", array, &array);
	printf("array 배열명으로 구한 주소 + 1 : %u / array &연산으로 구한 주소 + 1 : %u\n", array + 1, &array + 1);
	//배열명으로 구한 주소나 &연산을 통한 구한 주소나 모두 배열의 첫 번째 요소의 주소를 의미하지만, 배열명으로 구한 주소에 정수연산을 하면 자료형의 크기를 곱하고 &연산으로 구한 주소에 정수 연산을 하면 (자료형의 크기)*(배열의 크기)를 곱한다. 
	printf("\n(5)\n");
	arypointer = ary;
	initAry(arypointer);
	for(i=0; i<4; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("%2d ", arypointer[i][j]);
		}
		printf("\n");
	}
	// 배열 포인터를 통해 포인터를 (포인터 배열x) 2차원 배열처럼 사용할 수 있다. 
	printf("\n(6)\n");
	void (*fp)(char* sentence);
	fp = printSentence;
	fp("hello!\n");
	// 함수명은 함수 내용이 저장된 메모리의 시작 위치를 의미하고, 함수명을 함수 포인터에 저장하여 포인터를 함수처럼 쓸 수 있다.
	printf("\n(7)\n");
	void *vp;
	vp = pa;
	printf("va를 이용해 pa를 저장한 a값 : %d\n", *(int*)vp);
	// void 포인터는 어느 자료형이든 저장할 수 있지만, 사용할 때 형변환 연산자를 사용해야 한다. 
	
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

void initAry(int (*p)[5])
{
	int i = 0;
	int j = 0;
	for(i=0; i<4; i++)
	{
		for(j=0; j<5; j++)
		{
			p[i][j] = 5*i + j + 1;
		}
	}
	
	return;
}

void printSentence(char *sentence)
{
	printf("%s\n", sentence);
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
15.1.5 2차원 배열과 배열 포인터
	- 2차원 배열은 1차원 배열로 만든 배열이다. 따라서, 논리적으로 배열요소 하나하나가 1차원 배열이다.
		> 예를들어 ary[3][4]인 경우 첫 번째 요소인 ary[0]은 배열요소 4개를 가진 1차원 배열 ary[0][0] / ary[0][1] / ary[0][2] / ary[0][3] 을 모두 포함한다. 
		> 2차원 배열의 이름 즉, 첫 번째 요소의 주소는 1차원 배열의 주소이기 때문에 변수가 아닌 '배열'을 가리키는 배열 포인터에 저장한다. 
	- 배열 포인터는 배열을 가리키는 포인터를 의미한다. 
		> 기존에 배운 포인터는 pa = ary 로 배열을 카리키는 것이 아닌 "배열의 첫 번째 요소"를 가리킨 포인터이다. 
		> 15.1.4에서 배운 것 처럼 배열의 주소와 배열의 첫 번째 요소의 주소는 매우 비슷하나 차이가 있는 것을 확인했다. 배열포인터는 이 중 전자인 배열 포인터를 가리킨다.
	- 배열 포인터를 통해 2차원 배열의 이름을 저장할 수 있다.
		> 자료형 (*배열명)[부분배열의 크기]와 같은 형태로 2차원 배열을 가리키는 포인터를 저장할 수 있다. (괄호를 생략할 경우 그냥 배열 포인터가 된다.)
		> 즉, 해당 포인터는 자료형[부분배열의 크기]의 배열을 가리키는 포인터이며, 2차원은 1차원 배열을 배열요소로 가지는 1차원 배열이므로 포인터를 이용해 1차원 배열처럼 이용하듯 배열 포인터를 통해 2차원 배열처럼 사용할 수 있다. 
			ex) int ary[3][4] / int (*pa)[4] 가 있다고 가정할 때 pa = ary를 할 경우 pa를 ary처럼 사용할 수 있다.
	- 배열 포인터를 매개변수에 쓰면 함수 안에서 2차원 배열처럼 쓸 수 있다.
		>만약 포인터 배열을 이용한다면 그냥 사용할 수 없고 2중 포인터를 사용해야 할 것이다?
	- 2차원 배열에는 두 가지 의미의 배열 요소가 있다.
		> 개념적으로는 2차원 배열의 요소는 1차원 배열이다. 하지만, 실제로 데이터가 저장되는 공간은 1차원 배열의 요소이므로 물리적으로는 데이터를 저장하는 부분배열요소를 의미한다.
			ex) int ary[3][4]의 경우 논리적으로는 배열의 갯수가 3개이지만 물리적으로는 배열의 갯수가 12개이다. 
15.1.6 2차원 배열의 요소를 참조하는 원리
	- 배열 포인터를 쓰면 1차원의 물리적 공간을 2차원의 논리적 구조로 사용할 수 있다.
	- ary[3][4]에서 7번째 배열 공간인 ary[1][2]를 찾는 과정을 탐색해보자
		> 일단, ary[1]의 주소를 탐색하기 위하여 ary + 1 연산을 한다. (ary의 변수는 100이라고 가정하자.) 
		> 포인터에서 정수 연산은 정수에 자료형의 크기를 곱한다. 즉, ary의 첫 번째 요소의 자료형의 크기를 곱한다.
		> 그런데, 여기서 ary의 첫 번째 요소는 논리적으로 4개의 요소를 가지는 1차원 배열이므로 자료형의 크기는 4*4 (int크기 * 배열요소의 개수)인 16이다.
		> 따라서, 일단 116이라는 중간 결과가 나온다.
		> 그 다음은 ary[1][2]의 주소를 탐색해야 하는데 ary + 2를 할 경우 116 + 32 = 148이 된다. 이는 옳지 않다.
		> 따라서, ary + 2가 아닌 부분배열인 ary[1] + 2를 해야하고 ary[1]은 int자료형이므로 116 + 8이 된다. (2가 4*2로)
		> 따라서, 최종 결과는 124가 나오며 이는 ary + 4*6과 같다.
		> 즉, 1차원의 물리적 공간을 2차원의 논리적 구조로 사용한 것이다.
		> 때문에, 1차원 배열을 지정하는 배열 포인터를 사용하여 처음 ary + 1연산이 가능하게해야한다.

<15.2 함수 포인터와 void 포인터>
15.2.1 함수 포인터의 개념
	- 함수명은 함수의 정의가 있는 메모리의 시작 위치이다.
	- 따라서, 함수 명을 포인터에 저장하면 포인터를 함수처럼 사용할 수 있다. 이것이 함수 포인터이다.
	- 함수 포인터는 '해당함수의반환자료형 (*포인터변수명)(해당함수의 매개변수)'로 선언한다.
		ex) int sum(int, int)함수를 저장할 포인터 변수는 int (*fp)(int, int); 로 선언한다.
		>만약 포인터변수명에 괄호를 안붙이면 주소를 반환하는 함수선언이 된다. 
15.2.2 함수 포인터의 활용
	- 함수 포인터는 함수의 형태만 같으면 (자료형, 매개변수의 갯수와 형태) 모든 함수에서 사용할 수 있다.
		> 이러한 특징을 이용하여 형태가 같은 다양한 기능의 함수를 선택적으로 호출할 때 사용한다.
			ex) int sum(int a, int b) / int mul(int a, int b) / int max(int a, int b)함수가 있다고 가정하자.
			    세 함수모두 int를 반환하고 매개변수의 모양이 같으므로 int (*fp)(int, int)함수에 저장하고 사용할 수 있다.
				따라서, 상황에 맞게 fp를 사용하여 함수를 이용할 수 있다.(심지어, 매개변수로도 넘길 수 있다)
			ex) 1. 2개의 정수를 키보드에 입력한다 / 2. 두 정수로 연산을 수행한다. / 3. 연산 결과를 화면에 출력한다. 이 과정중에 2번을 제외하고는 sum, mul, max모두 1,3번을 공유하므로 
			    1, 3이 담긴 함수 내에서 fp를 통해 연산만 수정하면 간단하게 구현할 수 있다.
	- 함수 포인터는 다음과 같은 상황에 사용한다.
		> 함수를 제작할 때 특정 부분의 기능이 아직 결정되지 않았따면 일단 함수 포인터를 사용하고 나중에 따로 함수를 만들어 구현할 때 사용한다. 
		> 프로그램이 여러 개의 파일로 분리되어 있는 경우 다른 파일에 있는 정적 함수를 호출한다.
15.2.3 void 포인터
	- void 포인터는 가리키는 자료형이 정해지지 않은 포인터이다.
		> 가리키는 자료형이 다른 주소를 저장하는 경우에 사용한다.
		> void *변수명 처럼 선언한다.
	- void 포인터는 모든 주소를 저장할 수 있다.
		> 하지만, 반대로 간접참조 연산이나 정수 연산이 불가능하다. 이는 몇 바이트를 할당하는 자료형인지 판단할 수 없기 때문이다.
	- void 포인터를 사용할 때는 원하는 형태로 변환하여 사용한다.
		> 형변환을 통해 변환한 후 사용한다.
			ex) void *vp / *(int *)vp '
			> *와 형변환 연산자는 우선순위가 같으므로 연산이 왼쪽에서 오른쪽으로 진행된다. *을 먼저 사용한다.
	- 대입 연산을 할 때 void 포인터를 형변환 없이 다른 포인터에 대입할 수 있으나 명시적으로 형변환하여 사용하는 것이 좋다. 





포인터에 대한 개인적인 정리 
	 
			  

*/ 
