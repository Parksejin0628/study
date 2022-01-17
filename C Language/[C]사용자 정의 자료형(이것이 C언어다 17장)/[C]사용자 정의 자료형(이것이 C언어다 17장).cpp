#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct pet
{
	char name[20];
	int age;
};

struct intro
{
	char name[20];			//이름 
	int age;				//나이 
	double height;			//키 
	char *introduce;		//소갯말 
	pet dog;				//애완동물의 정보 
};

struct change
{
	int num1;
	int num2;
}; 

struct bitField
{
	unsigned int bool1 : 2;
	unsigned int bool2 : 2;
	unsigned int : 0;			//해당 메모리 단위 블록에 나머지 비트를 모두 패딩비트로 만듦	
};

struct change changeValue(struct change c1);
void printName(struct intro *sl); 

int main(void)
{
	struct intro s1;
	struct intro s2;
	struct pet cat = {"kitty", 4};
	struct change c1;
	struct bitField bitF = {0, 1};
	struct intro *ps1;
	struct intro slist[2];
	
	
	printf("(1)\n");
	printf("나이 : ");
	scanf("%d", &s1.age);
	printf("키 : ");
	scanf("%lf", &s1.height); 
	printf("나이 : %d\n키 : %.1wlf\n", s1.age, s1.height);
	//struct를 통해 구조체를 선언하며 . 연산자를 통해 멤버에 접근한다. 
	printf("\n(2)\n"); 
	printf("이름 : ");
	scanf("%s", s1.name);
	printf("한줄 소갯말 : ");
	fgetc(stdin);
	s1.introduce = (char*)malloc(80*sizeof(char));
	gets(s1.introduce);
	printf("애완 동물의 이름 : ");
	scanf("%s", s1.dog.name);
	printf("애완 동물의 나이 : ");
	scanf("%d", &s1.dog.age);
	printf("이름 : %s\n", s1.name);
	printf("한줄 소갯말 : %s\n", s1.introduce);
	printf("애완 동물의 이름 : %s\n", s1.dog.name);
	printf("애완 동물의 나이 : %d\n", s1.dog.age);
	// 구조체 멤버로 배열, 포인터, 이미 선언된 다른 구조체도 사용할 수 있다. 
	printf("\n(3)\n");
	s2 = s1;
	printf("[s1 복사본]\n");
	printf("이름 : %s\n", s2.name);
	printf("나이 : %d\n", s2.age);
	printf("키 : %.1lf\n", s2.height);
	printf("애완 동물의 이름 / 나이 : %s / %d\n", s2.dog.name, s2.dog.age);
	printf("한줄소개 : %s\n", s2.introduce);
	// 구조체 멤버끼리 대입 연산을 하면 각 멤버에 맞춰 알아서 대입이 된다. 
	printf("\n(4)\n");
	printf("고양이 이름 : %s\n", cat.name);
	printf("%s 나이 : %d\n", cat.name, cat.age);
	// 구조체 변수 선언과 동시에 초기화가 가능하다. 
	printf("\n(5)\n");
	printf("순서를 바꿀 두 값 : ");
	scanf("%d %d", &c1.num1, &c1.num2);
	c1 = changeValue(c1);
	printf("순서를 바꾼 두 값 : %d %d\n", c1.num1, c1.num2);
	// 구조체 변수를 매개변수로 주고 구조체 변수를 반환받으면 포인터 없이 두 값을 바꾸는 함수를 만들 수 있다. 
	printf("\n(6)\n");
	printf("bitF값 : %u %u\n", bitF.bool1, bitF.bool2);
	printf("bitF의 크기 : %d\n", sizeof(bitF));
	//비트 필드 구조체를 통해 사용할 비트를 결정할 수 있다. 실제로 bitF는 int형을 3개나 사용했지만 4바이트만을 할당했다. 
	printf("\n(7)\n");
	ps1 = &s1;
	printf("포인터를 통해 구한 이름 : %s\n", (*ps1).name);
	printf("포인터를 사용하고 ->연산자를 사용해 구한 이름 : %s\n", ps1->name);
	// 구조체 포인터에 구조체의 주소를 입력하면 구조체 전체를 사용할 수 있다. 또한, ->연산자를 통해 매번 괄호를 치는 번거러움을 방지할 수 있다. 
	printf("\n(8)\n");
	strcpy(s2.name, "mawdae");
	s2.age = 2; 
	slist[0] = s1;
	slist[1] = s2;
	printf("첫 번째 배열 요소의 값 - 이름 : %s / 나이 : %d / 키 : %.1lf / 애완동물의 이름 : %s / 애완동물의 나이 : %d / 한줄소개 : %s\n", slist[0].name, slist[0].age, slist[0].height, slist[0].dog.name, slist[0].dog.age, slist[0].introduce);
	printf("두 번째 배열 요소의 값 - 이름 : %s / 나이 : %d / 키 : %.1lf / 애완동물의 이름 : %s / 애완동물의 나이 : %d / 한줄소개 : %s\n", slist[1].name, slist[1].age, slist[1].height, slist[1].dog.name, slist[1].dog.age, slist[1].introduce);	
	// 구조체 배열을 사용할 수 있으며 배열처럼 구조체에 접근하되 구조체처럼 멤버에 접근한다. 
	printf("\n(9)\n");
	printName(slist);
	// 구조체 배열의 이름을 매개변수로 보내는 함수  
	
	fgetc(stdin);
	free(s1.introduce);
	scanf("%d");
	return 0;
}

struct change changeValue(struct change c1)
{
	int temp;
	temp = c1.num1;
	c1.num1 = c1.num2;
	c1.num2 = temp;
	
	return c1;
}

void printName(struct intro *sl)
{
	printf("첫 번째 이름 : %s\n", sl[0].name);
	printf("두 번째 이름 : %s\n", (sl + 1)->name);	
	
	return;
} 

/*
[17장 사용자 정의 자료형]
<17.1 구조체>
17.1.1 구조체 선언과 멤버 사용
	- 구조체는 다양한 자료형을 하나로 묶을 수 있는 복합 자료형이다.
	- 구조체를 사용하기 위해서는 구조체의 형태를 컴파일러에게 미리 알려주는 형 선언을 해야 한다.
	- 형 선언은 struct 예약어를 사용하여 다음과 같이 선언한다. 
		> struct 구조체이름 { 구조체 멤버 }; 
		ex) struct student(구조체 이름) 
			{
				int num;(구조체 멤버) 
				double grade;(구조체 멤버) 
			}; 
	- 구조체는 보통 함수 밖에다가 선언한다.
		> 함수 안에다가 선언할 경우 해당 함수 안에서만 구조체를 사용할 수 있다.
	- 선언한 구조체는 struct 예약어와 구조체 이름을 함께 하나의 자료형처럼 취급하여 사용할 수 있다.
		ex) struct student s1; : s1이라는 이름을 가진 student자료형 변수 선언
	- 구조체 변수는 각 구조체 멤버들의 공간이 메모리에 연속으로 할당되기 때문에 변수의 크기가 각 멤버의 크기를 더한 값이 된다.
		ex) student구조체는 int, double자료형을 가진 멤버를 가지므로 12바이트를 할당한다.
		> 모든 시스템은 데이터를 빠르게 읽고 쓰기 위해 일정한 크기 단위로 메모리에 접근한다. \
		> 따라서, 구조체 멤버의 크기가 들쑥날쑥한 경우 멤버 사이에 패팅 바이트를 넣어 멤버들을 가지런히 정렬하는데 이를 바이트 얼라인먼트라고 한다.
		> 바이트 얼라인먼트는 크기가 가장 큰 멤버가 메모리를 할당하는 기준 단위가 된다.
		> 결국 student구조체는 int로 4바이트를 확보한 후 double의 공간을 확보하기 전 바이트 얼라인먼트로 4바이트의 패딩 바이트를 넣게 된다.
		> short는 2바이트, int는 4바이트로 끊어서 할당된다.
		> 이러한 특징을 생각하여 구조체 멤버의 순서를 조정하면 메모리를 아낄 수 있다. 
	- 구조체 변수에서 사용할 멤버에 접근할 때는 . 연산자를 사용한다.
		ex) s1.num = 2;
17.1.2 다양한 구조체 멤버
	- 구조체 멤버로 배열도 사용할 수 있다.
	- 구조체 멤버로 포인터도 사용할 수 있다.
		> 만약, 문자열 포인터를 사용할 경우 포인터에 동적할당으로 공간을 할당한 후 문자열을 저장해야 한다.
	- 구조체 멤버로 다른 구조체도 사용할 수 있다.
		> 단, 해당 구조체보다 먼저 선언된 구조체여야 한다. 
		> 구조체 멤버의 멤버에 접근할 때도 .을 사용한다.
			ex)intro.school.grade = 1;
17.1.3 구조체 변수의 초기화와 대입 연산
	- 구조체 변수도 선언과 동시에 초기화가 가능하다. 하지만, 여러 개의 멤버를 초기화 해야 하므로 배열처럼 중괄호로 묶고 각 멤버의 형태에 맞는 값으로 초기화한다.
		ex) struct student s1 = {22, 2.5};
	- 구조체 변수끼리 대입 연산을 사용할 경우 각 멤버들을 다른 구조체 변수에 복사한다.
		ex) s1 = s2연산의 경우 s1.num = s2.num; s1.grade=s2.grade와 같다.
	- 구조체 선언과 동시에 변수 선언과 초기화도 가능하다. (초기화를 안 할 경우 함수 밖에 있는 구조체는 모두 0으로 자동 초기화된다.)
		ex) struct student
			{
				int id;
				char name[20];
				double grade;
		} s1 = {315, "홍길동", 2.4}; 
17.1.4 구조체 변수를 함수 매개변수에 사용하기
	- 구조체 변수를 함수의 매개변수로 주거나 반환받을 수 있다.
	- 따라서, 구조체 변수를 이용하면 함수에서 여러 개의 값을 구조체로 묶어 동시에 반환할 수 있다.
	- 구조체 변수를 이용해 포인터 없이 두 변수의 값을 바꾸는 함수를 만들 수 있다. (실습5) 
17.1.5 비트 필드 구조체
	- 0과 1을 저장하는 int형 값이 10개 있는 구조체는 너무 많은 공간을 낭비하게 된다.
		> 이런 낭비를 피하기 위해 비트 필드 구조체를 활용할 수 있다.
		> 비트 필드 구조체는 멤버의 크기를 비트 단위로 설정할 수 있다.
	- 비트 필드 구조체는 멤버가 사용할 비트 수를 콜론 옆에 표시함으로써 선언한다.
		ex) struct number
			{
				unsigned int num1 : 2	(비트 필드 구조체) 
				int num2 : 4
			}
		> 자료형은 정수형만 사용하며 멤버가 가질 수 있는 최대 비트 수를 결정한다.
			ex) unsigned int형은 최대 32비트까지 저장할 수 있다.
				unsigned char은 최대 8비트까지 저장할 수 있다.
		> 자료형의 크기를 넘어서 할당하는 멤버는 새로운 단위 블록에 할당한다. 
			ex) 만약 unsigned int형에 35비트를 선언하면 새로운 단위 블록에 3비트를 할당하여 총 64비트 / 8바이트를 사용하게 된다. 
	- 비트 필드 구조체에 멤버의 이름을 생략하면 해당 비트는 사용하지 않는 패딩 비트가 된다.
		> 특히 이름이 없는 멤버의 비트 수가 0인 경우 해당 블록의 나머지 비트는 모두 패딩 비트가 된다. 
<17.2 구조체 활용, 공용체, 열거형>
17.2.1 구조체 포인터와 -> 연산자
	- 구조체 변수는 그 안에 여러 개의 변수를 가지고 있으나 그 자신은 단지 하나의 변수이다.
	- 따라서, 구조체 변수에 주소 연산자를 사용하면 특정 멤버가 아닌 구조체 변수 전체의 주소가 구해진다.
		> 구조체 포인터에 구조체 변수의 주소를 저장하면 구조체 변수 전체를 가리킨다.
	- 구조체 포인터에 *연산을 사용하면 기리키는 구조체 변수를 사용할 수 있다.
		ex) (*ps).kor 
		> 문제는 멤버에 접근하는 . 연산자가 * 연산자보다 우선순위가 높다는 점이다. 이는, 포인터를 괄호로 묶지 않으면 논리적 오류가 발생한다.
		> -> 연산자를 사용하면 괄호로 묶지 않고도 구조체 포인터가 가리키는 멤버에 접근할 수 있다.
			ex)ps->kor
17.2.2 구조체 배열
	- 구조체 그 자체는 하나의 변수로 취급되므로 배열을 선언할 수 있다.
	- 구조체 배열을 초기화하는 방법은 배열을 초기화하는 방법과 같다. 단, 배열의 요소가 구조체이므로 중괄호 쌍을 2개 사용한다. 
		ex) struct intro list[5] = { {...}, {...}, ... };
	- 구조체 배열의 배열 요소를 사용할 때도 첨자를 사용하되 멤버에 접근할 때는 . 연산자를 추가로 사용한다.
		ex)list[4].age = 4; 
17.2.3 구조체 배열을 처리하는 함수
	- 배열의 이름이 첫 번째 요소의 주소이므로 구조체 배열의 이름은 첫 번째 구조체 변수를 가리킨다.
	- 따라서, 구조체 배열의 이름을 인수로 하는 함수는 구조체 포인터를 매개변수로 선언한다. 
*/ 	
